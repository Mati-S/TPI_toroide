#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int, int> mp(int a, int b) {
    return make_pair(a, b);
}

//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

int mod (int a, int b){
    if(b < 0){
        return -mod(-a, -b);
    }int ret = a % b;
    if(ret < 0){
        ret+=b;
    }
    return ret;
}

bool esMatriz(vector<vector<bool>> const &t) {
    bool resp = true;
    for (int i = 0; i < t.size(); i++) {
        if(t[i].size() != t[0].size()){
            resp = false;
        }
    }
    return resp;
}

bool sonIguales(toroide t, toroide tEvo) {
    bool resp = true;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[0].size() && resp; j++) {
            if(t[i][j] != tEvo[i][j]){
                resp = false;
            }
        }
    }
    return resp;
}

toroide trasladoVertical(toroide t) {
    toroide torTransladado;
    for(int i = 1; i < t.size(); i++){
        torTransladado.push_back(t[i]);
    }
    torTransladado.push_back(t[0]);
    return torTransladado;
}

toroide trasladoHorizontal(toroide t) {
    toroide torTransladado;
    for(int i = 0; i < t.size(); i++){
        vector<bool> fila;
        fila.push_back(t[i][t.size() -1]);
        for(int j = 0; j < t[0].size() - 1; j++){
            fila.push_back(t[i][j]);
        }
        torTransladado.push_back(fila);
        fila.clear();
    }
    return torTransladado;
}

int menorSuperficie(vector<posicion> p){
    int largo = 0;
    int alto = 0;
    while (alto == 0){
        int posMin = 0;
        int posMax = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[posMin].first > p[i].first){
                posMin = i;
            }if(p[posMax].first < p[i].first){
                posMax = i;
            }
        }
        alto = p[posMax].first - p[posMin].first + 1;
    }
    while (largo == 0){
        int posMin2 = 0;
        int posMax2 = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[posMin2].second > p[i].second){
                posMin2 = i;
            }if(p[posMax2].second < p[i].second){
                posMax2 = i;
            }
        }
        largo = p[posMax2].second - p[posMin2].second + 1;
    }
    return largo * alto;
}

int menor (vector<int> superficies){
    int supMenor = superficies[0];
    for (int i = 1; i < superficies.size(); i++){
        if(superficies[i] < supMenor){
            supMenor = superficies[i];
        }
    }
    return supMenor;
}