#include "escalonaProcessos.h"

bool executaFila(fila **filaProcessos, int clock, memoriaPrincipal **memoria)
{

    if((((*filaProcessos)->inicio->processo->tempoInit) > clock) || ((*filaProcessos)->tamanho == 0))
        return false;

    (*filaProcessos)->inicio->processo->tempoProcessador --;
    //IMPLEMENTAR COLOCAR PROCESSO NO FIM DA FILA

    if(((*filaProcessos)->inicio->processo->tempoProcessador == 0))
    {
        remover(filaProcessos);
        return true;
    }
}

bool executaFilaUsuario(fila ***filaProcessos, int clock, memoriaPrincipal **memoria)
{
    while(executaFila(&filaProcessos[FILA_PRIORIDADE1], clock, &memoria));
    while(executaFila(&filaProcessos[FILA_PRIORIDADE1], clock, &memoria));
    while(executaFila(&filaProcessos[FILA_PRIORIDADE1], clock, &memoria));

    return false;
}
