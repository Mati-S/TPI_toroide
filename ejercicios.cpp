#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    if(t.size() && t[0].size() > 0 && esMatriz(t)){
        resp = true;

    }
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = false;
    if(toroideValido(t)){
        for (int i = 0; i < t.size(); i++){
            for (int j = 0; j < t[0].size(); j++){
                resp = resp && not(t[i][j]);
            }
        }
    }
    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
    if(toroideValido(t)) {
        for (int i = 0; i < t.size(); i++){
            for (int j = 0; j < t[0].size(); j++){
                if(t[i][j]){
                    vivos.push_back(make_pair(i,j));
                }
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
	float resp = -1;
	int vivas = cantVivas(t);
    if(toroideValido(t) && vivas > 0){
        resp = vivas / (t.size() * t[0].size());
    }
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    float resp = 0;
    bool enRango = (f >= 0 && f < t.size()) && (c >= 0 && c < t[0].size());
    if(toroideValido(t) && enRango){
        for (int i = f-1 % t.size(); i < f+1 % t.size(); i++){
            for (int j = c-1 % t[i].size(); j < c + 1 % t[0].size(); j++){
                if(t[i][j] && (i != f || j != c)){
                    resp++;
                }
            }
        }
    }
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = false;
    bool enRango = (x.first >= 0 && x.first < t.size()) && (x.second >= 0 && x.second < t[0].size());
    if(toroideValido(t) && enRango){
        int vecinosVivos = cantidadVecinosVivos(t, x.first, x.second);
        if (t[x.first][x.second] && vecinosVivos >= 2 && vecinosVivos <= 3){
            resp = true;
        }if (not(t[x.first][x.second]) && vecinosVivos == 3) {
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    if(toroideValido(t)){
        for (int i = 0; i < t.size(); i++){
            for (int j = 0; j < t[0].size(); j++){
                evolucionDePosicion(t, make_pair(i,j));
            }
        }
    }
    return;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out;
    out = t;
    if(toroideValido(t) && K > 0){
        while (K > 0){
            evolucionToroide(out);
            K--;
        }
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    if(toroideValido(t)){
        toroide tEvo = evolucionMultiple(t, p);
        resp = mismoPatron(t, tEvo);
    }
    return resp;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false; 
    // Implementacion
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
    for (int i = 0; i < ts.size(); i++){
        int muereEn = 0;
        while(not(toroideMuerto(ts[i]))){
            evolucionToroide(ts[i]);
            muereEn++;
        }
        if(muereEn > resp){
            resp = muereEn;
        }
    }
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    if(t.size() == u.size() && t[0].size() == u[0].size()){
        out = t;
        for (int i = 0; i < u.size(); i++){
            for (int j = 0; j < u[0].size(); j++){
                if(not(out[i][j]) && u[i][j]){
                    out[i][j] = true;
                }
            }
        }
    }
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	// Implementacion
	return resp;
}
