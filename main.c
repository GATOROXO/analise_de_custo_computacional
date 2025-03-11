/**
 * @file main.c
 * @author Vitoria Calonga
 * @brief análise de custo computacional - lista encadeada simples
 * @version 0.1
 * @date 2025-03-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "lista.h"
#include <time.h>

int main(){
    tipo_no_lista *lista = NULL;
    int pos, contpos;
    srand(time(NULL));
    clock_t inicio, fim;
    
    inicio = clock();
    double tempo ;

    for(int i = 0; i < 3333; i++){
        insereInicioLst(&lista, rand() % 10000);
    }
    for(int i = 0; i < 3333; i++){
        insereFimLst(&lista, rand() % 10000);
    }
    for(int i = 0; i < 3334; i++){
        contpos = (3333*2) + i;
        pos = rand() % (contpos +1);
        inserePosLst(&lista, pos, rand() % 10000);
    }

    int qtdnoh = contaNosLst(lista);
    size_t tamanho_no = sizeof(tipo_no_lista);
    int memoria_total;
    memoria_total = tamanho_no * qtdnoh;

    fim = clock();
    
    tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    printf("Tempo de cpu usado na estrutura: %f\nMemoria utilizada: %d bytes.\n", tempo, memoria_total);

    return 0;
}