#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define ERROR        -1

#define TAMANHO_MEMORIA_TEMPO_REAL  960
#define TAMANHO_MEMORIA_USUARIO      64

// Criando a enumeração:
enum boolean {
    true = 1, false = 0
};

// Permitindo a sua declaração como um tipo qualquer:
typedef  enum boolean  bool;

typedef struct memoriaPrincipal
{
    //TAMANHO TOTAL DA MEMORIA DISPONIVEL
    int disponivelReal;
    int disponivelUsuario;
    //ESPACO DE MEMORIA
    bool *mapaBitsReal;
    bool *mapaBitsUsuario;
} memoriaPrincipal;

int inicializarMemoria(memoriaPrincipal **memoria);

#endif
