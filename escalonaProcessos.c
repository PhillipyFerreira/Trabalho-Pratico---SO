#include "escalonaProcessos.h"

bool executaFila(fila **filaProcessos, int clock, memoriaPrincipal **memoria)
{
    if(((*filaProcessos)->tamanho == 0))
        return false;
    if(((*filaProcessos)->inicio->processo->tempoInit) > clock)
        return false;

    (*filaProcessos)->inicio->processo->tempoProcessador --;

    if(((*filaProcessos)->inicio->processo->tempoProcessador <= 0))
    {
        remover(filaProcessos);
        return false;
    }
    alteraFila(filaProcessos, filaProcessos);
    return true;
}

bool executaFilaUsuario(fila ***filaProcessos, int clock, memoriaPrincipal **memoria)
{
    while(executaFila(&(*filaProcessos)[FILA_PRIORIDADE1], clock, &memoria));
    while(executaFila(&(*filaProcessos)[FILA_PRIORIDADE2], clock, &memoria));
    while(executaFila(&(*filaProcessos)[FILA_PRIORIDADE3], clock, &memoria));
    return false;
}

bool executaFilaU(fila **filaProcessos, int clock, memoriaPrincipal **memoria, fila **filaProcessosMenorPrioridade)
{
    if(((*filaProcessos)->tamanho == 0))
        return false;
    if(((*filaProcessos)->inicio->processo->tempoInit) > clock)
        return false;

    (*filaProcessos)->inicio->processo->tempoProcessador --;

    if(((*filaProcessos)->inicio->processo->tempoProcessador <= 0))
    {
        remover(filaProcessos);
        return false;
    }
    alteraFila(filaProcessos, filaProcessosMenorPrioridade);
    return true;
}
