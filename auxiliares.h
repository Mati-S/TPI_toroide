//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

int mod(int a, int b);
int filas(const rectangulo& t);
int columnas(rectangulo t);
bool esRectangulo(rectangulo r);
bool esToroide(const toroide& t);
bool sinRepetidos(vector<posicion> s);
float cantidadVivas(toroide t);
float superficieTotal(const toroide& t);
int vecinosVivos(const toroide& t, int f, int c);
toroide trasladarToroide(toroide t, int x, int y);
int superficieVivas(toroide t);
bool debeVivir(toroide t, int x, int y);

#endif //REUNIONESREMOTAS_AUXILIARES_H
