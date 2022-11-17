#include <stdlib.h>
#include <stdio.h>

typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} TAB;
TAB *criaArvore(char c)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));

    novo->info = c;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

int altura(TAB *a)
{
    if (a == NULL)
        return 0;
    else
    {
        int esq = 1 + altura(esq);
        int dir = 1 + altura(dir);
        if (esq > dir)
            return esq;
        if (dir > esq)
            return dir;
        else
            return esq;
    }
}

int verifica_AVL(TAB * raiz){
    if(raiz!= NULL){
        verifica_AVL(raiz->esq);
        verifica_AVL(raiz->dir);
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        int fb = dir - esq;
        if(fb < -1 || fb > 1)
            exit(0);
        else
            return 1;
    }
    return 0;
}