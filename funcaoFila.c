#include "funcaoFila.h"

/* Inicializa a fila  */
void inicializacao (fila * sequencia)
{
    sequencia->inicio = NULL;
    sequencia->fim = NULL;
    sequencia->tamanho = 0;
}

/* inserir (adicionar) um elemento na fila */
int inserir (fila * sequencia, elemento * ElementoFim, char *dado)
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

    //Se a lista esta vazia
    if(ElementoFim == NULL)
    {
        //Verifica se a lista realmente estah vazia
        if(sequencia->tamanho == 0)
        {
            sequencia->fim = novo_elemento;
            sequencia-> inicio = novo_elemento;
            novo_elemento->seguinte = NULL;
        }
    }
    else
    {
        //Insere o novo elemento ao fim da fila
        sequencia->fim = novo_elemento;
        novo_elemento->seguinte = NULL;
        ElementoFim->seguinte = novo_elemento;
    }
    sequencia->tamanho++;
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


