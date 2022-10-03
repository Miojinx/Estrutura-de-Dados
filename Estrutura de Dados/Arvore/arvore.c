/* Árvore
o primeiro nó é a raiz.
nós podem ser pais e filhos e nós de mesmo nível são irmãos
se x pertence a subarvore z, dizemos que x é descendente de v e v é ancestral de x
grau de um nó: é dado pela qunatidade de filhos de um nó. Ex: x tem 3 filhos, ou seja, x tem grau 3
Nó interno: nó com pelo menos um filho
nó folha: nó com grau igual a zero
caminho: uma sequência de nós consecutivos distintos entre dois nós
comprimento do caminho: ligações entre os nós
Nivel: contagem da raiz até a folha mais distante
altura: contagem da folha de maior nível até a raiz
Árvores binárias:
Estritamente Binária: 0 ou 2 filhos
Binária completa: Subárvores vazias apeas no último ou penúltimo nível
Binária cheia: subárvores vazias somente no último nível
Zigue Zague:Nós internos com uma subárvore vazia*/

// Implementação de árvores binárias

// representação dos nós de a
typedef struct noA
{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

// Criar nó
TNoA *criaNo(char ch)
{
    TNoA *novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void main()
{
    TNoA* raiz;
    raiz = criaNo("A");
    raiz->esq = criaNo("B");
    raiz->dir = criaNo("C");

}