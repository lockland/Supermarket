#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

#include "my_function.h"

struct listaD*
criar_elemento(char descricao[], float preco, int qtd);

struct listaD*
insere_primeiro(struct listaD * lista, struct listaD * novo);

struct listaD*
retorna_ultimo_da_lista(struct listaD * lista);

struct listaD*
insere_ultimo(struct listaD * lista, struct listaD * novo);

void
apresenta_lista(struct listaD * lista);

void
apresenta_lista_inversa(struct listaD * lista);

#endif // LISTAD_H_INCLUDED
