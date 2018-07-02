#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED
#include "recursos.h"

typedef struct tipoProcesso
{
    int tempoInit;
    int prioridade;
    int tempoProcessador;
    int blocoMemoria;
    int inicioMemoria;
    int fimMemoria;
    int usoRecurso[5];
} tipoProcesso;

int inicializaProcesso(tipoProcesso* processo);


#endif // PROCESSO_H_INCLUDED
