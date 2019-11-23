/* listaord.h
 *
 * Definição do TAD para uma lista linear encadeada adaptada
 * para um hash map.
 *
 * Criado originalmente por: Ciro C. Trindade.
 * Criado originalmente na data de: 30/Out/2019.
 *
 * Modificado pelo grupo:
 * Nome: Alexadre Saura.
 * Nome: Fábio Thomaz.
 * Nome: Ricardo Oliveira.
 *
 * Disciplina: Estrutura de Dados II.
 * Prof.: Ciro Cirne Trindade.
 * Curso: Ciência da Computação.
 * Universidade Católica de Santos.
 * Modificado no segundo semestre de 2019.
 * Tema do trabalho: Cobertura Vacinal.
 */

#ifndef _LISTAORD_H
#define _LISTAORD_H

#include "hashmap.h"
#include <stdbool.h>

/* função que inicializa a lista encadeada ordenada */
void lst_init(map_ptr *);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* função que devolve o número de elementos da lista */
//int lst_size(map_ptr);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* função que devolve verdadeiro se a lista estiver vazia */
//bool lst_isempty(map_ptr);

/* função que insere um novo par (chave, valor) na lista */
void lst_ins(map_ptr *, map_key, map_value);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* função que imprime a lista */
//void lst_print(map_ptr);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* função que remove a entrada (chave, valor) e devolve o
   endereço do valor, caso sua chave esteja na lista, ou NULL, 
   caso contrário */
//map_value * lst_rem(map_ptr *, map_key);

/* função que e devolve o endereço do valor, caso sua chave 
   esteja na lista, ou NULL, caso contrário */
map_value * lst_find(map_ptr, map_key);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* função que desaloca a lista */
//void lst_kill(map_ptr *);

#endif
