/* avl.c
 * Implementação das operações realizadas sobre o TAD que
 * representa uma árvore AVL.
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
 
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* void print_tree(avl_tree t) {
    if (t != NULL) {
        print_tree(t->esq);
        printf("%40s: %d\n", t->dado.coberturaVacinal, t->dado.cont);
        print_tree(t->dir);
    }
} */

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void print_max_tree(avl_tree t, int n, int * i) {
    if (t != NULL) {
        print_max_tree(t->dir, n, i);
        if((*i) == n) return;
        printf("Codigo: %s\n", t->dado.codigo);
        printf("Nome: %s\n", t->dado.nome);
        printf("Cobertura Vacinal: %s\n\n", t->dado.coberturaVacinal);
        (*i)++;
        if((*i) == n) return;
        print_max_tree(t->esq, n, i);
    }
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void print_min_tree(avl_tree t, int n, int * i) {
    if (t != NULL) {
        print_min_tree(t->esq, n, i);
        if((*i) == n) return;
        printf("Codigo: %s\n", t->dado.codigo);
        printf("Nome: %s\n", t->dado.nome);
        printf("Cobertura Vacinal: %s\n\n", t->dado.coberturaVacinal);
        (*i)++;
        if((*i) == n) return;
        print_min_tree(t->dir, n, i);
    }
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void avl_search(avl_tree * t, char * x, char * nome, char * codigo, bool * h) {
    if (*t == NULL) {
        if ((*t = (avl_tree) malloc(sizeof(struct avl_no))) == NULL) {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        *h = true;
        strcpy((*t)->dado.coberturaVacinal,x);
        strcpy((*t)->dado.nome,nome);
        strcpy((*t)->dado.codigo,codigo);
        (*t)->dado.cont = 1;
        (*t)->esq = (*t)->dir = NULL;
        (*t)->bal = 0;
    }
    else if (strlen(x) < strlen((*t)->dado.coberturaVacinal) || (strlen(x) == strlen((*t)->dado.coberturaVacinal) && strcasecmp(x,(*t)->dado.coberturaVacinal) < 0)) { // Inserir a esquerda
        avl_search(&(*t)->esq, x, nome, codigo, h);
        if (*h) { // O ramo esquerdo cresceu
            switch ((*t)->bal) {
                case 1: (*t)->bal = 0;
                        *h = false;
                        break;
                case 0: (*t)->bal = -1;
                        break;
                case -1:
                    // Rebalanceamento
                    if ((*t)->esq->bal == -1) { //Rota��o simples p/ direita
                        rotacao_dir(t);
                        (*t)->dir->bal = 0; //Ajusta o fator de balanceamento
                    }
                    else { // Rota��o dupla para direita
                        rotacao_esq(&(*t)->esq);
                        rotacao_dir(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                    }
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else if (strlen(x) > strlen((*t)->dado.coberturaVacinal) || (strlen(x) == strlen((*t)->dado.coberturaVacinal) && strcasecmp(x,(*t)->dado.coberturaVacinal) > 0)) { // Inserir a direita
        avl_search(&(*t)->dir, x, nome, codigo, h);
        if (*h) { // O ramo direito cresceu
            switch ((*t)->bal) {
                case -1: (*t)->bal = 0;
                         *h = false;
                         break;
                case 0 : (*t)->bal = 1;
                         break;
                case 1: // Rebalanceamento
                    if ((*t)->dir->bal == 1) { // Rota��o simples p/ esquerda
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        (*t)->esq->bal = 0;
                    }
                    else { // Rota��o dupla para esquerda
                        rotacao_dir(&(*t)->dir);
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                    } // fim do else
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else // a coberturaVacinal j� est� na �rvore
        (*t)->dado.cont++;
} // fim de avl_search

/**
 * Descrição: Rotação para a esquerda.
 * Parâmetro(s):
 * Retorno:
 */
void rotacao_esq(avl_tree * t) {
    avl_tree p;
    p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

/**
 * Descrição: Rotação para a direita.
 * Parâmetro(s):
 * Retorno:
 */
void rotacao_dir(avl_tree * t) {
    avl_tree p;
    p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* bool delete(avl_tree * t, char * x, bool * h) {
    avl_tree p;
    bool result;
    if (*t == NULL) // A coberturaVacinal n�o se encontra na �rvore
        return false;
    else if (strcasecmp(x,(*t)->dado.coberturaVacinal) == 0) { // a coberturaVacinal est� neste n�
        p = *t;
        if ((*t)->esq == NULL) { // n� folha ou somente com sub�rvore direita
            *t = p->dir;
            *h = true;
        }
        else if ((*t)->dir == NULL) { // n� com uma �nica sub�rvore esquerda
            *t = p->esq;
            *h = true;
        }
        else { // n� com duas sub�vores
            p = get_min(&(*t)->dir, h);
            (*t)->dado = p->dado;
            if(*h) balance_dir(t, h);
        }
        free(p);
        return true;
    }
    else if (strlen(x) < strlen((*t)->dado.coberturaVacinal) || (strlen(x) == strlen((*t)->dado.coberturaVacinal) && strcasecmp(x,(*t)->dado.coberturaVacinal) < 0)) {
        result = delete(&(*t)->esq, x, h);
        if (*h) balance_esq(t, h);
        return result;
    }
    else {
        result = delete(&(*t)->dir, x, h);
        if (*h) balance_dir(t, h);
        return result;
    }
} // fim do delete
*/

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void balance_dir(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case 1: (*t)->bal = 0;
                break;
        case 0: (*t)->bal = -1;
                *h = false;
                break;
        case -1: // rebalanceamento
                p1 = (*t)->esq;
                b1 = p1->bal;
                if (b1 <= 0) { // rota��o simples
                    (*t)->esq = p1->dir;
                    p1->dir = *t;
                    if (b1 == 0) {
                        (*t)->bal = -1;
                        p1->bal = 1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rota��o dupla
                    p2 = p1->dir;
                    b2 = p2->bal;
                    p1->dir = p2->esq;
                    p2->esq = p1;
                    p1->esq = p2->dir;
                    p2->dir = *t;
                    if(b2 == -1) (*t)->bal = 1;
                    else (*t)->bal = 0;
                    if(b2 == 1) p1->bal = -1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
void balance_esq(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case -1: (*t)->bal = 0;
                 break;
        case 0: (*t)->bal = 1;
                *h = false;
                break;
        case 1: // rebalanceamento
                p1 = (*t)->dir;
                b1 = p1->bal;
                if (b1 >= 0) { // rota��o simples
                    (*t)->dir = p1->esq;
                    p1->esq = *t;
                    if (b1 == 0) {
                        (*t)->bal = 1;
                        p1->bal = -1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rota��o dupla
                    p2 = p1->esq;
                    b2 = p2->bal;
                    p1->esq = p2->dir;
                    p2->dir = p1;
                    p1->dir = p2->esq;
                    p2->esq = *t;
                    if (b2 == 1) (*t)->bal = -1;
                    else (*t)->bal = 0;
                    if (b2 == -1) p1->bal = 1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
avl_tree get_min(avl_tree * t, bool * h) {
    avl_tree q;
    if ((*t)->esq != NULL) {
        q = get_min(&((*t)->esq),h);
        if (*h) balance_esq(t, h);
        return q;
    }
    else {
        *h = true;
        q = *t;
        *t = (*t)->dir;
        return q;
    }
}

/**
 * Descrição: 
 * Parâmetro(s):
 * Retorno:
 */
avl_tree get_max(avl_tree * t, bool * h) {
    avl_tree q;
    if ((*t)->dir != NULL) {
        q = get_max(&((*t)->dir),h);
        if (*h) balance_dir(t, h);
        return q;
    }
    else {
        *h = true;
        q = *t;
        *t = (*t)->esq;
        return q;
    }
}

// ESTA FUNÇÃO NÃO ESTÁ SENDO UTILIZADA
/* int profundidade(avl_tree t) {
	if (t->esq == NULL && t->dir == NULL) {
		return 0;	
	}
	int e = 0, d = 0;
	if (t->esq != NULL) {
		e = profundidade(t->esq);
	}
	if (t->dir != NULL) {
		d = profundidade(t->dir);
	}
	return 1 + (e > d ? e : d);
} */
