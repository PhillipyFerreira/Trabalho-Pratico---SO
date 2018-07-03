#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED
#include "recursos.h"

typedef struct tipoProcesso
{
    int pid;
    int tempoInit;
    int prioridade;
    int tempoProcessador;
    int blocoMemoria;
    int inicioMemoria;
    int fimMemoria;
    int usoRecurso[QUANTIDADE_DISPOSITIVOS];
} tipoProcesso;

int inicializaProcesso(tipoProcesso** processo);


#endif // PROCESSO_H_INCLUDED
