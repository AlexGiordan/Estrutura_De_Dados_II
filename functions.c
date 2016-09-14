#include <stdio.h>
#include <stdlib.h>

int ListaMenu(){
	int OpcaoListaMenu;

	printf("\n.....Menu Inicial.....");
	printf("\n[ 0] - Sair.");
	printf("\n[ 1] - Iniserir elemento na arvore.");
	printf("\n[ 2] - Remover elemento na arvore.");
	printf("\n[ 3] - Imprimir arvore basica.");
	printf("\n[ 4] - Finalizar arvore.");
	printf("\n");
	printf("\nOpcção: ");
	scanf("%d", &OpcaoListaMenu);
	printf("\n");
	
	return OpcaoListaMenu;
}

TNode *InicializarArvore(){
	TNode *Arvore;
	
	return Arvore = NULL;
}
