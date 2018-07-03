#ifndef FILAPROCESSOS_H_INCLUDED
#define FILAPROCESSOS_H_INCLUDED

#include "funcaoFila.h"

#define TAMANHO_FILA_USUARIO 4

#define FILA_TEMPO_REAL  0
#define FILA_PRIORIDADE1 1
#define FILA_PRIORIDADE2 2
#define FILA_PRIORIDADE3 3

int alocaFilas(fila **filaTempoReal, fila ***filaUsuario);

void liberaFilas(fila **filaTempoReal, fila **filaUsuario);

#endif
