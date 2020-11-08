#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(posicionesVivasTEST, toroideDiagonalVivas){
    toroide t = { 
	{true, false, false},
	{false, true, false},
	{false, false, true},
	{true, false, false},
	{false, true, false},
	{false, false, true}};

    vector<posicion> vivas = {mp(0,0), mp(1,1), mp(2,2), mp(3, 0), mp(4, 1), mp(5, 2)};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, toroideMuerto){
    toroide t2 = tMuerto;

    vector<posicion> vivas2 = {};
    vector<posicion> res2 = posicionesVivas(t2);
    EXPECT_EQ(ordenar(vivas2), ordenar(res2));
}

TEST(posicionesVivasTEST, toroideVivo){
    toroide t3 = tVivo;

    vector<posicion> vivas3 = {mp(0,0), mp(0,1), mp(0,2), mp(1,0), mp(1,1), mp(1,2), mp(2,0), mp(2,1), mp(2,2)};
    vector<posicion> res3 = posicionesVivas(t3);
    EXPECT_EQ(ordenar(vivas3), ordenar(res3));
}

TEST(posicionesVivasTEST, toroideCincoDado){
    toroide t4 = tDadoCinco;

    vector<posicion> vivas4 = {mp(0,0), mp(0,2), mp(1,1), mp(2, 0), mp(2, 2)};
    vector<posicion> res4 = posicionesVivas(t4);
    EXPECT_EQ(ordenar(vivas4), ordenar(res4));
}
