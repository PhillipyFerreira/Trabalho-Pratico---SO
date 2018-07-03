#include "funcaoFila.h"

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
    novo_elemento->processo =   processo;

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

    return 0;
}

/* remover (remover) um elemento de la fila */
int remover (fila * sequencia)
{

    elemento *remov_elemento;
    //Verifica se a fila esta fazia
    if (sequencia->tamanho == 0)
        return -1;
    remov_elemento = sequencia->inicio;
    //Altera o inicio da fila
    sequencia-> inicio = sequencia->inicio->seguinte;
    //Libera a memoria do elemento removido
    free (remov_elemento);
    sequencia->tamanho--;
    return 0;
}

/* exibição da fila */
void exibe(fila *sequencia)
{
    elemento *proximo;
    int i;
    proximo = sequencia->inicio;
    //Imprime toda a lista
    for(i=0; i<sequencia->tamanho; ++i)
    {
        proximo = proximo->seguinte;
    }
}


