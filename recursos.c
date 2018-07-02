#include "recursos.h"

int inicializaRecursos(recursosDoSistema* dispositivo)
{
    //alocaMemoria
    if ((dispositivo = (recursosDoSistema *) malloc (sizeof (recursosDoSistema))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }
    //Inicializa a quantidade de dispositivos disponiveis
    dispositivo->scanner     = QUANTIDADE_SCANNER;
    dispositivo->scanner     = QUANTIDADE_SCANNER;
    dispositivo->impressora  = QUANTIDADE_IMPRESSORA;
    dispositivo->modem       = QUANTIDADE_MODEM;
    dispositivo->sata        = QUANTIDADE_SATA;
    return 0;
}

void usaRecurso(recursosDoSistema* dispositivo, int* usoRecurso)
{
    for(int i=0; i < QUANTIDADE_DISPOSITIVOS; i++)
    {
        if(usoRecurso[i])
        {
            switch (idRecurso)
            {
               case SCANNER:
                 if(dispositivo->scanner == INDISPONIVEL)
                 {

                 }
               break;

               case IMPRESSORA:
                 if(dispositivo->scanner == INDISPONIVEL)
                 {

                 }
               break;

               case MODEM:
                 if(dispositivo->scanner == INDISPONIVEL)
                 {

                 }
               break;

               case SATA:
                 if(dispositivo->scanner == INDISPONIVEL)
                 {

                 }
               break;

               default
                 Instruções;
            }
        }
    }
}

void liberaRecurso(recursosDoSistema* dispositivo)
{

}
