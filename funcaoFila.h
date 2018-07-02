#ifndef FUNCAOFILA_H_INCLUDED
#define FUNCAOFILA_H_INCLUDED

#include "processo.h"

typedef struct elementoLista
{
    tipoProcesso *processo;
    struct elementoLista *seguinte;
} elemento;

typedef struct ListaDetectada
{
    elemento *inicio;
    elemento *fim;
    int tamanho;
} fila;

/* FirstInFirstOut */
#define fila_dado(sequencia) sequencia->inicio->dado

/* Inicializa a fila  */
void inicializacao (fila * sequencia);

/* inserir (adicionar) um elemento na fila */
int inserir (fila * sequencia, elemento * ElementoFim, char *dado);

/* remover (remover) um elemento de la fila */
int remover (fila * sequencia);

/* exibição da fila */
void exibe(fila *sequencia);

#endif
