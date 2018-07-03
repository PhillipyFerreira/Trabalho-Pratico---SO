#ifndef ESCALONAPROCESSOS_H_INCLUDED
#define ESCALONAPROCESSOS_H_INCLUDED
#include "filaProcessos.h"

bool executaFila(fila **filaProcessos, int clock, memoriaPrincipal **memoria);

bool executaFilaUsuario(fila ***filaProcessos, int clock, memoriaPrincipal **memoria);


#endif // ESCALONAPROCESSOS_H_INCLUDED
