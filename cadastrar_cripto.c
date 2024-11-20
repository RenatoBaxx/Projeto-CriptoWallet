#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float cotacaoInicial;
    float taxaCompra;
    float taxaVenda;
} Criptomoeda;

void cadastrarCriptomoeda() {
    Criptomoeda novaCripto;
    FILE *arquivo;

    printf("\n--- Cadastrar Criptomoeda ---\n");
    printf("Nome da criptomoeda: ");
    scanf(" %[^\n]", novaCripto.nome);
    printf("Cotação inicial: ");
    scanf("%f", &novaCripto.cotacaoInicial);
    printf("Taxa de compra (%%): ");
    scanf("%f", &novaCripto.taxaCompra);
    printf("Taxa de venda (%%): ");
    scanf("%f", &novaCripto.taxaVenda);

    arquivo = fopen("criptomoedas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "%s %.2f %.2f %.2f\n", novaCripto.nome, novaCripto.cotacaoInicial, novaCripto.taxaCompra, novaCripto.taxaVenda);
    fclose(arquivo);

    printf("Criptomoeda cadastrada com sucesso!\n");
}
