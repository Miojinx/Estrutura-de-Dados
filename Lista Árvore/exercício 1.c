#include <stdio.h>>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;
/*
void imprime(TAB *nodo, int tab)
{
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
*/
TAB* copia(TAB* a){
    TAB* raizCopia = (TAB*) malloc(sizeof(TAB));
    raizCopia = a;

     if (a != NULL)
    {

        printf("%c\n", a->info);
        copia(a->esq);
        printf("\n");
        copia(a->dir);
    }
    else
        printf("vazio"); 
}