#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief estrutura do noh da lista
 * 
 */
struct est_no_lista{
   int valor; //Armazena apenas um num. inteiro
   struct est_no_lista *prox;
};
typedef struct est_no_lista tipo_no_lista;

tipo_no_lista *alocaNo(int);

void insereInicioLst(tipo_no_lista**, int);
void insereFimLst(tipo_no_lista**, int);
void inserePosLst(tipo_no_lista**, int, int);
void imprimeLista(tipo_no_lista*);
int contaNosLst(tipo_no_lista*);

#endif