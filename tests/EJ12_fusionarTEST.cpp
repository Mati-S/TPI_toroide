#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(fusionarTEST, sinInterseccion){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, true, true},
                  {true, false, true},
                  {true, true, false}};

    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, todosCoinciden){
    toroide t1 = tTodosCoinciden; 
    toroide t2 = tTodosCoinciden;

    toroide tout = tTodosCoinciden;

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, ningunoCoincide){
    toroide t1 = tNoCoinciden1; 
    toroide t2 = tNoCoinciden2;

    toroide tout = tMuerto;

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, todosVivos){
    toroide t1 = tVivo; 
    toroide t2 = tVivo;

    toroide tout = tVivo;

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}