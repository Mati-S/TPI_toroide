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

const toroide tVacio = 
    { 
    };

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


#endif //REUNIONESREMOTAS_TOROIDESPARATESTS_H
