#include <stdio.h>>
#include <stdlib.h>
#include <limits.h>
typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *copia(TAB *a)
{

    if (a != NULL)
    {
        TAB *raizCopia = (TAB *)malloc(sizeof(TAB));
        raizCopia->info = a->info;
        raizCopia->esq = copia(a->esq);
        raizCopia->dir = copia(a->dir);
        return raizCopia;
    }
    else
        return NULL;
}

TAB *espelho(TAB *a)
{

    if (a != NULL)
    {
        TAB *raizEspelho = (TAB *)malloc(sizeof(TAB));
        raizEspelho->info = a->info;
        raizEspelho->esq = espelho(a->dir);
        raizEspelho->dir = espelho(a->esq);
        return raizEspelho;
    }
    return NULL;
}

int igual(TAB *a1, TAB *a2)
{

    if (a1 == NULL && a2 == NULL)
    {
        return 1;
    }
    else if (a1 != NULL && a2 != NULL)
    {
        if (a1->info == a2->info && a1->esq == a2->esq && a1->dir == a2->dir)
        {
            igual(a1->esq, a2->esq);
            igual(a1->dir, a2->dir);
            return 0; /* muito brabo fi */
        }
    }
    exit(0);
}

int maior(TAB *a)
{
    if (!a)
        return INT_MIN;

    int aux = a->info;
    int esq = maior(a->esq);
    int dir = maior(a->dir); /* inicio da comparação */
    if (aux < esq)
        aux = esq;
    if (aux < dir)
        aux = dir;
    return aux; /* fazer a comparação dos 3*/
}

int zz(TAB *a) // não ta dando certo
{
    if (a->dir != NULL && a->esq != NULL)
    {
        exit(0);
    }
    if (a->esq != NULL)
        zz(a->esq);
    if (a->dir != NULL)
        zz(a->dir);
    return 1;
}

TAB *retira_pares(TAB *arv)
{
}