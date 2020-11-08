#include "../ejercicios.h"
#include "gtest/gtest.h"
#include "../toroidesparaTest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

TEST(evolucionDePosicionTEST, toroidePorRevivir){
    toroide t2 = tPorRevivir;
    EXPECT_TRUE(evolucionDePosicion(t2, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, toroidePorMorir ){
    toroide t3 = tPorMorir;
    EXPECT_FALSE(evolucionDePosicion(t3, make_pair(2,2)));
}

TEST(evolucionDePosicionTEST, toroidePeriodico){
    toroide t4 = tPeriodico;
    EXPECT_FALSE(evolucionDePosicion(t4, make_pair(-1,11)));
}

TEST(evolucionDePosicionTEST, toroidePeriodicoEnRango){
    toroide t5 = tPeriodico;
    EXPECT_FALSE(evolucionDePosicion(t5, make_pair(3,1)));
}

TEST(evolucionDePosicionTEST, posicionInvalida){
    toroide t = tNoCoinciden2;
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(4,4)));
}

TEST(evolucionDePosicionTEST, aRevivir){
    toroide t = tPeriodico;
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,3)));
}
