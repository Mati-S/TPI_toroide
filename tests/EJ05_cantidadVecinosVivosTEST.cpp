#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(cantidadVecinosVivosTEST, seisVivos){
    toroide t = {
            {true, false, false, false},
            {false, false, true, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 6);
}

TEST(cantidadVecinosVivosTEST, fueraDeRango){
    toroide t2 = tPeriodico;

    EXPECT_EQ(cantidadVecinosVivos(t2, 7, -1), 0);
}

TEST(cantidadVecinosVivosTEST, enRangoTresVivos){
    toroide t = tPeriodico;

    EXPECT_EQ(cantidadVecinosVivos(t, 5, 2), 0);
}

TEST(cantidadVecinosVivosTEST, sinSobrevivientes){
    toroide t =tMuerto;
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 0);
}

TEST(cantidadVecinosVivosTEST, rodeadoDeVivos){
    toroide t =tVivo;
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 8);
}