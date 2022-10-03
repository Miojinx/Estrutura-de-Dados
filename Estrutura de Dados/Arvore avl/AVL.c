#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\erikt\OneDrive\Matérias UFF\Terceiro período\Estrutura de Dados\Revisão lista encadeada\listaEncadeada.h"

/* para uma árvore ser avl, ela deve ser binária de busca e a diferença entre as subárvores deve ser de no máximo 1.

Fator de balanceamento: diferença entre a altura da subárvore direita e esquerda
FB(n) = altura(n->dir) - altura(n->esq) 
se FB for -1, 0 ou 1, está balanceado, ou seja, é AVL
Inserção e exclusão devem preservar as propriedades da AVL*/

