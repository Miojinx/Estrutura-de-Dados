#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBusca
{
    char info;
    int chave;
    struct arvoreBusca *esq;
    struct arvoreBusca *dir;
} TNoA;

TNoA *busca(TNoA *no, int chave)
{
    if (no == NULL)
        return NULL;
    else if (no->chave == chave)
        return no;
    else if (no->chave > chave)
        busca(no->esq, chave);
    else
        busca(no->dir, chave);
}

TNoA *insere(TNoA *no, int chave)
{
    if (no == NULL)
    {
        no = (TNoA *)malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    }
    else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave))
        no->dir = insere(no->dir, chave);
    else
    {
        printf("Inserção inválida! "); // chave já existe
        exit(1);
    }
    return no;
}

void criaArvoreBalanceada(TNoA *raiz, int v[], int inicio, int fim)
{
    if (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        raiz = insere(raiz, v[meio]);
        criaArvoreBalanceada(raiz, v, inicio, meio - 1);
        criaArvoreBalanceada(raiz, v, meio + 1, fim);
    }
}