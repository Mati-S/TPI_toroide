//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int mod (int a, int b);

int filas(const rectangulo& t);
int columnas(rectangulo t);
bool esRectangulo(rectangulo r);

int filaToroide(int f, toroide t);
int columnaToroide(int c, toroide t);
bool estaEnRango(const toroide& t, int f, int c);
int vecinosVivos(const toroide& t, int f, int c);

toroide trasladarToroide(toroide t, int x, int y);
int superficieVivas(toroide t);

#endif //REUNIONESREMOTAS_AUXILIARES_H