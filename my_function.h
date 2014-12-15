#ifndef MY_FUNCTION_H_INCLUDED
#define MY_FUNCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaD.h"
#include "arvoreB.h"

typedef struct arvoreB noArvore;

typedef struct listaD noLista;

struct listaD{
    char descricao[20];
    int qtd;
    float preco;
    noLista *proximo;
    noLista *anterior;
};

struct arvoreB{
  char info;
  noLista* produtos;
  noArvore * esquerda;
  noArvore * direita;
};

void
mostraSomaSetor(noArvore* tree, char setor);

void
vende_produto(noArvore* tree, char setor, char descricao[], float preco, int qtd);

void
mostra_produtos(noArvore* tree, char setor);

#endif // MY_FUNCTION_H_INCLUDED
