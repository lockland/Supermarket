#include "listaD.h"

struct listaD * criar_elemento(char descricao[], float preco, int qtd){
  struct listaD *novo;
  novo = (struct listaD *) malloc(sizeof(struct listaD));
  strcpy(novo->descricao, descricao);
  novo->qtd = qtd;
  novo->preco = preco;
  novo->proximo  = NULL;
  novo->anterior = NULL;
  return novo;
}
//Funcao abaixo insere no inicio da lista
struct listaD * insere_primeiro(struct listaD * lista, struct listaD * novo){
   if (lista != NULL){
     lista->anterior = novo;
     novo->proximo = lista;
   }
   return novo;
}


struct listaD * retorna_ultimo_da_lista(struct listaD * lista){
  while (lista->proximo != NULL){
    lista = lista->proximo;
  }
  return lista;
}

struct listaD * insere_ultimo(struct listaD * lista, struct listaD * novo){
  if (lista != NULL) {
    struct listaD * n = retorna_ultimo_da_lista(lista);
    n->proximo = novo;
    novo->anterior = n;
    return lista;
  }else{
    return novo;
  }
}

void apresenta_lista(struct listaD * lista){
  //Percorrendo os elementos da lista
   int cont = 1;
   while (lista != NULL){
      printf("\tProduto [%d]: Descricao %s, Preco %0.2f, Quantidade %d\n", cont, lista->descricao, lista->preco, lista->qtd);
      cont++;
      lista = lista->proximo;
   }
}

void apresenta_lista_inversa(struct listaD * lista){
   int cont = 1;
   struct listaD * ultimo = retorna_ultimo_da_lista(lista);
   system("pause");
   while (ultimo != NULL){
      printf("Produto [%d]: Descricao %s, Preco %0.2f, Quantidade %d\n", cont, lista->descricao, lista->preco, lista->qtd);
      cont++;
      ultimo = ultimo->anterior;
   }
}
