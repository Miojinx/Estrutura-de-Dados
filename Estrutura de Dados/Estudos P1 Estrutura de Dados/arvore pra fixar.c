#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Arvore
{
    char info;
    struct Arvore *esq;
    struct Arvore *dir;
} TNoA;

TNoA *criaArvore(char c)
{
    TNoA *novo = (TNoA *)malloc(sizeof(TNoA));

    novo->info = c;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

void imprimeArvore(TNoA *a, int tab)
{
    for (int i = 0; i < tab; i++)
        printf("-");
    if (a != NULL)
    {
        printf("%c\n", a->info);
        imprimeArvore(a->esq, tab + 2);
        printf("\n");
        imprimeArvore(a->dir, tab + 2);
    }
}

// profundidade, simetrica e pós ordem

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
    if (esq < dir)
        return dir;
    if (esq == dir)
        return esq;
}

int quantidadeNo(TNoA *a)
{
    if (a == NULL)
        return 0;
    return 1 + quantidadeNo(a->esq) + quantidadeNo(a->dir);
}

int arvoreCheia(TNoA *a, int qtdNo, int alt)
{
    int calculaNos = 0;
    for (int i = 0; i < alt; i++)
        calculaNos = calculaNos + pow(2, i);
    if (calculaNos == qtdNo)
        return 1;
    return 0;
}

TNoA *espelho(TNoA *a)
{
    if (a != NULL)
    {
        TNoA *arvoreEspelho = (TNoA *)malloc(sizeof(TNoA));
        arvoreEspelho->info = a->info;
        arvoreEspelho->esq = espelho(a->dir);
        arvoreEspelho->dir = espelho(a->esq);
        return arvoreEspelho;
    }
    return NULL;
}