#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../toroidesparaTest.h"

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
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
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, unToroideGrande){
    toroide t = jorgitoTriple;

    toroide evo_t = jorgitoTripleEvolucionado;

    toroide res = evolucionMultiple(t, 20);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideEspada){
    toroide t = unaEspada;

    toroide evo_t = unaEspadaEvolucionado;

    toroide res = evolucionMultiple(t, 3);
    EXPECT_EQ(res, evo_t);
}
