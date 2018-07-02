#include "filaProcessos.h"

int alocaFilas(fila *filaTempoReal, fila **filaUsuario)
{
    static int numeroTotalProcessos = 0;
        //Aloca recursos Fila Tempo real
    if ((filaTempoReal = (fila *) malloc (sizeof (fila))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }
    //Aloca recursos para um array de fila de usuario
    if ((filaUsuario = (fila **) malloc (3*sizeof(fila*))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }
    for(int i = 0; i<TAMANHO_FILA_USUARIO; i++)
    {
        if ((filaUsuario[i] = (fila *) malloc (sizeof (fila))) == NULL)
        {
            printf("ERRO NO MALLOC");
            return -1;
        }
    }
    return 0;
}

void liberaFilas(fila *filaTempoReal, fila **filaUsuario)
{
    free(filaTempoReal);
    for(int i = 0; i<TAMANHO_FILA_USUARIO; i++)
    {
        free(filaUsuario[i]);
    }
    free(*filaUsuario);
    return;
}


