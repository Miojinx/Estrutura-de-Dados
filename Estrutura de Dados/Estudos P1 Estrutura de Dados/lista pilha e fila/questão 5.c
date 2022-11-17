#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int info;
    struct Lista *prox;
} TLista;

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

void mostraPilha(TPilha *p)
{/* 
    TLista *aux;
    if (p != NULL)
    {
        for (aux = p->topo; aux != NULL; aux = aux->prox){
            printf("%d\n",aux->info);
        }
    } */

    TLista *aux;
    aux = p->topo;
    while(aux){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void removerX(TPilha *p, int x)
{
    int valTopo;
    TPilha *pilhaAux = criaPilha();
    while (p->topo != NULL)
    {
        valTopo = (pop(p));
        if (valTopo != x)
            push(pilhaAux, valTopo);
    }
    while (pilhaAux->topo != NULL)
    {
        push(p, pop(pilhaAux));
    }
    free(pilhaAux);
}

main()
{
    TPilha *p = criaPilha();
    push(p, 1);
    push(p, 1);
    push(p, 7);
    push(p, 5);
    push(p, 2);
    push(p, 1);
    removerX(p, 1);
    mostraPilha(p);
}