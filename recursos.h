#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include "memoria.h"

//Identifica a quantidade de recursos disponiveis no sistema
#define QUANTIDADE_SCANNER      1
#define QUANTIDADE_IMPRESSORA   2
#define QUANTIDADE_MODEM        1
#define QUANTIDADE_SATA         2
#define INDISPONIVEL            0

//Define a posicao do item no array usoRecurso
#define SCANNER      0
#define IMPRESSORA   1
#define MODEM        2
#define SATA         3

#define QUANTIDADE_DISPOSITIVOS 4

//Estrutura que aloca a quantidade de recursos no sistema
typedef struct recursosDoSistema
{
    int scanner;
    int impressora;
    int modem;
    int sata;
}recursosDoSistema;

//Inicializa os recursos do sistema
int inicializaRecursos(recursosDoSistema* dispositivo);

//Processo verifica e aloca o uso do recurso
int usaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso);

//Processo libera o recurso utilizado
void liberaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso);

#endif // RECURSOS_H_INCLUDED

