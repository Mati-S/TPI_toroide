#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res;
    res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, toroidePeriodico){
    toroide t2 = tPeriodico;
    int p2;
    bool res2;
    res2 = esPeriodico(t2, p2);
    EXPECT_TRUE(res2);
    EXPECT_EQ(p2, 2);
}

TEST(esPeriodicoTEST, muereEnK){
    toroide t3 = tMuereEnKMenos1;
    int p3;
    bool res3;
    res3 = esPeriodico(t3, p3);
    EXPECT_FALSE(res3);
    EXPECT_EQ(p3, 0);
}

TEST(esPeriodicoTEST, toroideMuerto){
    toroide t4 = tMuerto;
    int p4;
    bool res4;
    res4 = esPeriodico(t4, p4);
    EXPECT_FALSE(res4);
    EXPECT_EQ(p4, 0);
}

TEST(esPeriodicoTEST, toroideVivo){
    toroide t5 = tVivo;
    int p5;
    bool res5;
    res5 = esPeriodico(t5, p5);
    EXPECT_FALSE(res5);
    EXPECT_EQ(p5, 0);
}

TEST(esPeriodicoTEST, constante){
    toroide t = naveEspacial;
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
}

TEST(esPeriodicoTEST, elKDeEspadas){
    toroide t = jorgitoTriple;
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

TEST(esPeriodicoTEST, casoExtra){
    toroide t = {{false,false,false,true,true,false},{true,true,false,false,false,true},{true,true,false,true,true,false},{true,false,true,true,true,false},{true,true,true,true,true,true},{true,false,false,false,true,false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}