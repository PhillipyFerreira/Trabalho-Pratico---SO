#ifndef FILAPROCESSOS_H_INCLUDED
#define FILAPROCESSOS_H_INCLUDED

#include "funcaoFila.h"

#define TAMANHO_FILA_USUARIO 3

int alocaFilas(fila **filaTempoReal, fila ***filaUsuario);

void liberaFilas(fila **filaTempoReal, fila **filaUsuario);

#endif
