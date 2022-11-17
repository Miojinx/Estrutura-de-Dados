#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int info;
    struct Lista *prox;
} TLista;

TLista *crialista()
{

    return NULL;
}

TLista *insereInicio(TLista *li, int info)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = info;
    novo->prox = li;
    return novo;
}

TLista *insereFim(TLista *li, int info)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = info;
    novo->prox = NULL;
    TLista *p = li;
    if (p == NULL)
        li = novo;
    else
    {
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }
    return li;
}

TLista *insereOrdenado(TLista *li, int info)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = info;
    TLista *p = li;
    if (p == NULL)
    {
        novo->prox == NULL;
        novo->info = info;
    }
    else if (p->info > info) // insere no inicio se o primeiro ja for maior
    {
        novo->prox = li;
        li = novo;
    }
    else{
        for(p->prox != NULL && p->prox->info < info){
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
    return li;
}

TLista *inverter(TLista *inicio)
{
    TLista *p;
    TLista *nova_lista = cria_lista();
    for (p = inicio; p != NULL; p = p->prox)
    {
        nova_lista = insere(nova_lista, p->info);
    }
    p = inicio;
    while (p != NULL)
    {
        inicio = retira(inicio);
        p = inicio;
    }
    return nova_lista;
}

TLista* questao3(TLista* inicio, int x){
    TLista* p;
    TLista* ant, *atual, *prox;
    for(p=inicio; p->prox != NULL;p=p->prox){
        ant = p;
        atual = p->prox;
        prox = atual->prox;
        if(atual->info == x){
            int aux = ant->info;
            ant->info = prox->info;
            prox->info = aux;
        }
    }
    return inicio;
}

TLista * ordenar(TLista* li){
    TLista * listaOrdenada = (TLista*) malloc(sizeof(TLista));
    listaOrdenada == NULL;
    TLista * p;
    for(p = li; p!= NULL; p = p->prox){
        insereOrdenado(li, p->info);
    }
    p = li;
    while(p!=NULL);
        li = retira(li);
        p = li;
    return listaOrdenada;
}