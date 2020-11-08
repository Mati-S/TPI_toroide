#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, tetris){
    toroide t1 = tetris;
    toroide t2 = tetrisTraslado;
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, unPunto){
    toroide t1 = tTransladarUltimo1;
    toroide t2 = tTransladarUltimo2;
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, noCoinciden){
    toroide t1 = tTransladarNoCoinciden1;
    toroide t2 = tTransladarNoCoinciden2;
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, transladarDos){
    toroide t1 = tTransladarDos1; 
    toroide t2 = tTransladarDos2; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}