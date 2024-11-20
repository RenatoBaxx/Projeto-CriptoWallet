#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float cotacaoInicial;
    float taxaCompra;
    float taxaVenda;
} Criptomoeda;

void excluirCriptomoeda() {
    char nome[50];
    int encontrado = 0;
    Criptomoeda cripto;
    FILE *arquivo, *temp;

    printf("\n--- Excluir Criptomoeda ---\n");
    printf("Nome da criptomoeda a excluir: ");
    scanf(" %[^\n]", nome);

    arquivo = fopen("criptomoedas.txt", "r");
    temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fscanf(arquivo, "%s %f %f %f", cripto.nome, &cripto.cotacaoInicial, &cripto.taxaCompra, &cripto.taxaVenda) != EOF) {
        if (strcmp(cripto.nome, nome) == 0) {
            encontrado = 1;
            printf("Criptomoeda encontrada:\n");
            printf("Nome: %s\nCotação: %.2f\nTaxa de Compra: %.2f%%\nTaxa de Venda: %.2f%%\n", cripto.nome, cripto.cotacaoInicial, cripto.taxaCompra, cripto.taxaVenda);
            printf("Deseja realmente excluir? (1-Sim / 0-Não): ");
            int confirmar;
            scanf("%d", &confirmar);
            if (confirmar != 1) {
                fprintf(temp, "%s %.2f %.2f %.2f\n", cripto.nome, cripto.cotacaoInicial, cripto.taxaCompra, cripto.taxaVenda);
            }
        } else {
            fprintf(temp, "%s %.2f %.2f %.2f\n", cripto.nome, cripto.cotacaoInicial, cripto.taxaCompra, cripto.taxaVenda);
        }
    }
    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("criptomoedas.txt");
        rename("temp.txt", "criptomoedas.txt");
        printf("Criptomoeda excluída com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Criptomoeda não encontrada.\n");
    }
}
//salve