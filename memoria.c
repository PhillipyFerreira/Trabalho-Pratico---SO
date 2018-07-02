#include "memoria.h"

int inicializarMemoria(memoriaPrincipal *memoria)
{
    //alocaMemoria
    if ((memoria = (memoriaPrincipal *) malloc (sizeof (memoriaPrincipal))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }
    //Inicializa o tamanho disponivel da memoria
    memoria->disponivelReal    = TAMANHO_MEMORIA_TEMPO_REAL;
    memoria->disponivelUsuario = TAMANHO_MEMORIA_USUARIO;

    //Aloca recursos para a memoria de tempo real e memoria de usuario
    if ((memoria->mapaBitsReal = (bool *) malloc (TAMANHO_MEMORIA_TEMPO_REAL*sizeof (bool))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }
    if ((memoria->mapaBitsUsuario = (bool *) malloc (TAMANHO_MEMORIA_USUARIO    * sizeof (bool))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }


    return 0;

}
