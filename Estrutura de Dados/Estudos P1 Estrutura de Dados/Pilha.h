#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    TLista *topo;
} TPilha;

TPilha *criaPilha()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(TPilha *pilha, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(TPilha *pilha)
{
    TLista *aux = (TLista *)malloc(sizeof(TLista));
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    int excluido = aux->info;
    free(aux);
    return excluido;
}

int peek(TPilha *pilha)
{
    return pilha->topo->info;
}

int alteraTopo(TPilha *p, int novoVal)
{
    p->topo->info = novoVal;
    return p->topo->info;
}

main()
{
    TPilha *p = criaPilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);
    imprimeLista(p->topo);
}
