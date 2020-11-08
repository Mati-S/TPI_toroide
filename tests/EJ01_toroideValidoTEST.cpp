#include "../ejercicios.h"
#include "gtest/gtest.h"
#include "../toroidesparaTest.h"

using namespace std;

TEST(toroideValidoTEST, toroideVacio){
    toroide t = { vector<bool> () };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(toroideValido(t));
}

TEST(toroideValidoTEST, toroide2Filas){
    toroide t2 = tDosFilas;
    EXPECT_FALSE(toroideValido(t2));
}

TEST(toroideValidoTEST, torVacio){
    toroide t3 = {};
    EXPECT_FALSE(toroideValido(t3));
}

TEST(toroideValidoTEST, toroideFilaIncompleta){
    toroide t3 = tFilaMedia;
    EXPECT_FALSE(toroideValido(t3));
}   


TEST(toroideValidoTEST, toroide2Comlumnas){
    toroide t4 = tDosColumnas;
    EXPECT_FALSE(toroideValido(t4));
}

TEST(toroideValidoTEST, toroideNoRectangular) {
    toroide t = toroideNoRectangular;
    EXPECT_FALSE(toroideValido(t));
}