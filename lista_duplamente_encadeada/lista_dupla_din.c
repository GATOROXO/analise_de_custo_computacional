#include "est_lista_dupla_din.h"

/**
 * @brief Aloca um novo nó para a lista.
 * 
 * @param valor Valor a ser armazenado no nó.
 * @return Ponteiro para o novo nó ou NULL em caso de erro.
 */
tipo_no_lista *alocaNo(int valor) {
    tipo_no_lista* novo_no = (tipo_no_lista*)malloc(sizeof(tipo_no_lista));
    if (novo_no == NULL) {
        printf("[ERRO 1]\n");
        return NULL;
    }
    novo_no->ant = NULL;
    novo_no->prox = NULL;
    novo_no->valor = valor;
    return novo_no;
}

/**
 * @brief Insere um novo nó no início da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param valor Valor a ser inserido no novo nó.
 */
void insereInicioLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista *novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL) {
        *inicio = novo_no;
    } else {
        novo_no->prox = *inicio;
        (*inicio)->ant = novo_no;
        *inicio = novo_no;
    }
}

/**
 * @brief Insere um novo nó no final da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param valor Valor a ser inserido no novo nó.
 */
void insereFimLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista *novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL) {
        *inicio = novo_no;
    } else {
        tipo_no_lista* aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
        novo_no->ant = aux;
    }
}

/**
 * @brief Insere um novo nó em uma posição específica da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param valor Valor a ser inserido no novo nó.
 * @param pos Posição onde o novo nó será inserido.
 */
void inserePosLst(tipo_no_lista** inicio, int valor, int pos) {
    if (pos < 0) return;
    tipo_no_lista* novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL || pos == 0) {
        insereInicioLst(inicio, valor);
        free(novo_no);
        return;
    }
    tipo_no_lista* aux = *inicio;
    int i = 0;
    while (i < pos - 1 && aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }
    novo_no->prox = aux->prox;
    novo_no->ant = aux;
    if (aux->prox != NULL) {
        aux->prox->ant = novo_no;
    }
    aux->prox = novo_no;
}

/**
 * @brief Remove o nó do início da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @return Valor armazenado no nó removido ou -1 em caso de erro.
 */
int removeInicioLst(tipo_no_lista** inicio) {
    if (*inicio == NULL) {
        printf("[ERRO] Lista Vazia.\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    int valor = aux->valor;
    *inicio = aux->prox;
    if (*inicio != NULL) {
        (*inicio)->ant = NULL;
    }
    free(aux);
    return valor;
}

/**
 * @brief Remove o nó do final da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @return Valor armazenado no nó removido ou -1 em caso de erro.
 */
int removeFimLst(tipo_no_lista** inicio) {
    if (*inicio == NULL) {
        printf("Lista Vazia!\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    if (aux->prox == NULL) {
        int valor = aux->valor;
        *inicio = NULL;
        free(aux);
        return valor;
    }
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    int valor = aux->valor;
    aux->ant->prox = NULL;
    free(aux);
    return valor;
}

/**
 * @brief Remove o nó de uma posição específica da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param pos Posição do nó a ser removido.
 * @return Valor armazenado no nó removido ou -1 em caso de erro.
 */
int removePosLst(tipo_no_lista** inicio, int pos) {
    if (*inicio == NULL || pos < 0) {
        printf("Lista vazia ou posição inválida\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    if (pos == 0) {
        return removeInicioLst(inicio);
    }
    int i = 0;
    while (i < pos && aux != NULL) {
        aux = aux->prox;
        i++;
    }
    if (aux == NULL) {
        printf("Posição inexistente\n");
        return -1;
    }
    int valor = aux->valor;
    aux->ant->prox = aux->prox;
    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return valor;
}

/**
 * @brief Remove o nó que contém um valor específico.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 * @param valor Valor do nó a ser removido.
 * @return Valor armazenado no nó removido ou -1 em caso de erro.
 */
int removeValorLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista* aux = buscaValorLst(*inicio, valor);
    if (aux == NULL) {
        printf("Valor não encontrado\n");
        return -1;
    }
    if (aux == *inicio) {
        return removeInicioLst(inicio);
    }
    if (aux->prox == NULL) {
        return removeFimLst(inicio);
    }
    int val = aux->valor;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    return val;
}

/**
 * @brief Busca o nó em uma posição específica da lista.
 * 
 * @param inicio Ponteiro para o início da lista.
 * @param pos Posição do nó a ser buscado.
 * @return Ponteiro para o nó encontrado ou NULL se não existir.
 */
tipo_no_lista *buscaPosLst(tipo_no_lista* inicio, int pos) {
    if (pos < 0) return NULL;
    tipo_no_lista* aux = inicio;
    int i = 0;
    while (aux != NULL && i < pos) {
        aux = aux->prox;
        i++;
    }
    return aux;
}

/**
 * @brief Busca o nó que contém um valor específico na lista.
 * 
 * @param inicio Ponteiro para o início da lista.
 * @param valor Valor a ser buscado.
 * @return Ponteiro para o nó encontrado ou NULL se não existir.
 */
tipo_no_lista *buscaValorLst(tipo_no_lista* inicio, int valor) {
    tipo_no_lista* aux = inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

/**
 * @brief Conta o número de nós na lista.
 * 
 * @param inicio Ponteiro para o início da lista.
 * @return Número de nós na lista.
 */
int contaNosLst(tipo_no_lista* inicio) {
    int count = 0;
    tipo_no_lista* aux = inicio;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

/**
 * @brief Imprime todos os valores dos nós da lista.
 * 
 * @param inicio Ponteiro para o início da lista.
 */
void imprimeLista(tipo_no_lista* inicio) {
    tipo_no_lista* aux = inicio;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

/**
 * @brief Busca e imprime a posição do nó que contém um valor específico.
 * 
 * @param inicio Ponteiro para o início da lista.
 * @param valor Valor a ser buscado.
 */
void buscaEImprimeValorLst(tipo_no_lista* inicio, int valor) {
    tipo_no_lista* no = buscaValorLst(inicio, valor);
    if (no != NULL) {
        printf("Valor encontrado: %d\n", no->valor);
        int pos = 0;
        tipo_no_lista* aux = inicio;
        while (aux != no && aux != NULL) {
            pos++;
            aux = aux->prox;
        }
        if (aux != NULL) {
            printf("Posição encontrada: %d\n", pos);
        }
    } else {
        printf("Valor não encontrado\n");
    }
}

/**
 * @brief Libera a memória de todos os nós da lista.
 * 
 * @param inicio Ponteiro para o ponteiro do início da lista.
 */
void liberaLista(tipo_no_lista** inicio) {
    tipo_no_lista* aux;
    while (*inicio != NULL) {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
    }
}
