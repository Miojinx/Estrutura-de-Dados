#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Tlista;

Tlista *criaLista()
{
    return NULL;
}

Tlista *insereLista(Tlista *li, int i)
{
    Tlista *novo = (Tlista *)malloc(sizeof(Tlista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

void imprimeLista(Tlista *li)
{
    Tlista *p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

Tlista *insereFim(Tlista *li, int i)
{
    Tlista *novo = (Tlista *)malloc(sizeof(Tlista));
    novo->info = i;
    novo->prox == NULL;
    Tlista *p = li;
    if (p == NULL)
        li= novo;
    else
    {
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox == novo;
    }
    return li;
}

Tlista *insereOrdenado(Tlista *li, int i)
{
    Tlista *novo = (Tlista *)malloc(sizeof(Tlista));
    novo->info = i;
    Tlista *p = li;
    if (p == NULL)
    {
        novo->prox == NULL;
        novo->info = i;
    }
    else if (p->info > i) // insere no inicio se o primeiro ja for maior
    {
        novo->prox = li;
        li = novo;
    }
    else
    {
        while (p->prox != NULL && p->prox->info > i)
        {
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
    return li;
}

Tlista *exclui(Tlista *li, int elem)
{
    Tlista *p;
    Tlista *c;

    if (li->prox == NULL)
    {
        return NULL;
    }
    if (li->info == elem)
    {
        p = li; // cria auxiliar para poder liberar memoria e nao quebrar a lista
        li = p->prox;
        printf("Elemento encontrado: %d\n", elem);
        printf("--------------------------------------------\n");
    }
    else
    {
        for (p = li; p != NULL; p = p->prox)
        {
            if (p->info == elem)
            {
                c->prox = p->prox; // c usado para percorrer a lista sempre um elemento antes de p
                printf("Elemento encontrado: %d\n", elem);
                printf("--------------------------------------------\n");
                break;
            }
            c = p;
        }
    }
    free(p);
    return li;
}

Tlista *altera(Tlista *li, int vantigo, int vnovo)
{
    Tlista *p;
    if (li == NULL)
        return NULL;
    else if (li->info == vantigo)
    {
        li->info == vnovo;
        return li;
    }
    else
    {
        for (p = li; p != NULL; p = p->prox)
        {
            if (p->info == vantigo)
            {
                p->info == vnovo;
                return li;
            }
        }
    }
}
