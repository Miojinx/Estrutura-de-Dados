#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\erikt\OneDrive\Matérias UFF\Terceiro período\Estrutura de Dados\Revisão lista encadeada\listaEncadeada.h"
// declaração

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

int filaVazia(TFila *f)
{
    if (f->inicio == NULL)
        return 1;
    return 0;
}

void insere(TFila *f, int elem)
{
    TLista* novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; // inserção no fim da fila
    if (!filaVazia(f))
        f->fim->prox = novo;
    else
        f->inicio = novo;
    f->fim = novo; // elt. novo é o novo fim da fila
}

int retira(TFila *f)
{
    if (filaVazia(f))
        exit(1);
    int info = f->inicio->info;
    TLista* aux = f->inicio;
    f->inicio = f->inicio->prox;
    /* se elemento removido era o único da fila
    faz fim apontar para null também*/
    if (f->inicio == NULL)
        f->fim = NULL;
    free(aux);
    return info;
}

int alteraInicio(TFila *f, int novoElem){
    f->inicio->info = novoElem;
    return 0;
}