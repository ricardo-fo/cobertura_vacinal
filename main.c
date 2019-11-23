/* main.c
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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ferramentas.h"
#include "hashmap.h"
#include "avl.h"

#define ARQUIVO "cobertura_vacinal.csv"
#define TAMANHO_LINHA 1001
#define SEP ";"

void buscarCidade(hash_map);
void maioresCidades(avl_tree);
void menoresCidades(avl_tree);

int main() {
    FILE * stream;
    if((stream = fopen(ARQUIVO, "r")) == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", ARQUIVO);
        exit(1);
    }

    char linha[TAMANHO_LINHA];
    char aux[TAMANHO_LINHA];

    hash_map mapa;
    map_key chave;
    map_value valor;

    bool h;

    map_init(mapa);
    avl_tree t = NULL; // Ponteiro para a raiz da árvore

    // Percorre o arquivo apenas adicionando os usuários
    while (fgets(linha, TAMANHO_LINHA, stream) != NULL) {
        // Recortar a string
        strcpy(aux, trim(linha));

        // Apagar os dados da estrutura anterior
        strcpy(chave, "");
        strcpy(valor.nome, "");
        strcpy(valor.coberturaVacinal, "");

        // Passagem dos dados do arquivo para a estrutura
        strcpy(chave, strtok(aux, SEP));
        strcpy(valor.nome, strtok(NULL, SEP));
        strcpy(valor.coberturaVacinal, strtok(NULL, SEP));

        map_put(mapa, chave, valor);
        avl_search(&t, valor.coberturaVacinal, valor.nome, chave, &h);
    }
    fclose(stream); // Fecha o arquivo de leitura

    int op;

    do {
        printf("\n<0> Sair;\n");
        printf("<1> Buscar cobertura vacinal;\n");
        printf("<2> Exibir as n cidades com maior cobertura vacinal;\n");
        printf("<3> Exibir as n cidades com menor cobertura vacinal.\n>>> ");
        scanf("%d", &op);
        switch(op){
            case 0:
                printf("Adeus!\n");
                break;
            case 1:
                buscarCidade(mapa);
                break;
            case 2:
                maioresCidades(t);
                break;
            case 3:
                menoresCidades(t);
                break;
            default:
                printf("\nOPCAO INVALIDA!\n");
        }
    } while(op != 0);

    return 0;
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void buscarCidade(hash_map mapa){
    map_key cod;
    printf("Codigo da cidade: ");
    scanf("%s", cod);

    map_value * dados;
    if((dados = map_get(mapa, cod)) == NULL){
        printf("ERRO: Cidade nao encontrada!\n");
    } else {
        printf("Nome da cidade: %s\n", (*dados).nome);
        printf("Cobertura vacinal da cidade: %s\n", (*dados).coberturaVacinal);
    }
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void maioresCidades(avl_tree t){
    int i = 0;
    int qntd;
    printf("\nQuantidade de cidades: ");
    scanf("%d", &qntd);
    printf("\n");
    print_max_tree(t, qntd, &i);
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void menoresCidades(avl_tree t){
    int i = 0;
    int qntd;
    printf("\nQuantidade de cidades: ");
    scanf("%d", &qntd);
    printf("\n");
    print_min_tree(t, qntd, &i);
}
