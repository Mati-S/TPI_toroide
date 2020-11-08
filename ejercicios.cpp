#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    resp = esToroide(t);
    return resp;
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
	double resp = -1;
    double c = cantidadVivas(t);
    double sT = superficieTotal(t);
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
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    int i = 1;
    while(i<=K){
        evolucionToroide(out);
        i++;
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    toroide tEvo = t;
    toroide tConstante = t;

    int i = 1;
    evolucionToroide(tEvo);

    while(tEvo != t && !toroideMuerto(tEvo) && tEvo != tConstante){

        evolucionToroide(tEvo);
        evolucionToroide(tConstante);
        i++;

    }

    if(t == tEvo && !toroideMuerto(tEvo)){
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
    toroide tEvoConstante = t;
    toroide uEvoConstante = u;

    evolucionToroide(tEvo);
    evolucionToroide(uEvo);

    while(tEvo != t && tEvo != tEvoConstante && tEvo != u && !toroideMuerto(tEvo)){
        evolucionToroide(tEvo);
        evolucionToroide(tEvoConstante);
    }

    if(tEvo == u){
        resp = true;
    }

    while(uEvo != u && uEvo != t && uEvo != uEvoConstante && !toroideMuerto(uEvo) && !resp){
        evolucionToroide(uEvo);
        evolucionToroide(uEvoConstante);
    }

    if(uEvo == t){
        resp = true;
    }
    
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
    int mayorTicks = 0;
    int muerteTicks = 0;
    bool esInmortal = false;
    
    for(int i = 0; i<ts.size() && !esInmortal;i++){
        toroide t = ts[i];
        toroide tPrev = ts[i];

        if(!toroideMuerto(t)){
            int dead = 0;
            bool estaMuerto = toroideMuerto(t);
            bool periodico = esPeriodico(t, dead);

            if(!periodico){
                evolucionToroide(t);
                muerteTicks = 1;

                while(!estaMuerto && t != tPrev){
                    evolucionToroide(t);
                    evolucionToroide(tPrev);
                    if(toroideMuerto(t)){
                        estaMuerto = true;
                    }
                    muerteTicks++;
                }

                bool prevMuerto = toroideMuerto(tPrev);

                if(t == tPrev && !prevMuerto){
                    resp = i;
                    esInmortal = true;
                }
                if(muerteTicks > mayorTicks){
                    mayorTicks = muerteTicks;
                    resp = i;
                }
                muerteTicks = 0;

            } else {
                resp = i;
                esInmortal = true;
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
	bool resp = false;
    toroide tTraslado = t;
    int x = 0;
    while(x < t.size() && !resp){
        int y = 0;
        while(y < t[0].size() && !resp){
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
    int resp = 0;
    vector<toroide> toroideLista;
    bool estaMuerto = toroideMuerto(t);
    if(!estaMuerto){
        for(int i = 0; i<t.size(); i++){
            for(int j = 0; j<t[i].size();j++){
                toroideLista.push_back(trasladarToroide(t, i, j));
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
    }
    return resp;
}
