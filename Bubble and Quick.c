#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[51];
    int prioridade;
    int tempo;
} Prato;

int carregar_dados(const char *arquivo, Prato **pratos) {
    FILE *file = fopen(arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    printf("Lendo dados do arquivo: %s...\n", arquivo);

    int tamanho = 0, capacidade = 100;
    *pratos = (Prato *)malloc(capacidade * sizeof(Prato));

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        if (sscanf(linha, "%d,%d,%50[^\n]", &(*pratos)[tamanho].prioridade,
                   &(*pratos)[tamanho].tempo,
                   (*pratos)[tamanho].nome) == 3) {
            tamanho++;
            if (tamanho == capacidade) {
                capacidade *= 2;
                *pratos = (Prato *)realloc(*pratos, capacidade * sizeof(Prato));
            }
        }
    }

    fclose(file);
    printf("Leitura concluída. Total de pratos: %d\n", tamanho);
    return tamanho;
}

int comparar_pratos(const Prato *a, const Prato *b) {
    if (a->prioridade != b->prioridade)
        return b->prioridade - a->prioridade;
    return a->tempo - b->tempo;
}

// Bubble Sort
void bubble_sort(Prato *pratos, int n) {
    printf("Iniciando Bubble Sort...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar_pratos(&pratos[j], &pratos[j + 1]) > 0) {
                Prato temp = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = temp;
            }
        }
    }
    printf("Bubble Sort concluído.\n");
}

// Quicksort
void quicksort(Prato *pratos, int baixo, int alto) {
    if (baixo < alto) {
        Prato pivo = pratos[alto];
        int i = baixo - 1;
        for (int j = baixo; j < alto; j++) {
            if (comparar_pratos(&pratos[j], &pivo) <= 0) {
                i++;
                Prato temp = pratos[i];
                pratos[i] = pratos[j];
                pratos[j] = temp;
            }
        }
        Prato temp = pratos[i + 1];
        pratos[i + 1] = pratos[alto];
        pratos[alto] = temp;

        int indice_pivo = i + 1;
        quicksort(pratos, baixo, indice_pivo - 1);
        quicksort(pratos, indice_pivo + 1, alto);
    }
}

void salvar_dados(const char *arquivo, Prato *pratos, int n) {
    printf("Salvando dados no arquivo: %s...\n", arquivo);
    FILE *file = fopen(arquivo, "w");
    if (!file) {
        perror("Erro ao salvar o arquivo");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d,%d,%s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }
    fclose(file);
    printf("Dados salvos com sucesso.\n");
}

int main() {
    const char *arquivo_entrada = "pratos_bubble.csv";
    const char *arquivo_saida_bubble = "ordenados_bubble.csv";
    const char *arquivo_saida_quick = "ordenados_quick.csv";

    Prato *pratos;
    printf("Carregando dados...\n");
    int n = carregar_dados(arquivo_entrada, &pratos);
    if (n == 0) {
        return 1;
    }

    Prato *copia_pratos = (Prato *)malloc(n * sizeof(Prato));
    memcpy(copia_pratos, pratos, n * sizeof(Prato));

    // Bubble Sort
    clock_t inicio_bubble = clock();
    bubble_sort(pratos, n);
    clock_t fim_bubble = clock();
    double tempo_bubble = (double)(fim_bubble - inicio_bubble) / CLOCKS_PER_SEC;

    salvar_dados(arquivo_saida_bubble, pratos, n);
    printf("Bubble Sort concluído em %.6f segundos.\n", tempo_bubble);

    // Quicksort
    clock_t inicio_quick = clock();
    printf("Iniciando Quicksort...\n");
    quicksort(copia_pratos, 0, n - 1);
    clock_t fim_quick = clock();
    double tempo_quick = (double)(fim_quick - inicio_quick) / CLOCKS_PER_SEC;

    salvar_dados(arquivo_saida_quick, copia_pratos, n);
    printf("Quicksort concluído em %.6f segundos.\n", tempo_quick);

    free(pratos);
    free(copia_pratos);

    printf("Execução finalizada.\n");
    return 0;
}
