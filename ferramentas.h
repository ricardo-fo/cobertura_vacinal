/* ferramentas.h
 * Definição dos protótipos da funções.
 *
 * Criado pelo grupo:
 * Nome: Alexadre Saura.
 * Nome: Fábio Thomaz.
 * Nome: Ricardo Oliveira.
 *
 * Disciplina: Estrutura de Dados II.
 * Prof.: Ciro Cirne Trindade.
 * Curso: Ciência da Computação.
 * Universidade Católica de Santos.
 * Criado no segundo semestre de 2019.
 * Tema do trabalho: Cobertura Vacinal.
 */
 
#ifndef _FERRAMENTAS_H
#define _FERRAMENTAS_H

#include <stdbool.h>

/* Remove espaçamentos laterias, i.e. da esquerda e direita, em branco de uma string.
 * Retorna a string modificada. */
char * trim(char *);

/* Verifica se uma string possui, ao menos, uma letra.
 * Caso possua, ao menso, uma letra, retorna true; caso contrário, retorna false.  */
// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
//bool is_there_char(char *);

/* Verifica se uma string possui todos os caracteres alfabéticos ou se há espaçamentos.
 * Caso tenha apenas letras de 'a' até 'z' ou espaços em branco, retorna true; caso contrário, retorna false. */
// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
//bool is_there_esp_char(char *);

/* Lê o nome de um usuário, aceitando, apenas, letras de 'a' até 'z' e dígitos de '0' até '9'.*/
// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
//void ler_usuario(char [21]);

/* Lê o nome completo do usuário, aceitando, apenas, letras de 'a' até 'z'. */
// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
//void ler_nome_completo(char [51]);

#endif
