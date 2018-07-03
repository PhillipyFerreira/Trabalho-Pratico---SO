#include "funcaoFila.h"
int numeroTotalProcessos = 0;
/* Inicializa a fila  */
void inicializacao (fila ** sequencia)
{
    (*sequencia)->inicio = NULL;
    (*sequencia)->fim = NULL;
    (*sequencia)->tamanho = 0;
}

/* inserir (adicionar) um elemento na fila */
int inserir (fila **sequencia, tipoProcesso *processo)
{
    static int PID = 1;
    //Aloca recurso para o novo elemento
    elemento *novo_elemento;
    if ((novo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL)
    {
        printf("ERRO NA EM CRIAR NOVO ELEMENTO");
        return -1;
    }

    if ((novo_elemento->processo = (tipoProcesso *) malloc (sizeof(tipoProcesso))) == NULL)
    {
        printf("ERRO NA EM CRIAR O ELEMENTO PROCESSO");
        return -1;
    }

    //Seta o processo recebido como aprametro para o novo elemento da lista

    novo_elemento->processo->blocoMemoria           = processo->blocoMemoria;
    novo_elemento->processo->prioridade             = processo->prioridade;
    novo_elemento->processo->tempoInit              = processo->tempoInit;
    novo_elemento->processo->tempoProcessador       = processo->tempoProcessador;
    novo_elemento->processo->usoRecurso[SCANNER]    = processo->usoRecurso[SCANNER];
    novo_elemento->processo->usoRecurso[IMPRESSORA] = processo->usoRecurso[IMPRESSORA];
    novo_elemento->processo->usoRecurso[SATA]       = processo->usoRecurso[SATA];
    novo_elemento->processo->usoRecurso[MODEM]      = processo->usoRecurso[MODEM];

    novo_elemento->processo->PID = PID;

    // Se a lista esta vazia
    if((*sequencia)->fim == NULL)
    {
        // Insere o novo elemento na lista e ajusta os ponteiros
        (*sequencia)->fim = novo_elemento;
        (*sequencia)-> inicio = novo_elemento;
        novo_elemento->seguinte = NULL;
    }
    else
    {
        // Insere o novo elemento na lista e ajusta os ponteiros
        (*sequencia)->fim = novo_elemento;
        novo_elemento->seguinte = NULL;
        (*sequencia)->fim->seguinte = novo_elemento;
    }

    (*sequencia)->tamanho++;
    PID ++;
    numeroTotalProcessos ++;

    return 0;
}

/* remover (remover) um elemento de la fila */
int remover (fila ** sequencia)
{

    elemento *remov_elemento;
    //Verifica se a fila esta fazia
    if ((remov_elemento = (elemento *) malloc (sizeof (elemento))) == NULL)
    {
        printf("ERRO NA EM CRIAR NOVO ELEMENTO");
        return -1;
    }
    if ((*sequencia)->tamanho == 0)
        return -1;
    remov_elemento = (*sequencia)->inicio;
    //Remove o primeiro elemento da lista
    (*sequencia)-> inicio = (*sequencia)->inicio->seguinte;
    //Libera a memoria do elemento removido
    free (remov_elemento);
    //Diminui o tamanho da fila
    (*sequencia)->tamanho--;
    if ((*sequencia)->tamanho == 0)
    {
        (*sequencia)->inicio=NULL;
        (*sequencia)->fim=NULL;
    }
    //Diminui a quantidade total de processos
    numeroTotalProcessos--;
    return 0;
}

/* exibição da fila */
void exibe(fila *sequencia)
{
    elemento *proximo;

    int i;
    proximo = sequencia->inicio;
    //Imprime toda a lista
    if(sequencia->tamanho == 0)
    {
        printf("FILA VAZIA");
    }
    for(i=0; i<sequencia->tamanho; ++i)
    {
        printf("tempoInit: %d\nprioridade: %d\ntempoProcessador: %d\nblocoMemoria: %d\nImp: %d\nscn: %d\nmod: %d\nsata: %d\nPID: %d\n",
                        proximo->processo->tempoInit, proximo->processo->prioridade, proximo->processo->tempoProcessador, proximo->processo->blocoMemoria,
                        proximo->processo->usoRecurso[IMPRESSORA], proximo->processo->usoRecurso[SCANNER], proximo->processo->usoRecurso[MODEM],
                        proximo->processo->usoRecurso[SATA], proximo->processo->PID);
        proximo = proximo->seguinte;
    }
}

// Remove o primeiro elemento da sequencia1 e inclui na sequencia2
int alteraFila(fila ** sequencia1, fila ** sequencia2)
{
    elemento *elementoTemp;
    //Verifica se a fila esta fazia
    if ((elementoTemp = (elemento *) malloc (sizeof (elemento))) == NULL)
    {
        printf("ERRO NA EM CRIAR NOVO ELEMENTO");
        return -1;
    }

    elementoTemp = (*sequencia1)->inicio;
    //Remove o primeiro elemento da lista
    remover(sequencia1);
    inserir(sequencia2, elementoTemp);
    return 0;
}

// Verifica se a fila esta vazia
bool vazia(fila *sequencia)
{
    if(sequencia->tamanho==0)
    {
        return true;
    }else
    {
        return true;
    }
}

