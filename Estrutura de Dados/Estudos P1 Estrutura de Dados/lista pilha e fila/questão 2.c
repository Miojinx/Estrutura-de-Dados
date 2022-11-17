/* Implemente uma fila por meio de duas pilhas */

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
    int minVal;
} TPilha;

TPilha *criaPilha()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(pilha));
    pilha->topo = NULL;
    pilha->minVal = NULL;
    return pilha;
}

void push(TPilha *p, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = p->topo;
    p->topo = novo;
    if (p->topo->info < p->minVal)
        p->minVal = p->topo->info;
}

int pop(TPilha *pilha)
{
    TLista *aux;
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    if (pilha->minVal == aux->info)
    {
        TLista *p;
        int menor = 9999;
        for (p = pilha->topo; p != NULL; p = p->prox)
        {
            if (p->info < menor)
            {
                menor = p->info;
            }
        }
        pilha->minVal = menor;
    }
    int x = aux->info;
    free(aux);
    return x;
}

void filaPorPilha(TPilha *p)
{
    if (p->topo->prox == NULL)
        printf("%d\n", p->topo);
    else
    {
        TPilha *pilhaAux = criaPilha();
        while (p->topo->prox != NULL)
            push(pilhaAux, pop(p));
        print("%d\n", pop(p));
        while (pilhaAux->topo != NULL)
            push(p, pop(pilhaAux));
    }
}

/* QUESTÃO 3. RETORNAR O MENOR ELEMENTO SEM ITERAR PELA PILHA */

int min(TPilha *p)
{
    return p->minVal;
}