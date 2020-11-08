#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(toroideMuertoTEST, toroideDiagonalVivas){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    EXPECT_FALSE(toroideMuerto(t));
}

TEST(toroideMuertoTEST, toroideVivo){
    toroide t2 = tVivo;
    EXPECT_FALSE(toroideMuerto(t2));
}

TEST(toroideMuertoTEST, UltimoHombreEnPie){
    toroide t4 = tUnoVivo;
    EXPECT_FALSE(toroideMuerto(t4));
}

TEST(toroideMuertoTEST, torMuerto){
    toroide t3 = tMuerto;
    EXPECT_TRUE(toroideMuerto(t3));
}