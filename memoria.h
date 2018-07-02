#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#define TAMANHO_MEMORIA_TEMPO_REAL  960
#define TAMANHO_MEMORIA_USUARIO     64

#include <stdio.h>
#include <stdlib.h>

typedef struct memoriaPrincipal
{
    //TAMANHO DA MEMORIA
    int disponivelReal;
    int disponivelUsuario;
    //ESPACO DE MEMORIA
    bool *real;
    bool *usuario;
} memoriaPrincipal;


#endif
