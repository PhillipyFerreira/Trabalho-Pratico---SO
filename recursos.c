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

int usaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso)
{
    bool recursoNaoAlocado = false;
    for(int i=0; i < QUANTIDADE_DISPOSITIVOS; i++)
    {
        if(usoRecurso[i])
        {
            switch (i)
            {
               case SCANNER:
                 if(dispositivo->scanner == INDISPONIVEL)
                 {
                     recursoNaoAlocado = true;
                 }
                 dispositivo->scanner--;
               break;

               case IMPRESSORA:
                 if(dispositivo->impressora == INDISPONIVEL)
                 {
                     recursoNaoAlocado = true;
                 }
                 dispositivo->impressora--;
               break;

               case MODEM:
                 if(dispositivo->modem == INDISPONIVEL)
                 {
                    recursoNaoAlocado = true;
                 }
                 dispositivo->modem--;
               break;

               case SATA:
                 if(dispositivo->sata == INDISPONIVEL)
                 {
                     recursoNaoAlocado = true;
                 }
                 dispositivo->sata--;
               break;
            }
        }
    }
    if(recursoNaoAlocado)
    {
        liberaRecurso(dispositivo, usoRecurso);
        return(-1);
    }
    return 0;
}

void liberaRecurso(recursosDoSistema* dispositivo, bool* usoRecurso)
{
    for(int i=0; i < QUANTIDADE_DISPOSITIVOS; i++)
    {
        if(usoRecurso[i])
        {
            switch (i)
            {
               case SCANNER:
                 dispositivo->scanner++;
               break;

               case IMPRESSORA:
                 dispositivo->impressora++;
               break;

               case MODEM:
                 dispositivo->modem++;
               break;

               case SATA:
                 dispositivo->sata++;
               break;
            }
        }
    }
}
