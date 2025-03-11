#include "lista.h"

/**
 * @brief função que cria(aloca um espaço de memória) um novo noh
 * 
 * @param valor 
 * @return tipo_no_lista* 
 */
tipo_no_lista *alocaNo(int valor) {
    tipo_no_lista *novo_no;

    novo_no = (tipo_no_lista*) malloc(sizeof(tipo_no_lista));
    if (novo_no != NULL) {
        novo_no->valor = valor;
        novo_no->prox = NULL;
    }
    return novo_no;
}


/**
 * @brief função que insere valor no inicio da lista
 * 
 * @param ls 
 * @param valor 
 */
void insereInicioLst(tipo_no_lista **ls, int valor) {
   tipo_no_lista *novo_no;
    novo_no = alocaNo(valor);
    if(novo_no != NULL){
        novo_no->prox = (*ls);
        (*ls) = novo_no;
    }
}


/**
 * @brief insere valor no fim da lista
 * 
 * @param ls 
 * @param valor 
 */
void insereFimLst(tipo_no_lista **ls, int valor){
    if ((*ls) == NULL){ //caso lista esteja vazia
        (*ls) = alocaNo(valor);
    } 
    else { //caso lista não esteja vazia
        tipo_no_lista *aux, *novo_no;

        //aux recebe lista
        aux = (*ls);

        // Posiciona ponteiro aux no ultimo noh
        while (aux->prox != NULL){
            aux = aux->prox;
        }

        // Aloca novo noh e acopla/encadeia ele na estrutura
        novo_no = alocaNo(valor);
        aux->prox = novo_no;
    }
}


/**
 * @brief função que insere em posição específica
 * 
 * @param ls 
 * @param pos 
 * @param valor 
 */
void inserePosLst(tipo_no_lista **ls, int pos, int valor){
    tipo_no_lista *novo_no;
    novo_no = alocaNo(valor);

    if ((*ls) == NULL || pos == 0 ) {
        novo_no->prox = (*ls);
        (*ls) = novo_no;
    } 
    else {
        tipo_no_lista *aux, *ant = NULL;
        int contpos = 0;
        aux = (*ls);
        
        while((aux->prox != NULL) && (contpos < pos)){
           ant = aux;
           aux = aux->prox;
           contpos++;
        }

        if(contpos == pos && aux->prox != NULL){
            novo_no->prox = aux;
            ant->prox = novo_no;
        }
        else{
            aux->prox = novo_no;
        }
        
    }
}


void imprimeLista(tipo_no_lista *ls){
    tipo_no_lista *aux = ls; 
    if(ls == NULL){
        printf("lista vazia/n");
    }
    else{
        printf("Lista ordenada: [");
        while(aux->prox != NULL){
            printf(" %d ", aux->valor);
            aux = aux->prox;
            }
        }
    printf("]\t\n");
}

/**
 * @brief função que conta a quantidade de nós(valores) dentro da lista
 * 
 * @param ls 
 * @return int 
 */
int contaNosLst(tipo_no_lista* ls) {
    int count = 0;
    tipo_no_lista *aux = ls;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

