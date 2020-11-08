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
    int ret = a % b;
    if(ret < 0){
        ret+=b;
    }
    return ret;
}

int filas(const rectangulo& t){
    return t.size();
}

int columnas(rectangulo t) {
    int f = 0;
    if (filas(t) > 0) {
        f = t[0].size();
    }
    return f;
}

bool esRectangulo(rectangulo r){
    bool iguales = true;
    if(filas(r)>0 && columnas(r) > 0){
        for(int i = 0; i<r.size(); i++){
            if(r[i].size() != r[0].size()){
                iguales=false;
            }
        }
    }
    return iguales;
}

int filaToroide(int f, toroide t){
    return mod(f, filas(t));
}

int columnaToroide(int c, toroide t){
    return mod(c, columnas(t));
}

bool estaEnRango(const toroide& t, int f, int c){
    bool esta = false;
    if((f < filas(t) && f >= 0) && (c < columnas(t) && c >= 0)){
        esta = true;
    }
    return esta;
}

int vecinosVivos(const toroide& t, int f, int c){
    int vivos = 0;
    if(estaEnRango(t, f, c)){
        for(int i = f-1; i<=f+1; i++){
            for(int j = c-1; j<= c+1; j++){
                if((i != f) || (j != c)){
                    int x = filaToroide(i, t);
                    int y = columnaToroide(j, t);
                    if(t[x][y]){
                        vivos++;
                    }
                }
            }
        }
    }
    return vivos;
}

toroide trasladarToroide(toroide t, int x, int y){
    toroide tTraslado(t.size(), vector<bool>(t[0].size(), false));
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < t[i].size(); j++){
            if(t[i][j]){
                tTraslado[mod(i+x, t.size())][mod(j+y, t[i].size())] = t[i][j];
            }
        }
    }
    return tTraslado;
}

int superficieVivas(toroide t){
    int lejosX = 0;
    int lejosY = 0;
    
    int cercaX = t.size();
    int cercaY = t[0].size();

    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            if(t[i][j]){
                if(cercaX > i){
                    cercaX = i;
                }
                if(cercaY > j){
                    cercaY = j;
                }
                if(i > lejosX){
                    lejosX = i;
                }
                if(j > lejosY){
                    lejosY = j;
                }
            }
        }
    }
    int superficieX = lejosX - cercaX + 1;
    int superficieY = lejosY - cercaY + 1;
    return (superficieX*superficieY);
}
