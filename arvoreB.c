#include "arvoreB.h"

//Criacao de um struct arvoreB da arvore
struct arvoreB * cria_elemento(char info){
  struct arvoreB * novo = malloc(sizeof(struct arvoreB));
  novo->info = info;
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->produtos = NULL;
  return novo;
}

//Inclusao de um nodo na Arvore
void insere_folha(struct arvoreB ** arv, char info){
   if (*arv == NULL){
     *arv = cria_elemento(info);
   }else{
   //se a informação é menor que a informacao da arvore, insere a esquerda
     if(info < (*arv)->info){
        insere_folha(&(*arv)->esquerda, info);
     //se a informação é maior que a informacao da arvore, insere a direita
     }else if (info > (*arv)->info){
        insere_folha(&(*arv)->direita, info);
     }
   }
}

//Caminhamento pre-ordem
float pre_ordem(struct arvoreB * arv, float somatorio){
  noLista* aux = NULL;
  if (arv != NULL) {

     for(aux = arv->produtos; aux != NULL; aux = aux->proximo)
        somatorio = somatorio + (aux->preco * aux->qtd);

     if (arv->esquerda != NULL){
       // printf("Nodo Esquerdo. \n");
        somatorio = pre_ordem(arv->esquerda, somatorio);
     }
     if(arv->direita != NULL){
       // printf("Nodo Direito. \n");
        somatorio = pre_ordem(arv->direita, somatorio);
     }
  }
  return somatorio;
}

//Caminhamento em-ordem
void em_ordem(struct arvoreB * arv){
  if (arv != NULL){
     if (arv->esquerda != NULL){
       em_ordem(arv->esquerda);
     }
     printf("\t%c \n", arv->info);
     if (arv->direita != NULL){
       em_ordem(arv->direita);
     }
  }
  else
    printf("\tNENHUM SETOR CADASTRADO !!");
}

struct arvoreB*
pesquisar_nodo(struct arvoreB * arv, char pesq){
  if (arv != NULL){
     if (arv->info == pesq){
        return arv;
     }else{
       if (pesq > arv->info){
          pesquisar_nodo(arv->direita, pesq);
       }else{
          pesquisar_nodo(arv->esquerda, pesq);
       }
     }
  }else{
        return NULL;
  }
}
