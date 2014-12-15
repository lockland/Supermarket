/**
				#######################################################
								Trabalho GB
								Disciplina: Estrutura de dados
								professora: Aline Riva
								Nome: Sidney dos Santos Souza / João Henrique Seibel Rodriguez 
				#######################################################
	
Proposta do trabalho:
--------------------------------------------------------------------------------------------------
A figura abaixo descreve uma estrutura em arvore, o qual possui a representação de uma empresa de 
atacado e varejo. Esta estrutura em árvore representa a comercialização de produtos na empresa em 
seus diversos setores. A arvore possui uma Raiz (Sigla G), a qual não deve possuir produtos 
comercializados em sua lista, e duas subárvores, uma a Esquerda e outra a Direita. A subárvore da 
Esquerda (Sigla D), possui apontamento para sua "lista de produtos vendidos" e pode ter duas 
subárvores (Ex: Siglas C e F ).  É importante definir que a lista de produtos de um setor é representada 
por uma lista duplamente encadeada.  
 
O objetivo desse trabalho é implementar as funções necessárias para atender as opções exibidas   na 
tela principal do programa (utilize o código fornecido).  
 
Observação: A soma de um setor incluí os produtos vendidos nele mais a soma de todos os produtos 
vendidos nos setores que são filhos dele 
----------------------------------------------------------------------------------------------------

obs: A ide utilizada para compilação desse trabalho foi o CODE:BLOCKS com compilador GCC.
	Criei um projeto com o intuito de aplicar as tecnicas de TAD e facilitar o debugging caso necessario.
*/

#include "my_function.h"

int
main()
{
    char op;
    char setor;
    noArvore* tree = NULL;

    do
    {
        system("cls");
        printf("\t******************************************************************\n");
        printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
        printf("\t******************************************************************\n");
        printf("\t* \t\t\t\t\t\t\t\t *\n");
        printf("\t*\t INSERIR SETOR..........................[1] \t\t *\n");
        printf("\t*\t MOSTRAR SETORES........................[2] \t\t *\n");
        printf("\t*\t VENDER PRODUTO.........................[3] \t\t *\n");
        printf("\t*\t MOSTRAR PRODUTOS VENDIDOS NO SETOR.....[4] \t\t *\n");
        printf("\t*\t SOMATORIO DOS PRODUTOS VENDIDOS........[5] \t\t *\n");
        printf("\t*\t SAIR DO SISTEMA........................[0] \t\t *\n");
        printf("\t* \t\t\t\t\t\t\t\t *\n");
        printf("\t******************************************************************\n\n\n");
        printf("\t\tESCOLHA UMA OPCAO: ");
        op = getchar();
        fflush(stdin);

        switch(op)
        {
            case '1':
                system("cls");
                printf("\t******************************************************************\n");
                printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                printf("\t******************************************************************\n\n\n");
                printf("\tESCOLHA A SIGLA PARA O SETOR, EX: \"Z\": ");
                setor = getchar();
                fflush(stdin);

                do
                {
                    noArvore* existe = pesquisar_nodo(tree, setor);
                    if(!existe)
                    {
                        insere_folha(&tree, setor);
                        break;
                    }
                    else
                    {
                        printf("\tSETOR JA EXISTE, ESCOLHA OUTRA SIGLA: ");
                        setor = getchar();
                        fflush(stdin);
                    }
                }while(1);
                printf("\n\tSETOR INSERIDO COM SUCESSO !!!\n");

                printf("\n\t");system("pause");

                break;

            case '2':
                system("cls");
                printf("\t******************************************************************\n");
                printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                printf("\t******************************************************************\n\n\n");
                printf("\tSETORES CADASTRADOS\n\t-----------------------------------------------\n\n");
                em_ordem(tree);
                printf("\n\t");system("pause");
                break;

            case '3':
                system("cls");
                printf("\t******************************************************************\n");
                printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                printf("\t******************************************************************\n\n\n");
                printf("\tDIGITE O SETOR PARA QUAL DESEJA VENDER O PRODUTO: ");
                setor = getchar();
                fflush(stdin);

                while(setor == tree->info)
                {
                    system("cls");
                    printf("\t******************************************************************\n");
                    printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                    printf("\t******************************************************************\n\n\n");
                    printf("\tVOCE NAO PODE INSERIR PRODUTOS NESSE SETOR. ESCOLHA OUTRO: ");
                    setor = getchar();
                    fflush(stdin);
                }

                char descricao[20];

                printf("\n\tDIGITE A DESCRICAO DO PRODUTO: ");
                scanf("%[^\n]", descricao);

                float preco;
                int qtd;

                printf("\n\tDIGITE O PRECO DO PRODUTO: ");
                scanf("%f", &preco);

                printf("\n\tDIGITE A QUANTIDADE DO PRODUTO: ");
                scanf("%d", &qtd);

                vende_produto(tree, setor ,descricao, preco, qtd);

                printf("\n\tPRODUTO VENDIDO COM SUCESSO :D !!!\n");

                printf("\n\t");system("pause");
                break;

            case '4':
                system("cls");
                printf("\t******************************************************************\n");
                printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                printf("\t******************************************************************\n\n\n");
                printf("\tESCOLHA O SETOR: ");
                setor = getchar();
                fflush(stdin);

                mostra_produtos(tree, setor);
                break;

            case '5':
                system("cls");
                printf("\t******************************************************************\n");
                printf("\t* \t\t\t TRABALHO FINAL GB \t\t\t *\n");
                printf("\t******************************************************************\n\n\n");
                printf("\tESCOLHA O SETOR: ");
                setor = getchar();
                fflush(stdin);

                mostraSomaSetor(tree, setor);
                break;
        }
    }while(op != '0');

    printf("\n\t");
    return 0;
}
