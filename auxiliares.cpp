#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

int mod (int a, int b){
    if(b < 0) //you can check for b == 0 separately and do what you want
        return -mod(-a, -b);
    int ret = a % b;
    if(ret < 0)
        ret+=b;
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

bool esToroide(const toroide& t){
    bool resp = false;
    if(filas(t) >= 3 && columnas(t) >= 3 && esRectangulo(t)){
        resp = true;
    }
    return resp;
}

float cantidadVivas(toroide t){
    float vivas = 0 ;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[0].size(); j++){
            if(t[i][j]){
                vivas++;
            }
        }
    }
    return vivas;
}

float superficieTotal(const toroide& t){
    return (filas(t) * columnas(t));
}

int filaToroide(int f, toroide t){
    return mod(f, filas(t));
}

int columnaToroide(int c, toroide t){
    return mod(c, columnas(t));
}

int vecinosVivos(const toroide& t, int f, int c){
    int vivos = 0;

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

    return vivos;
}

bool debeVivir(toroide t, int x, int y){
    bool resp = false;
    int cantVivos = vecinosVivos(t, x, y);
    if(t[x][y] && cantVivos >= 2 && cantVivos <= 3){
        resp = true;
    }else if(!t[x][y] && cantVivos == 3){
        resp = true;
    }
    return resp;
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

//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}
