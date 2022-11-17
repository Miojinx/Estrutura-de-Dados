#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct fila *prox;
} TLista;

typedef struct documento
{
    TLista *topo;
} Doc;

Doc *criar_documento()
{
    Doc *d = (Doc *)malloc(sizeof(Doc));
    d->topo = NULL;
    return d;
}

Doc *importar_imagem(Doc *d, int i)
{
    TLista *imagem = (TLista *)malloc(sizeof(TLista));
    imagem->info = i;
    imagem->prox = d->topo;
    d->topo = imagem->prox;
}
