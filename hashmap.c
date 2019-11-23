/* hashmap.c
 *
 * Implementação das operações realizadas sobre o TAD hash_map
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

#include "hashmap.h"
#include "listaord.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void map_init(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) {
		lst_init(&m[i]);
	}
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/*int map_size(hash_map m)
{
	int i, cont = 0;
	for (i = 0; i < M; i++) {
		cont += lst_size(m[i]);
	}
	return cont;
}*/

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* bool map_isempty(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) 
		if (!lst_isempty(m[i]))
			return false;
	return true; 
}*/

map_value * map_get(hash_map m, map_key key)
{
	return lst_find(m[h(key)], key);
}

void map_put(hash_map m, map_key key, map_value val)
{
	lst_ins(&m[h(key)], key, val);
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* map_value * map_remove(hash_map m, map_key key)
{
	return lst_rem(&m[h(key)], key);
}*/

/* método do meio do quadrado para chaves alfanuméricas */
int h(map_key key)
{
	int i, soma = 0;
	// converte a chave para um inteiro
	for (i = 0; key[i] != '\0'; i++) {
		soma += key[i] << (i % 8);
	}
	
	// meio do quadrado
	soma *= soma;
	int x = log10(M) / log10(2);
	int desl = (NUM_BITS - x) / 2;
	soma >>= desl;
	return soma & ((int) pow(2, x) - 1);
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* void map_print(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) {
		printf("\n[%d] = ", i);
		printf("%d", lst_size(m[i]));
		//lst_print(m[i]);
	}
	printf("\n");
} */

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* void map_kill(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) {
		lst_kill(&m[i]);
	}
} */
