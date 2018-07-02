#include "processo.h"

int inicializaProcesso(tipoProcesso* processo)
{

    if ((processo = (tipoProcesso *) malloc (QUANTIDADE_DISPOSITIVOS*sizeof (tipoProcesso))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }

//    if ((processo->usoRecurso = (int *) malloc (QUANTIDADE_DISPOSITIVOS*sizeof (int))) == NULL)
//    {
//        printf("ERRO NO MALLOC");
//        return -1;
//    }
    return 0;
}
