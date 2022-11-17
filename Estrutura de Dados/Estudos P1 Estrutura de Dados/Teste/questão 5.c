#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

typedef struct pilha
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

int questao5(TPilha *p)
{
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        push(p, num);
        if(p->topo->info != p->topo->prox->info);
        pop(p);
        pop(p);
        scanf("%d", &num);
    }
    return p->topo;
}