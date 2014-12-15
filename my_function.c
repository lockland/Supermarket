#include "my_function.h"

void
mostraSomaSetor(noArvore* tree, char setor)
{
    noArvore* _setor = pesquisar_nodo(tree, setor);
    float somatorio = 0.0;
    somatorio = pre_ordem(_setor, somatorio);

    printf("\n\tA SOMA DOS PRODUTOS VENDIDOS EH: %0.2f", somatorio);
    printf("\n\t");system("pause");
}

void
vende_produto(noArvore* tree, char setor, char descricao[], float preco, int qtd)
{
    noArvore* _setor = pesquisar_nodo(tree, setor);
    noLista* produto = criar_elemento(descricao, preco, qtd);
    _setor->produtos = insere_ultimo(_setor->produtos, produto);
}

void
mostra_produtos(noArvore* tree, char setor)
{
    noArvore* _setor = pesquisar_nodo(tree, setor);

    printf("\n");
    apresenta_lista(_setor->produtos);
    printf("\n\t");system("pause");
}
