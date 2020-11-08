#include "../ejercicios.h"
#include "gtest/gtest.h"
#include "../toroidesparaTest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, torMuerto){
    toroide t = tMuerto;
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 0);
}

TEST(menorSuperficieVivaTEST, torVivo){
    toroide t = tVivo;

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieVivaTEST, toroidePeriodico){
    toroide t = tPeriodico;

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}
TEST(menorSuperficieVivaTEST, tetris){
    toroide t = tetris;

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 12);
}