#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include "memoria.h"

#define QUANTIDADE_SCANNER      1
#define QUANTIDADE_IMPRESSORA   2
#define QUANTIDADE_MODEM        1
#define QUANTIDADE_SATA         2
#define INDISPONIVEL            0

#define SCANNER      0
#define IMPRESSORA   1
#define MODEM        2
#define SATA         3

#define QUANTIDADE_DISPOSITIVOS 4

typedef struct recursosDoSistema
{
    int scanner;
    int impressora;
    int modem;
    int sata;
}recursosDoSistema;

int inicializaRecursos(recursosDoSistema* dispositivo);

int usaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso);

void liberaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso);



#endif // RECURSOS_H_INCLUDED

