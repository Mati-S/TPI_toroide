#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMuertoYVivo){
    toroide t = tVivo;

    toroide evo_t = tMuerto;

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroidePorRevivirYVivo){
    toroide t = tPorRevivir;
    toroide evo_t = tVivo;
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, luzDeTrafico){
    toroide t = semaforo;
    toroide evo_t = semaforoEvolucion;
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}
