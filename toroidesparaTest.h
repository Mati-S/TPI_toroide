#ifndef REUNIONESREMOTAS_TOROIDESPARATESTS_H
#define REUNIONESREMOTAS_TOROIDESPARATESTS_H

#include "definiciones.h"


const toroide tFilaMedia = {     
        {true, false, false},
        {false, true},
        {false, false, true}
    };

const toroide tDosFilas = {     
        {true, false},
        {true, false},
        {false, false}
    };

const toroide tDosColumnas = {   
        {true, false, false},
        {false, true, false}
    };

const toroide tVacio = {};

const toroide toroideNoRectangular = {
        {true, false, false, true},
        {false, true},
        {false, false, true}};

const toroide tVivo = { 
        {true, true, true},
        {true, true, true},
        {true, true, true}
    };

const toroide tMuerto = { 
        {false, false, false},
        {false, false, false},
        {false, false, false}
    };

const toroide tUnoVivo = { 
        {false, false, false},
        {false, false, false},
        {false, false, true}
    };

const toroide tDadoCinco = { 
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };

//1,1//
const toroide tPorRevivir  = { 
        {true, false, true},
        {false, false, false},
        {false, true, false}
    };

//2,2//
const toroide tPorMorir  = { 
        {false, false, false},
        {false, true, false},
        {false, false, true}
    };

//Usar dos veces el mismo//
const toroide tTodosCoinciden  = { 
        {true, false, false},
        {false, false, true},
        {true, false, true}
    };

//Parte1//
const toroide tNoCoinciden1  = { 
        {false, true, false},
        {false, true, true},
        {false, true, false}
    };

//Parte2//
const toroide tNoCoinciden2  = { 
        {true, false, false},
        {false, false, false},
        {true, false, true}
    };

//Parte1//
const toroide tTransladarUltimo1  = { 
        {false, false, false},
        {false, false, false},
        {false, false, true}
    };

//Parte2//
const toroide tTransladarUltimo2  = { 
        {true, false, false},
        {false, false, false},
        {false, false, false}
    };

//Parte1//
const toroide tTransladarDos1  = { 
        {false, false, false},
        {false, false, false},
        {false, false, true}
    };

//Parte2//
const toroide tTransladarDos2  = {
        {true, false, false},
        {false, false, false},
        {false, false, false}
    };

//Parte1//
const toroide tTransladarNoCoinciden1  = { 
        {true, false, false},
        {false, true, false},
        {false, false, true}
    };

//Parte2//
const toroide tTransladarNoCoinciden2  = { 
        {true, true, true},
        {false, false, false},
        {false, false, false}
    };

const toroide jorgitoTriple = {
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,true,false,false,true,true,false,false,true,true,false,false,false,false,false,false},
        {false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false},
        {false,false,false,false,false,false,true,true,false,false,true,true,false,false,true,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,true,true,true,true,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}
};

// Evolucion k = 20
const toroide jorgitoTripleEvolucionado = {
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,true,false,true,false,false,false,false,true,false,false,false,false,false,false,false,false},
        {false,true,false,true,false,false,false,false,true,false,true,false,false,false,false,false,false,false},
        {false,false,true,false,false,false,false,false,true,false,true,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false},
        {false,false,false,false,true,true,false,false,false,false,false,true,false,false,true,false,false,false},
        {false,false,false,true,false,false,true,false,false,false,false,false,true,true,false,false,false,false},
        {false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,true,false,true,false,false,false,false,false,true,false,false},
        {false,false,false,false,false,false,false,true,false,true,false,false,false,false,true,false,true,false},
        {false,false,false,false,false,false,false,false,true,false,false,false,false,true,false,true,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,true,false,true,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}
};

const toroide unaEspada = {
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, true, true, false, false, true, false, false},
        {false, false, true, false, true, true, false, false, false},
        {false, false, false, true, false, true, false, false, false},
        {false, false, false, true, true, false, true, false, false},
        {false, false, true, false, false, true, true, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false}
};

// Evolucion k = 3
const toroide unaEspadaEvolucionado = {
        {false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	true,	false,	false,	false,	false,	true,	false,	false},
        {false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,	false,	false,	true,	false,	true,	false,	false,	false},
        {false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,	false,	true,	false,	false,	false,	false,	true,	false},
        {false,	false,	false,	false,	false,	false,	true,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false}
};


//K = 5//
const toroide tMuereEnKMenos1  = { 
        {false, false, false,false, false, false, false},
        {false, true, true,false, false, false, false},
        {false, false, false,true, false, false, false},
        {false, false, false,false, false, true, false},
        {false, false, false,true, true, false, false}
    };

const toroide tMuertoK  = {
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false}
    };
//K = ??//

const toroide tPeriodico  = { 
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false},
        {false, false, true,true, true, false, false},
        {false, false, false,false, false, false, false},
        {false, false, false,false, false, false, false}
};

const toroide semaforo = {
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true, true, true, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, true, false, false, false, false, false, true, false, false},
        {false, false, true, false, false, false, false, false, true, false, false},
        {false, false, true, false, false, false, false, false, true, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true, true, true, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false}
};

const toroide semaforoEvolucion = {
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, true, true, true, false, false, false, true, true, true, false},
        {false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, true, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false},
};

// Toroide constante
const toroide naveEspacial = {
        {false, false, false, false, false, false},
        {false, false, true, true, false, false},
        {false, true, false, false, true, false},
        {false, true, false, true, false, false},
        {false, false, true, false, false, false},
        {false, false, false, false, false, false},
};

// El toroide 6 es la respuesta por ser un toroide constante
const vector<toroide> listaT1 = {
    {{false,false,true,true,false,false},{false,false,true,false,false,true},{false,true,false,true,true,true},{true,false,true,true,false,false}},
    {{false,true,true,false,true,false,true},{true,false,false,false,true,false,true},{false,false,false,false,true,true,true},{true,false,true,true,true,false,false},{false,false,false,true,false,false,true},{true,true,false,true,true,true,false}},
    {{false,false,true},{true,false,false},{true,true,true},{false,false,false}},
    {{true,false,false,false,true}, {true,false,false,false,false}, {false,true,false,true,false}, {true,false,false,true,false}},
    {{true,true,false,false,true,true,false,true},{true,true,true,false,false,true,false,true},{false,true,false,false,true,true,true,false},{true,false,false,true,false,false,false,true},{false,false,true,false,true,false,true,false}},
    {{true,true,false},{true,false,false},{false,true,false},{false,true,false},{true,true,true}},
    {{false,false,false},{true,true,false},{true,true,true},{false,false,true}},
    {{false,false,false,true,true,false,false},{true,true,true,true,false,false,true},{false,false,true,false,true,false,true},{false,false,false,true,true,false,false},{false,false,true,false,false,true,true},{false,true,false,false,true,true,true}},
    {{false,true,true,false,true},{false,true,false,true,false},{true,false,true,true,false},{false,false,false,true,true}},
    {{true,true,false,false,true,false,true,false},{true,true,false,true,true,false,true,true},{false,false,false,false,true,true,false,true},{false,true,true,true,true,true,true,true},{true,false,true,false,false,false,true,false}},
    {{false,false,false,true,false,true},{false,false,true,false,true,true},{true,true,true,false,true,true},{true,false,true,false,true,true}},
    {{true,true,false},{false,false,true},{true,false,true},{true,false,true},{false,false,true},{false,true,false}},
    {{false,true,true,true,false},{false,true,true,true,true},{true,true,true,false,false}}
};

const toroide tetris = {{false,true,true,false},{false,false,false,false},{true,true,true,false},{false,true,false,true}};
const toroide tetrisTraslado = {{false,false,false,false},{true,true,false,true},{true,false,true,false},{true,true,false,false}};

const toroide rubikA = {{true, true, false, true, true},{true, false, true, false, true},{false, true, true, true, false},{true, false, true, false, true},{true, true, false, true, true}};

const toroide rubikB = {{true, true, true, true, true},{true, false, false, false, true},{true, false, false, false, true},{true, false, false, false, true},{true, true, true, true, true}};

const toroide fusionA = {{true,true,true,false,false},{false,true,false,false,true},{true,true,true,true,true},{false,false,false,true,true},{true,true,false,true,true}};
const toroide fusionB = {{true,false,true,true,true},{true,false,false,true,false},{false,true,true,false,false},{false,false,true,true,true},{false,true,true,true,false}};
const toroide fusionAB = {{true,false,true,false,false},{false,false,false,false,false},{false,true,true,false,false},{false,false,false,true,true},{false,true,false,true,false}};

const toroide fusionC = {{true,false,false,true},{true,false,true,false},{false,true,true,true},{false,false,true,true}};
const toroide fusionD = {{false,false,true,true},{false,false,true,true},{true,false,false,false},{true,true,false,true}};
const toroide fusionCD = {{false,false,false,true},{false,false,true,false},{false,false,false,false},{false,false,false,true}};

const toroide fusionE = {{true,true,true,true,false,true,true,true},{true,false,true,true,false,true,false,true},{true,false,true,false,true,true,false,true},{false,false,false,true,false,false,true,false},{false,true,true,false,true,true,false,false},{true,false,false,true,false,true,true,false},{true,true,true,true,true,true,true,false},{false,true,false,true,true,false,true,false}};
const toroide fusionF = {{false,false,false,false,true,true,false,false},{false,true,true,true,true,true,true,false},{false,true,false,false,false,true,false,false},{false,false,false,true,true,false,true,false},{false,true,false,false,true,true,false,true},{true,true,false,true,false,true,false,false},{true,false,false,true,false,false,false,true},{false,true,true,false,false,false,false,true}};
const toroide fusionEF = {{false,false,false,false,false,true,false,false},{false,false,true,true,false,true,false,false},{false,false,false,false,false,true,false,false},{false,false,false,true,false,false,true,false},{false,true,false,false,true,true,false,false},{true,false,false,true,false,true,false,false},{true,false,false,true,false,false,false,false},{false,true,false,false,false,false,false,false}};

// Estos toroides son no periodicos infinitos y rompen el programa
const toroide tabletaDeChocolate = {
        {true,true,true,true},
        {true,false,false,true},
        {false,true,true,false},
        {true,false,true,true},
        {true,false,false,false},
        {true,false,false,true},
        {true,false,true,false},
        {false,false,false,true}
};

// Evolucion con k = 5
const toroide tabletaDeChocolateEvolucion = {
        {false,false,false,false},
        {false,false,false,false},
        {true,true,true,true},
        {true,false,true,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false}
};

// Secuencia con todos los toroides infinitos
const vector<toroide> toroidesInteresantes = {
        {{true,false,true,false,false,true,false},{false,false,true,true,false,true,false},{true,true,true,true,true,true,false}},
        tabletaDeChocolate
};

#endif //REUNIONESREMOTAS_TOROIDESPARATESTS_H
