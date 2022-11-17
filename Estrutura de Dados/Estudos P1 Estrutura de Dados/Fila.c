#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

typedef struct Fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *criafila()
{
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->fim = NULL;
    f->inicio = NULL;
    return f;
}

int filaVazia(TFila *f)
{
    if (f->inicio == NULL)
        return 1;
    return 0;
}

void insere(TFila *f, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL;
    if (!filaVazia(f))
        f->fim->prox = novo;
    else
    {
        f->inicio = novo;
    }
    f->fim = novo;
}

int retira(TFila *f)
{
    if (filaVazia(f))
        exit(1);
    int info = f->inicio->info;
    TLista *aux = f->inicio;
    f->inicio = f->inicio->prox;
    // se o elemento removido era o único da fila
    // faz fim apontar para null também
    if (f->inicio == NULL)
    {
        f->fim == NULL;
    }
    free(aux);
    return info;
}

alteraInicio(TFila *f, int novoVal)
{
    f->inicio->info = novoVal;
    return f->inicio->info;
}

int main()
{
    TFila *f = criafila();
    insere(f, 10);
    insere(f, 20);
    imprimeLista(f->inicio);
    imprimeLista(f->fim);
}
