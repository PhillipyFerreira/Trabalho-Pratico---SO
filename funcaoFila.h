#ifndef FUNCAOFILA_H_INCLUDED
#define FUNCAOFILA_H_INCLUDED

#include "processo.h"

typedef struct elementoLista
{
    tipoProcesso *processo;
    struct elementoLista *seguinte;
} elemento;

typedef struct filaFIFO
{
    elemento *inicio;
    elemento *fim;
    int tamanho;
} fila;

/* Inicializa a fila  */
void inicializacao (fila ** sequencia);

/* inserir (adicionar) um elemento na fila */
int inserir (fila **sequencia, tipoProcesso *processo);

/* remover (remover) um elemento de la fila */
int remover (fila ** sequencia);

/* remover (remover) um elemento de la fila */
int alteraFila(fila ** sequencia1, fila ** sequencia2);

/* exibição da fila */
void exibe(fila *sequencia);

#endif
