#include "functions.c"

typedef struct node{
	int FValor;
	int FFatorBalanceamentoNode;
	struct node *FNodeEsquerda;
	struct node *FNodeDireita;
}TNode;



int ListaMenu();

TNode *InicializarArvore();

