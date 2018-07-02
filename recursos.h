#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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

// Criando a enumeração:
enum boolean {
    true = 1, false = 0
};

// Permitindo a sua declaração como um tipo qualquer:
typedef  enum boolean  bool;


typedef struct recursosDoSistema
{
    int scanner;
    int impressora;
    int modem;
    int sata;
}recursosDoSistema;

int inicializaRecursos(recursosDoSistema* dispositivo);

void usaRecurso(recursosDoSistema* dispositivo);

void liberaRecurso(recursosDoSistema* dispositivo);



#endif // RECURSOS_H_INCLUDED

