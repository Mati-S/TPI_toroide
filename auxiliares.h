//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int mod (int a, int b);
bool esMatriz(vector<vector<bool>> const &t);
bool sonIguales(toroide t, toroide tEvo);
toroide trasladoVertical(toroide t);
toroide trasladoHorizontal(toroide t);
int menorSuperficie(vector<posicion> pos);
int menor (vector<int> superficies);

#endif //REUNIONESREMOTAS_AUXILIARES_H