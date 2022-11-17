#include <stdio.h>
#include <stdlib.h>

/* Questão 1, uma pilha por meio de duas filas */

typedef struct lista
{
    int info;
    struct lista *prox;
} Tlista;

Tlista *criaLista()
{
    return NULL;
}

typedef struct fila
{
    Tlista *inicio;
    Tlista *fim;
} TFila;

TFila *criafila()
{
    TFila *novo = (TFila *)malloc(sizeof(TFila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void insereFila(TFila *f, int i)
{
    Tlista *novo = (TFila *)malloc(sizeof(TFila));
    novo->info = NULL;
    if (f == NULL)
        f->inicio = novo;
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int retiraFila(TFila *f)
{
    if (f == NULL)
        exit(1);
    int info;
    Tlista *aux = (Tlista *)malloc(sizeof(Tlista));
    info = f->inicio->info;
    aux = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(aux);
    return info;
}

void pegaTopo(TFila *f)
{
    int resultado;
    if (f->inicio->prox == NULL)
    {
        resultado = retiraFila(f);
    }
    else
    {
        TFila *filaAux = (TFila *)malloc(sizeof(TFila));
        while (f->inicio->prox != NULL)
        {
            insereFila(filaAux, retiraFila(f));
        }
        resultado = retiraFila(f);
        while (filaAux->inicio != NULL)
        {
            insereFila(f, retiraFila(filaAux));
        }
    }
    printf("%d\n", resultado);
}

void main()
{
    TFila *f = criafila();
    insereFila(f, 1);
    insereFila(f, 2);
    insereFila(f, 3);
    pegaTopo(f);
}
