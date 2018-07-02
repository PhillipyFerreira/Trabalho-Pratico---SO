#include "filaProcessos.h"
#include "memoria.h"

int main ()
{
//    InicializaFilaProcessos();
    fila *filaTempoReal;
    fila **filaUsuario;
    memoriaPrincipal *memoria;
    recursosDoSistema *dispositivo;
    bool* usoRecurso;

    if (alocaFilas(filaTempoReal, filaUsuario) == -1)
    {
        printf("ERRO NA CRIACAO DAS FILAS");
        return 0;
    }
    if(inicializarMemoria(memoria) == -1)
    {
        printf("ERRO NA ALOCACAO DA MEMORIA PRINCIPAL");
        return 0;
    }
    if(inicializaRecursos(dispositivo) == -1)
    {
        printf("ERRO NA ALOCACAO DOS RECURSOS");
        return 0;
    }
    if ((usoRecurso = (bool *) malloc (QUANTIDADE_DISPOSITIVO*Ssizeof (bool))) == NULL)
    {
        printf("ERRO NO MALLOC");
        return -1;
    }


    //Lembrar de alocar elemento
//    inicializacao (sequencia);
//    inserir (sequencia, sequencia->fim, nome);
//    inserir (sequencia, sequencia->fim, nome);
//    exibe (sequencia); /*o primeiro entrado será exibido */
//    inserir (sequencia, sequencia->fim, nome);
//    exibe (sequencia); /*o primeiro entrado será exibido */
//    remover (sequencia); /* exclusão do primeiro elemento entrado */
//    exibe (sequencia);
//    liberaFilas(filaTempoReal, filaUsuario);
    return 0;
}
