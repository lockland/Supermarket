#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include "my_function.h"


struct arvoreB*
cria_elemento(char info);


void
insere_folha(struct arvoreB ** arv, char info);

//Caminhamento pre-ordem
float
pre_ordem(struct arvoreB * arv, float somatorio);

//Caminhamento em-ordem
void
em_ordem(struct arvoreB * arv);

//Pesquisar um nodo
struct arvoreB*
pesquisar_nodo(struct arvoreB * arv, char pesq);


#endif // ARVOREB_H_INCLUDED
