
#include "est_lista_dupla_din.h"  // Inclui o cabeçalho da lista duplamente encadeada

/**
 * @brief Função principal do programa
 */
int main(){
    tipo_no_lista *lista = NULL;  // Ponteiro para a lista inicializado como NULL
    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios
    clock_t inicio , fim;  // Variáveis para medir o tempo de execução
    int contador = 0;  // Contador para o número de elementos na lista
    double tempo_de_cpu;  // Variável para armazenar o tempo de CPU utilizado

    inicio = clock();  // Marca o início da medição do tempo

    /**
     * @brief Insere 3333 elementos no início da lista
     */
    for(int i =0; i<3333;i++){
        int aleatorio = rand() %10000;  // Gera um número aleatório entre 0 e 9999
        insereInicioLst(&lista, aleatorio);  // Insere o número no início da lista
        contador++;  // Incrementa o contador
    }

    /**
     * @brief Insere 3333 elementos no fim da lista
     */
    for(int j = 0; j<3333;j++){
        int aleatorio = rand()%10000;  // Gera um número aleatório entre 0 e 9999
        insereFimLst(&lista, aleatorio);  // Insere o número no fim da lista
        contador++;  // Incrementa o contador
    }

    /**
     * @brief Insere 3334 elementos em posições aleatórias da lista
     */
    for(int k =0; k<3334; k++){
        int aleatorio = rand()%10000;  // Gera um número aleatório entre 0 e 9999
        inserePosLst(&lista, aleatorio, (rand() % contador+1));  // Insere o número em uma posição aleatória da lista
    }

    int num_lista = contaNosLst(lista);  // Conta o número de nós na lista
    size_t tamanho_no = sizeof(tipo_no_lista);  // Obtém o tamanho de um nó da lista
    int memoria_total = tamanho_no *num_lista;  // Calcula a memória total utilizada pela lista

    fim = clock();  // Marca o fim da medição do tempo
    tempo_de_cpu = ((double)(fim-inicio))/CLOCKS_PER_SEC;  // Calcula o tempo de CPU utilizado

    // Exibe o tempo de CPU utilizado, o número de nós criados e a memória utilizada
    printf("tempo de cpu usado na estrutura: %f\nestruturas criadas: %d\nMemoria utilizada: %d bytes.\n", tempo_de_cpu, num_lista, memoria_total);

    liberaLista(&lista);  // Libera a memória alocada para a lista
    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
