#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int info;
}TPilha;

int base, lim, topo;

void inicializa(int* base, int* lim, int* topo){
    *base = 0;
    *lim = 9;
    *topo = -1;
}
//inserção de elemento
int pilhaCheia(int lim, int topo){
    if (topo == lim)
        return 1;
    return 0;
}

int pilhaVazia(int base, int topo){
    if (topo<base)
        return 1;
    return 0;
}

int push (TPilha* pilha, int lim, int* topo, int info){
    if (pilhaCheia(lim, *topo))
        return -1; //pilha está cheia, inserção inválida
    else{
        //faz a inserção
        *topo = *topo + 1;
        pilha[*topo].info = info;
        return info; //retorna o elemento
    }
}
//Remoção de elemento
int pop(TPilha* pilha, int base, int* topo){
    if(pilhaVazia(base, *topo))
        return -1; //pilha vazia, remoção inválida
    else{
        //faz a remoção
        int info = pilha[*topo].info;
        *topo = *topo - 1;
        return info; // retorna o elemento removido
    }
}

int peek(TPilha *pilha, int base, int* topo){
    if(pilhaVazia(base, *topo))
        return -1;
    return pilha[*topo].info; /* faz consulta */
}

int main(){
    TPilha pilha[10];
    inicializa(&base, &lim, &topo);
}