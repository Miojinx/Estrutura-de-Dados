#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore
{
    char info;
    struct arvore *esq;
    struct arvore *dir;
} TNoA;

TNoA *criaNo(char info)
{
    TNoA *novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TNoA *nodo, int tab)
{
    for (int i = 0; i < tab; i++)
        printf("-");
    if (nodo != NULL)
    {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }
    else
        printf("vazio");
}

void profundidade(TNoA *a)
{
    if (a != NULL)
    {
        printf("%c\n", a->info);
        profundidade(a->esq);
        profundidade(a->dir);
    }
}

void simetrica(TNoA *a)
{
    if (a != NULL)
    {
        simetrica(a->esq);
        printf("%c\n", a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA *a)
{
    if (a != NULL)
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n", a->info);
    }
}

int altura(TNoA *a)
{
    if (a == NULL)
        return 0;
    int esq = 1 + altura(a->esq);
    int dir = 1 + altura(a->dir);
    if (esq > dir)
        return esq;
    else if (esq < dir)
        return dir;
    else if (esq == dir)
        return esq;
}

int qtdNo(TNoA *a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + qtdNo(a->esq) + qtdNo(a->dir);
}

TNoA *espelho(TNoA *a)
{
    if (a != NULL)
    {
        TNoA *b = (TNoA *)malloc(sizeof(TNoA));
        b->info = a->info;
        b->esq=a->dir;
        b->dir=a->esq;
        return b;
    }
    return NULL;
}

int binariaCheia(qt, alt)
{
    int x = 0, i;
    for (i = 0; i < alt; i++)
        x = x + pow(2, i);
    if (x == qt)
        return 1;
    return 0;
}