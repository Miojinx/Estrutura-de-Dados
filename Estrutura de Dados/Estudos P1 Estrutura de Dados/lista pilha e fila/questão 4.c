#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    char info;
    struct Lista * prox;
}TLista;

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

void push(TPilha *p, char elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(TPilha *p)
{
    if(p==NULL)
        exit(1);
    int removido;
    TLista *aux = (TLista *)malloc(sizeof(TLista *));
    removido = p->topo->info;
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    return removido;
}

char* remover_duplicatas(char *s){
    TPilha * p = criaPilha();
    int i = 0;
    while(s[i] != "\0"){
        push(p, s[i]);
        if(p->topo->info == p->topo->prox->info){
            pop(p);
            pop(p);
        }
        i++;
    }
    TPilha * pilhaAux = criaPilha();
    while (p->topo!= NULL)
    {
        push(pilhaAux, p->topo);
    }
    while (pilhaAux->topo!= NULL)
        print("%c", pop(pilhaAux));
    return s;    
}

