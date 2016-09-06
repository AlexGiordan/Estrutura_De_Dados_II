
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int valor;
  struct node *esq, *dir;
}raiz;

int menu(){
  int op;
  printf("Selecione uma opção:\n");
  printf("1 - Inserir elemento na arvore\n");
  printf("2- Imprimir arvore\n");
  printf("3- Remover elemento\n");
  printf("4- Sair\n");
  printf("Op: "); scanf("%d", &op);
  return op;
}

void imprimePonto(int n){
  int i;
  for (i = 0; i < n; i++) printf(".");
}

int lerValor(){
  int valor;
  printf("Informe o valor que deseja inserir na arvore: ");
  scanf("%d", &valor);
  return valor;
}

void inserirFolha(raiz **arvore, int valor){
  if (*arvore == NULL){
    (*arvore) = (raiz *)malloc(sizeof(raiz));
    (*arvore)->valor = valor;
    (*arvore)->esq = (*arvore)->dir = NULL;
    return ;
  }
  if (valor < (*arvore)->valor){ inserirFolha(&(*arvore)->esq, valor); return ; }
  inserirFolha(&(*arvore)->dir, valor);
}



void imprimeArvore(raiz *arvore, int nivel){
  if (arvore == NULL) return ;
  imprimePonto(nivel * 2 + 2);
  printf("%d\n", arvore->valor);
  imprimeArvore(arvore->esq, nivel + 1);
  imprimeArvore(arvore->dir, nivel+1);
}

void finalizaArvore(raiz **arvore){
  if (*arvore == NULL) return ;
  finalizaArvore(&(*arvore)->esq);
  finalizaArvore(&(*arvore)->dir);
  *arvore = NULL;
}

raiz *removet(raiz *arvore, int num){
  raiz *NoASerRemovido, *NoPai, *Substituto, *Proximo, *Auxiliar;
  
  NoASerRemovido = arvore;
  NoPai = NULL;
  
  // Procura o nó raiz do nó a ser removido
  while ( NoASerRemovido && NoASerRemovido->valor != num) {
    NoPai = NoASerRemovido;
    
    // Verifica se o valor produrado esta a esquerda ou direita
    if (num < NoASerRemovido->valor)
	  NoASerRemovido = NoASerRemovido->esq;
    else
	  NoASerRemovido = NoASerRemovido->dir;
  }  

  // Verifica se o nó ser removido Existe		
  if(!NoASerRemovido) return NULL;
	
  // Verifica em qual lado da arvore deve continuar a descer	
  if (NoASerRemovido->esq == NULL)
	Substituto = NoASerRemovido->dir;
  else
	if (NoASerRemovido->dir == NULL) 
	  Substituto = NoASerRemovido->esq;
    else { // Busca descer sempre a esquerda
	  Auxiliar = NoASerRemovido;
      Substituto = NoASerRemovido->dir;
      Proximo = Substituto->esq;   
            
      while (Proximo != NULL) {
        Auxiliar = Substituto;
        Substituto = Proximo;
        Proximo = Substituto->esq;
      }

      if (Auxiliar != NoASerRemovido) {
        Auxiliar->esq = Substituto->dir;
        Substituto->dir = NoASerRemovido->dir;
      }

      Substituto->esq = NoASerRemovido->esq;
    }

     if (NoPai == NULL) //Verifica se o nó é um nó folha caso verdade já retorna o nó caso falso avança procurando se o nó a ser removido esta a esquerda ou direita
      arvore = Substituto;
     else
      if (NoASerRemovido == NoPai->esq)
        NoPai->esq = Substituto;
      else
        NoPai->dir = Substituto;
     
  free(NoASerRemovido);
  return NoPai;		
}

int main(void){
  int op, num;
  raiz *arvore = NULL;
  inserirFolha(&arvore, 5);
  inserirFolha(&arvore, 10);
  inserirFolha(&arvore, 1);
  inserirFolha(&arvore, 20);

  while (op = menu(), op != 4){
    switch(op){ 
    case 1:

      num = lerValor();
      inserirFolha(&arvore, num);
      printf("ELEMENTO INSERIDO COM SUCESSO!\n\n");
      break;
      case 2:

	printf("ARVORE IMPRESSA:\n");
	imprimeArvore(arvore, 0);
	printf("\n");
	break;
    case 3:

      num = lerValor();
      arvore = removet(arvore, num);
      break;
    }
  }
  finalizaArvore(&arvore);
  return 0;
}
