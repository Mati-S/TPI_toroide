#include "../ejercicios.h"
#include "gtest/gtest.h"
#include "../toroidesparaTest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, torVivo){
    toroide t2 = tVivo;
    EXPECT_NEAR(densidadPoblacion(t2), 1.0, 0.01);
}


TEST(densidadPoblacionTEST, torMuerto){
    toroide t3 = tMuerto;
    EXPECT_NEAR(densidadPoblacion(t3), 0.0, 0.01);
}


TEST(densidadPoblacionTEST, toroideUltimoSuperviviente){
    toroide t4 = tUnoVivo;
    EXPECT_NEAR(densidadPoblacion(t4), 0.1, 0.1);
}
