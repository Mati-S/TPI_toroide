#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    if (t.size() >= 3 && t[0].size() >= 3 && esMatriz(t)) {
        resp = true;
    }
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = true;
    if (toroideValido(t)) {
        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < t[0].size(); j++) {
                resp = resp && !t[i][j];
            }
        }
    }
    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[0].size(); j++) {
            if (t[i][j]) {
                vivos.push_back(make_pair(i, j));
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
    float resp = 0;
    int vivas = posicionesVivas(t).size();
    if (vivas > 0) {
        resp = vivas / (t.size() * t[0].size());
    }
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    float resp = 0;
    bool enRango = f >= 0 && f < t.size() && c >= 0 && c < t[0].size();
    if (enRango){
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (t[mod(f + i, t.size())][mod(c + j, t.size())] && (i != 0 || j != 0)) {
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
    if (toroideValido(t) && enRango) {
        int vecinosVivos = cantidadVecinosVivos(t, x.first, x.second);
        if (t[x.first][x.second] && vecinosVivos >= 2 && vecinosVivos <= 3) {
            resp = true;
        }
        if (!t[x.first][x.second] && vecinosVivos == 3) {
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t) {
    toroide tEvo = t;
    if (toroideValido(t)) {
        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < t[0].size(); j++) {
                tEvo[i][j] = evolucionDePosicion(t, mp(i, j));
            }
        }
    }
    t = tEvo;
    return;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out;
    out = t;
    if (toroideValido(t) && K > 0) {
        while (K > 0) {
            evolucionToroide(out);
            K--;
        }
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    toroide tEvo = t;
    p = 0;
    while(!toroideMuerto(tEvo) && !resp){
        evolucionToroide(tEvo);
        p++;
        if(sonIguales(t, tEvo)){
            resp = true;
        }
    }if(toroideMuerto(tEvo)){
        p = 0;
    }
    return resp;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
    bool mismasDimenciones = t.size() == u.size() && t[0].size() == t[0].size();
    bool resp = false;
    toroide tEvo = t;
    bool seRepite = false;
    if(mismasDimenciones) {
        while (!seRepite && !resp){
            if (toroideMuerto(tEvo) && !sonIguales(tEvo, u)) {
                break;
            } else if (sonIguales(tEvo, u)) {
                resp = true;
            } else {
                evolucionToroide(tEvo);
                seRepite = sonIguales(t, tEvo);
            }
        }
    }
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector<toroide> ts) {
    int resp = -1;
    int ticksEnMorir = 0;
    for (int i = 0; i < ts.size(); i++){
        int inmortal;
        int muereEn = 0;
        bool hayPeriodico = esPeriodico(ts[i],inmortal);
        if(hayPeriodico){
            resp = -1;
            break;
        }if (!toroideMuerto(ts[i])) {
            while (!toroideMuerto(ts[i])) {
                evolucionToroide(ts[i]);
                muereEn++;
            }if(muereEn > ticksEnMorir){
                resp = i;
                ticksEnMorir = muereEn;
            }
        }if(toroideMuerto(ts[i]) && resp == -1){
            resp = i;
        }
     }
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    if (t.size() == u.size() && t[0].size() == u[0].size()) {
        vector<bool> fila;
        for (int i = 0; i < u.size(); i++) {
            for (int j = 0; j < u[0].size(); j++) {
                if (u[i][j] && t[i][j]) {
                    fila.push_back(true);
                } else {
                    fila.push_back(false);
                }
            }
            out.push_back(fila);
            fila.clear();
        }
    }
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u) {
    bool resp = false;
    toroide tTrasladado;
    tTrasladado = t;
    for(int i = 0; i <= t.size(); i++){
        tTrasladado = trasladoVertical(tTrasladado);
        if(sonIguales(tTrasladado, u)){
            resp = true;
            break;
        }for(int j = 0; j <= t[0].size(); j++) {
            tTrasladado = trasladoHorizontal(tTrasladado);
            if (sonIguales(tTrasladado, u)) {
                resp = true;
                break;
            }
        }
    }
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t) {
    int resp = -1;
    toroide tTrasladado = t;
    vector<posicion> posiciones;
    vector<int> superficies;
    if(toroideMuerto(t)){
        resp = 0;
    }else{
        for (int i = 0; i <= t.size(); i++) {
            tTrasladado = trasladoVertical(tTrasladado);
            posiciones = posicionesVivas(tTrasladado);
            superficies.push_back(menorSuperficie(posiciones));
            posiciones.clear();
            for (int j = 0; j <= t[0].size(); j++) {
                tTrasladado = trasladoHorizontal(tTrasladado);
                posiciones = posicionesVivas(tTrasladado);
                superficies.push_back(menorSuperficie(posiciones));
                posiciones.clear();
            }
        }
        resp = menor(superficies);
    }
    return resp;
}
