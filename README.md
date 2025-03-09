**Universidade Federal de Mato Grosso - UFMT**  
**Semestre:** 2024/2  
**Disciplina:** Estrutura de Dados  
**Professor:** Ivairton Monteiro Santos  
**Dupla:**  
- João Paulo Alves Campos  
- Vitoria Calonga  

**Data de Entrega:** 10/03/2025  

---

## Descrição do Projeto
Este projeto tem como objetivo avaliar o desempenho e o uso de memória de três estruturas de dados diferentes:

1. **Lista Estática** com capacidade para armazenar 10.000 registros.
2. **Lista Dinâmica com Encadeamento Simples**.
3. **Lista Dinâmica com Encadeamento Duplo**.

O foco da análise está na comparação dos tempos de inserção e eficiência no uso de memória entre essas estruturas.

---

## Requisitos Implementados

1. **Geração de Dados:**
   - Geração aleatória de 10.000 valores inteiros (podendo haver repetições).
   - Distribuição das inserções conforme segue:
     - ~1/3 dos valores inseridos no início da lista.
     - ~1/3 dos valores inseridos no final da lista.
     - ~1/3 dos valores inseridos em uma posição aleatória da lista.

2. **Medição de Tempo:**
   - Utilização da biblioteca `<times.h>` para medir o tempo de CPU gasto em cada inserção.
   - Inserção dos 10.000 valores em cada estrutura e registro do tempo de processamento.
   - Repetição do experimento 10 vezes para cada estrutura e cálculo do tempo médio de execução.

3. **Análise de Memória:**
   - Avaliação da ocupação de memória de cada estrutura.
   - Comparação da eficiência no uso de memória entre os métodos.
   - Quantificação da memória utilizada em cada contexto.

---

## Estratégia de Implementação

- **Lista Estática:** Utilização de um array fixo de tamanho 10.000 para armazenar os registros.
- **Lista Encadeada Simples:** Implementação de nós alocados dinamicamente contendo um ponteiro para o próximo nó.
- **Lista Duplamente Encadeada:** Implementação de nós com dois ponteiros, um apontando para o próximo e outro para o nó anterior.
- **Medição de Tempo:** Uso da função `times()` da biblioteca `<sys/times.h>` para capturar o tempo de processamento.
- **Medição de Memória:** Uso de ferramentas como `sizeof()` e `malloc_usable_size()` (dependendo da plataforma) para avaliar o consumo de memória.

---

## Resultados Obtidos

Os resultados do tempo de execução para cada estrutura foram armazenados e analisados conforme a tabela abaixo:

| Estrutura                  | Inserções no Início | Inserções no Fim | Inserções Aleatórias | Menor Tempo | Maior Tempo | Tempo Médio |
|----------------------------|--------------------|-----------------|------------------|-------------|-------------|-------------|
| Lista Estática             | 3333               | 3333            | 3334             | XX ms       | XX ms       | XX ms       |
| Lista Encadeada Simples    | 3333               | 3333            | 3334             | XX ms       | XX ms       | XX ms       |
| Lista Duplamente Encadeada | 3333               | 3333            | 3334             | XX ms       | XX ms       | XX ms       |

(Os valores de tempo serão preenchidos após os testes práticos serem realizados.)

---

## Análise de Memória

| Estrutura                  | Memória Utilizada (bytes) | Eficiência de Uso |
|----------------------------|--------------------------|------------------|
| Lista Estática             | XX KB                    | Alta             |
| Lista Encadeada Simples    | XX KB                    | Média            |
| Lista Duplamente Encadeada | XX KB                    | Baixa            |

(Os valores de memória serão preenchidos após os testes práticos serem realizados.)

### Conclusão
- **Desempenho:** A estrutura mais eficiente em termos de tempo de inserção será determinada a partir dos testes.
- **Uso de Memória:** A comparação indicará qual estrutura consome menos memória e apresenta melhor relação custo-benefício.
- **Recomendações:** Baseando-se nos resultados, será sugerida a estrutura mais adequada para diferentes cenários de uso.

---

## Código Fonte
O código-fonte da implementação pode ser encontrado no diretório correspondente do projeto.

---

## Referências
- Documentação da biblioteca `<sys/times.h>`
- Materiais da disciplina de Estrutura de Dados
- Recursos adicionais sobre medição de desempenho em C

---

**João Paulo Alves Campos & Vitoria Calonga**  
**UFMT - 2024/2**

