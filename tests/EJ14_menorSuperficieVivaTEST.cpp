#include "../ejercicios.h"
#include "gtest/gtest.h"

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

TEST(menorSuperficieVivaTEST, casoPrueba){
    toroide t = {
            {false, false, false, false, false, false, false, false},
            {false, true, true, true, true, true, true, false},
            {false, false, false, false, false, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, true, false, false, false},
            {false, false, false, false, false, false, false, false},
    };  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 24);
}