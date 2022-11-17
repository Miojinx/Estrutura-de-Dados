#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

TLista *insereLista(TLista *l, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

TLista *inverter_mn(TLista *l, int n, int m)
{
    TLista *p, *p2;
    TLista *listaInvertida = criaLista();
    TLista *final = criaLista();
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == n)
            for (p2 = p; p2->prox->info != m; p2 = p2->prox)
                listaInvertida = insereLista(listaInvertida, p2->prox->info);
        break;
    }
    for (p = l; p->info == n; p = p->prox)
    {
        final = insereFim(final, p->info);
    }
    for(p2 = final; p2 != NULL; p2 = p2->prox)
        final = insereFim(final, p2->info);
    for(p = l; p == m; p = p->prox)

    for(p; p != NULL; p=p->prox){
        final = insereFim(final, p->prox);
    }
    return final;
}