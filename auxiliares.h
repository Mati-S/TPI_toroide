//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
bool esMatriz(vector<vector<bool>> const &t);
int cantVivas(vector<vector<bool>> const &t);
bool mismoPatron(vector<vector<bool>> const &t, vector<vector<bool>> const &tEvo);
bool mirarPosiciones(posicion pos1, posicion pos2);
int seMuereEnK (toroide const &t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
