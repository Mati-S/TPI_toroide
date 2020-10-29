#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

bool esMatriz(vector<vector<bool>> const &t){
    bool resp = (t.size() == t[0].size());
    return resp;
}

int cantVivas(vector<vector<bool>> const &t){
    int vivas = 0;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if(t[i][j]){
                vivas++;
            }
        }
    }
    return vivas;
}

bool mismoPatron(vector<vector<bool>> const &t, vector<vector<bool>> const &tEvo) {
    bool resp = true;
    vector<posicion> vivos;
    vector<posicion> vivosEvo;
    if(vivos.size() == vivosEvo.size()){
        for(int i = 0; i < vivos.size() -1 && resp; i++) {
            posicion diferenciaPosiciones = make_pair(vivos[i].first - vivos[i + 1].first,
                                                      vivos[i].second - vivos[i + 1].second);
            posicion diferenciaPosicionesEvo = make_pair(vivosEvo[i].first - vivosEvo[i + 1].first,
                                                         vivosEvo[i].second - vivosEvo[i + 1].second);
            resp = mirarPosiciones(diferenciaPosiciones, diferenciaPosicionesEvo);
        }
    }
    return resp;
}

bool mirarPosiciones(posicion pos1, posicion pos2){
    bool resp;
    resp = pos1.first == pos2.first;
    resp = resp && pos1.first == pos2.first;
    return resp;
}

int seMuereEnK (toroide const &t){
    bool muerto = false;
    if (not(muerto)){

    }
}