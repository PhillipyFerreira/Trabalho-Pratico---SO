#include "filaProcessos.h"
#include "escalonaProcessos.h"
#include "memoria.h"

int main ()
{
    //Declaração de variáveis
//    InicializaFilaProcessos();
    fila *filaTempoReal;
    fila **filaUsuario;
    memoriaPrincipal *memoria;
    recursosDoSistema *dispositivo;
    tipoProcesso *processo;
    FILE *process;
    int clock = 0;
    bool existeProcessos=true;

    //Aloca os recursos dinamicamente
    {
    if (alocaFilas(&filaTempoReal, &filaUsuario) == ERROR)
    {
        printf("ERRO NA CRIACAO DAS FILAS");
        return 0;
    }
    inicializacao(&filaTempoReal);
    inicializacao(&filaUsuario[FILA_PRIORIDADE1]);
    inicializacao(&filaUsuario[FILA_PRIORIDADE2]);
    inicializacao(&filaUsuario[FILA_PRIORIDADE3]);
    if(inicializarMemoria(&memoria) == ERROR)
    {
        printf("ERRO NA ALOCACAO DA MEMORIA PRINCIPAL");
        return 0;
    }
    if(inicializaRecursos(&dispositivo) == ERROR)
    {
        printf("ERRO NA ALOCACAO DOS RECURSOS");
        return 0;
    }
    if(inicializaProcesso(&processo) == ERROR)
    {
        printf("ERRO AO INICILIZAR UM PROCESSO");
        return 0;
    }
    }

    //Arquivo de entrada de processos
	process=fopen("processes.txt","r"); /*leitura do arquivo processes.txt*/

    //Verifica a integridade do arquivo
	if (process == NULL)
    {
        printf ("Erro: nao foi possivel abrir o arquivo.\n");
        return(1);
    }

    while((fscanf(process,"%d, %d, %d, %d, %d, %d, %d, %d\n", &processo->tempoInit, &processo->prioridade,
                    &processo->tempoProcessador, &processo->blocoMemoria, &processo->usoRecurso[IMPRESSORA],
                    &processo->usoRecurso[SCANNER], &processo->usoRecurso[MODEM], &processo->usoRecurso[SATA])) != EOF)
    {
        if( processo->prioridade == FILA_TEMPO_REAL )
        {
            inserir(&filaTempoReal, processo);
        }
        else
        {
            inserir(&filaUsuario[processo->prioridade], processo);
        }
    }




    while(existeProcessos)
    {
        printf("FILA NO TEMPO %d \n\n", clock);
        exibe(filaTempoReal);
        existeProcessos = executaFila(&filaTempoReal, clock, &memoria);
//        while(executaFila(&filaTempoReal, clock, &memoria));
//        while(executaFilaUsuario(&filaUsuario, clock, &memoria));
//        if((vazia(filaTempoReal) && vazia(filaUsuario[FILA_PRIORIDADE1]) && vazia(filaUsuario[FILA_PRIORIDADE2]) & vazia(filaUsuario[FILA_PRIORIDADE3])))
//        {
//            existeProcessos=false;
//        }
        clock ++;
        system("pause");
    }
    {
//	printf("dispatcher => \n");
//	printf("PID: %d\n",num_processo);
//	printf("offset: \n");
//	printf("blocks: %d\n", blocos_mem);
//	printf("priority: %d\n", prioridade);
//	printf("time: %d\n", tempo_de_execucao);
//	printf("printers: %d\n",impressora);
//	printf("scanners: %d\n",scanner);
//	printf("modems: %d\n",modem);
    }
//	printf("drives: %d\n\n",sata);

//  IMPLEMENTAR FREE() DOS MALLOCs,m
//    liberaFilas(filaTempoReal, filaUsuario);
//
    return 0;
}
