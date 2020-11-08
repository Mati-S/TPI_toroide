#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, seleccionConPeriodico){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, -1);
}

TEST(seleccionNaturalTEST, bosqueDeToroides){
    toroide t1 = tVivo; 

    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t1);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, seleccionNormal){
    toroide t1 = tNoCoinciden2;
    toroide t2 = tMuerto;
    toroide t3 = tVivo;
    toroide t4 = tDadoCinco;
    toroide t5 = tMuereEnKMenos1;

    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t4);
    ts.push_back(t5);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 4);
}


TEST(seleccionNaturalTEST, prueba_multiple){
    vector<toroide> ts = listaT1;
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 4);
}
