/* avl.h
 * Definição do TAD para representar uma árvore AVL e protótipo
 * de suas operações.
 *
 * Criado originalmente por: Ciro C. Trindade.
 * Criado originalmente na data de: 30/Set/2019.
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

#ifndef _AVL_H
#define _AVL_H

#define M 1024  // número de encaixes da tabela de hashing
#define NUM_BITS 16
#define MAX_DEF 255
#define MAX_WORD 30

#include <stdbool.h>

// Definição da estrutura de dados
typedef struct {
    char nome[MAX_DEF + 1];
    char coberturaVacinal[MAX_DEF + 1];
    char codigo[MAX_DEF + 1];
    int cont;
} avl_info;

typedef struct avl_no * avl_tree;

struct avl_no {
    avl_info dado;
    avl_tree esq;
    avl_tree dir;
    int bal; // balanceamento do nó
};

/* ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
 * Imprime a árvore AVL t através de um percurso em ordem.
 */
// void print_tree(avl_tree t);

/* ... */
void print_max_tree(avl_tree t, int n, int * i);

/* ... */
void print_min_tree(avl_tree t, int n, int * i);


/*
 * Verifica se a palavra x já ocorreu na árvore AVL t; 
 * caso afirmativo, seu contador é incrementado; caso contrário, 
 * x é inserida em t e h sinaliza que houve um aumento da
 * altura de t.
 */
void avl_search(avl_tree *, char *, char *, char *, bool *);


/* 
 * Faz uma rotação para a direita na árvore AVL t. 
 */
void rotacao_dir(avl_tree * t);


/*
 * Faz uma rotação para a esquerda na árvore AVL t.
 */
void rotacao_esq(avl_tree *);

/* ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
 * Se a palavra x está contida na árvore AVL t, x é
 * removida de t, h sinaliza uma diminuição da altura
 * de t e a função devolve verdadeiro; caso contrário,
 * nada é feito e a função devolve falso.
 */
// bool delete(avl_tree * t, char * x, bool * h);


/*
 * Faz o balanceamento da árvore AVL t após uma remoção 
 * em sua subárvore esquerda e sinaliza se houve uma 
 * dimuição da altura dessa subárvore através de h.
 */
void balance_esq(avl_tree * t, bool * h);


/*
 * Faz o balanceamento da árvore AVL t após uma remoção 
 * em sua subárvore direita e sinaliza se houve uma 
 * dimuição da altura dessa subárvore através de h.
 */
void balance_dir(avl_tree *, bool *);

/*
 * Devolve um ponteiro para o nó que contém o menor
 * valor na árvore AVL t e sinaliza através de h se 
 * houve uma diminuição da altura de t.
 */
avl_tree get_min(avl_tree * t, bool * h);

/*
 * Devolve um ponteiro para o nó que contém o maior
 * valor na árvore AVL t e sinaliza através de h se 
 * houve uma diminuição da altura de t.
 */
avl_tree get_max(avl_tree * t, bool * h);

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
//int profundidade(avl_tree);

#endif
