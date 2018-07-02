#include "processo.h"

int inicializaProcesso(tipoProcesso** processo)
{
    if (((*processo) = (tipoProcesso *) malloc (sizeof (tipoProcesso))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }

    return 0;
}
