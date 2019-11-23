/* ferramentas.c
 * Descrição das funções referentes ao arquivo ferramentas.h.
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

#include "ferramentas.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* ---------------------------------------------------------------------------------------------
 * Descrição: Remove espaçamentos laterias, i.e. da esquerda e direita, em branco de uma string.
 * ---------------------------------------------------------------------------------------------
 * Parâmetro(s): 
 * char * str: string a ser recortada.
 * ---------------------------------------------------------------------------------------------
 * Retorno(s): 
 * char *: string recortada.
 * ---------------------------------------------------------------------------------------------
 */
char * trim(char * str){
    char *end;

    while(isspace((unsigned char)*str)) str++;

    if(*str == 0) return str;

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';

    return str;
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* --------------------------------------------------------------
 * Descrição: Verifica se uma string possui, ao menos, uma letra.
 * --------------------------------------------------------------
 * Parâmetro(s): 
 * char * str: string a ser verificada.
 * --------------------------------------------------------------
 * Retorno(s): bool
 * true: caso possua, ao menso, uma letra; 
 * false: caso não possua, ao menos, umaa letra.
 * --------------------------------------------------------------
 */
/* bool is_there_char(char * str){
    unsigned int i;
    for(i = 0; i < strlen(str) - 1; i++){
        if(isalpha(str[i])) return true;
    }
    return false;
} */

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* -----------------------------------------------------------------------------------------------
 * Descrição: Verifica se uma string possui todos os caracteres alfabéticos ou se há espaçamentos.
 * -----------------------------------------------------------------------------------------------
 * Parâmetro(s): 
 * char * str: string a ser verificada.
 * -----------------------------------------------------------------------------------------------
 * Retorno(s): bool 
 * true: caso tenha apenas letras de 'a' até 'z' ou espaços em branco; 
 * false: caso não possua algo além de letras de 'a' até 'z' ou espaços em branco.
 * -----------------------------------------------------------------------------------------------
 */
/* bool is_there_esp_char(char * str){
    unsigned int i;
    for(i = 0; i < strlen(str) - 1; i++){
        if(!isalpha(str[i]) || str[i] != ' ') return true;
    }
    return false;
} */

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* ------------------------------------------------------------------------------------------------------
 * Descrição: Lê o nome de um usuário, aceitando, apenas, letras de 'a' até 'z' e dígitos de '0' até '9'.
 * ------------------------------------------------------------------------------------------------------
 * Parâmetro(s): 
 * char usuario[21]: string que lerá o nome de usuário a ser verificado.
 * ------------------------------------------------------------------------------------------------------
 * Retorno(s): void.
 * ------------------------------------------------------------------------------------------------------
 */
/* void ler_usuario(char usuario[21]){
    printf("Nome do usuario: ");
    char buffer;
    while(scanf(" %20[a-zA-Z0-9]s", usuario) != 1){
        while((buffer = getchar()) != '\n');
        printf("Nome do usuario invalido! Caracteres aceitos: a-z ou A-Z ou 0-9\n");
        printf("Nome do usuario: ");
    }
    while((buffer = getchar()) != '\n');
} */

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* -----------------------------------------------------------------------------------
 * Descrição: Lê o nome completo do usuário, aceitando, apenas, letras de 'a' até 'z'.
 * -----------------------------------------------------------------------------------
 * Parâmetro(s):
 * char nome_completo[21]: string que lerá o nome completo a ser verificado.
 * -----------------------------------------------------------------------------------
 * Retorno(s): void.
 * -----------------------------------------------------------------------------------
 */
/* void ler_nome_completo(char nome_completo[21]){
    printf("Nome completo: ");
    char buffer;
    while(scanf(" %50[a-zA-Z ]s", nome_completo) != 1){
        while((buffer = getchar()) != '\n');
        printf("Nome completo invalido! Caracteres aceitos: a-z ou A-Z ou espaço em branco\n");
        printf("Nome completo: ");
    }
    while((buffer = getchar()) != '\n');
} */
