#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"
#include "iostream"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    return esToroide(t);
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = true;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            if(t[i][j]){
                resp = false;
            }
        }
    }
    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[0].size(); j++){
            if(t[i][j]){
                vivos.push_back(mp(i,j));
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
	float resp = 0;
	float c = cantidadVivas(t);
	float sT = superficieTotal(t);
	resp = c/sT;
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    int resp = vecinosVivos(t, f, c);
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = debeVivir(t, x.first, x.second);
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    toroide tEvo = t;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            t[i][j] = evolucionDePosicion(tEvo, mp(i,j));
        }
    }
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int k) {
    toroide out = t;
    int i = 1;
    while(i<=k){
        evolucionToroide(out);
        i++;
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    toroide tEvo = t;
    int i = 1;
    evolucionToroide(tEvo);
    while(tEvo != t && !toroideMuerto(tEvo)){
        evolucionToroide(tEvo);
        i++;
    }
    if(!toroideMuerto(tEvo)){
        resp = true;
    }else{
        i = 0;
    }
    p = i;
    return resp;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false; 
    toroide tEvo = t;
    toroide uEvo = u;
    evolucionToroide(tEvo);
    evolucionToroide(uEvo);
    while(tEvo != t || uEvo != u){
        evolucionToroide(tEvo);
        evolucionToroide(uEvo);
    }
    if(tEvo == t || uEvo == u){
        resp = true;
    }
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector<toroide> ts) {
    int resp = -1;
    int muertIn = 0;
    int muertFin = 0;
    bool hayUnPeriodico = false;
	for(int i = 0; i<ts.size() && !hayUnPeriodico;i++){
	    toroide t = ts[i];
        if(!toroideMuerto(t)){
            int dead;
            bool estaMuerto = toroideMuerto(t);
            bool esPeriod = esPeriodico(t, dead);
            if(!esPeriod){
                while(!estaMuerto){
                    evolucionToroide(t);
                    if(toroideMuerto(t)){
                        estaMuerto = true;
                    }
                    muertFin++;
                }
                if(muertFin > muertIn){
                    muertIn = muertFin;
                    resp = i;
                    muertFin = 0;
                }
            }else{
                resp = i;
                hayUnPeriodico = true;
            }
        }
	}
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out(t.size(), vector<bool>(t[0].size(), false));
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            if(t[i][j] && u[i][j]){
                out[i][j] = true;
            }
        }
    }
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
    toroide tTraslado = t;
	bool resp = false;
    int x = 0;
    while(x < t.size()){
        int y = 0;
        while(y < t[0].size()){
            if(!resp){
                tTraslado = trasladarToroide(t, x, y);
                if(tTraslado == u){
                    resp = true;
                }
            }
            y++;
        }
        x++;
    }
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	const toroide& tTraslado = t;
	vector<toroide> toroideLista;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size();j++){
            toroideLista.push_back(trasladarToroide(tTraslado, i, j));
        }
    }
    int f= filas(t);
    int c = columnas(t);
    int superficieMasChica = f * c;

    for(int i = 0; i<toroideLista.size(); i++){
        int superficie = superficieVivas(toroideLista[i]);
        if(superficie < superficieMasChica){
            superficieMasChica = superficie;
        }
    }

    resp = superficieMasChica;
    cout << resp << endl;
	return resp;
}
