#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INVESTIDORES 100
#define MAX_CRYPTOS 10

typedef struct {
    char nome[20];
    double saldo;
} CriptoSaldo;

typedef struct {
    char cpf[12];
    float saldoReais;
    int numCriptos;
    CriptoSaldo criptos[MAX_CRYPTOS];
} Investidor;

int carregarDadosInvestidores(Investidor investidores[], const char *caminhoArquivo = "usuarios.txt";) {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (fscanf(arquivo, "%11s %f %d", 
                  investidores[count].cpf, 
                  &investidores[count].saldoReais, 
                  &investidores[count].numCriptos) == 3) {
        for (int j = 0; j < investidores[count].numCriptos; j++) {
            fscanf(arquivo, "%19s %lf", 
                   investidores[count].criptos[j].nome, 
                   &investidores[count].criptos[j].saldo);
        }
        count++;
        if (count >= MAX_INVESTIDORES) {
            break;
        }
    }

    fclose(arquivo);
    return count;
}

void consultarSaldo(Investidor investidores[], int totalInvestidores) {
    char cpfBusca[12];
    int encontrado = 0;

    printf("Digite o CPF do investidor (apenas números): ");
    scanf("%11s", cpfBusca);

    for (int i = 0; i < totalInvestidores; i++) {
        if (strcmp(investidores[i].cpf, cpfBusca) == 0) {
            printf("\nCPF: %s\n", investidores[i].cpf);
            printf("Saldo em Real: %.2f\n", investidores[i].saldoReais);
            for (int j = 0; j < investidores[i].numCriptos; j++) {
                printf("Saldo em %s: %f\n", investidores[i].criptos[j].nome, investidores[i].criptos[j].saldo);
            }
            encontrado = 1;

            int escolha;
            do {
                printf("\n1. Voltar ao menu\n2. Sair\nEscolha uma opção: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    return;
                } else if (escolha == 2) {
                    printf("Saindo...\n");
                    exit(0);
                } else {
                    printf("Opção inválida! Por favor, escolha uma opção válida.\n");
                }
            } while (1);
        }
    }

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado.\n", cpfBusca);
    }
}

int main() {
    Investidor investidores[MAX_INVESTIDORES];
    int totalInvestidores = carregarDadosInvestidores(investidores, "usuarios.txt");

    if (totalInvestidores > 0) {
        consultarSaldo(investidores, totalInvestidores);
    } else {
        printf("Nenhum dado de investidor foi carregado.\n");
    }

    return 0;
}
