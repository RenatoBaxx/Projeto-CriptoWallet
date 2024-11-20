#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define MAX_INVESTIDORES 100
#define MAX_CRYPTOS 10
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float cotacaoInicial;
    float taxaCompra;
    float taxaVenda;
} Criptomoeda;

typedef struct {
    char cpf[12];
    float saldoReais;
    float saldoCriptos[MAX_CRYPTOS];
} Investidor;

int carregarCriptomoedas(Criptomoeda criptos[], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (fscanf(arquivo, "%s %f %f %f", 
                  criptos[count].nome, 
                  &criptos[count].cotacaoInicial, 
                  &criptos[count].taxaCompra, 
                  &criptos[count].taxaVenda) == 4) {
        count++;
        if (count >= MAX_CRYPTOS) {
            break;
        }
    }

    fclose(arquivo);
    return count;
}

int carregarDadosInvestidores(Investidor investidores[], const char *nomeArquivo, Criptomoeda criptos[], int totalCriptos) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (fscanf(arquivo, "%11s %f", 
                  investidores[count].cpf, 
                  &investidores[count].saldoReais) == 2) {

        for (int i = 0; i < totalCriptos; i++) {
            if (fscanf(arquivo, "%f", &investidores[count].saldoCriptos[i]) != 1) {
                break; 
            }
        }

        count++;
        if (count >= MAX_INVESTIDORES) {
            break;
        }
    }

    fclose(arquivo);
    return count;
}

void exibirSaldo(Investidor investidores[], int totalInvestidores, Criptomoeda criptos[], int totalCriptos) {
    char cpfBusca[12];
    int encontrado;

    do {
        encontrado = 0;
        printf("\nDigite o CPF do investidor: ");
        scanf("%11s", cpfBusca);

        for (int i = 0; i < totalInvestidores; i++) {
            if (strcmp(investidores[i].cpf, cpfBusca) == 0) {
                printf("\nInvestidor encontrado! Exibindo dados...\n");
                printf("CPF: %s\n", investidores[i].cpf);
                printf("Saldo em reais: %.2f\n", investidores[i].saldoReais);

                for (int j = 0; j < totalCriptos; j++) {
                    if (investidores[i].saldoCriptos[j] > 0) {
                        printf("Saldo em %s: %.2f\n", criptos[j].nome, investidores[i].saldoCriptos[j]);
                    }
                }
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("\nInvestidor com CPF %s não encontrado.\n", cpfBusca);
        }

        int escolha;
        do {
            printf("\n1. Ver outro investidor\n2. Voltar ao menu\n3. Sair\nEscolha uma opção: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    break; 
                case 2:
                    exibirMenu();
                    return; 
                case 3:
                    printf("Saindo...\n");
                    exit(0);
                default:
                    printf("Opção inválida! Por favor, escolha uma opção válida.\n");
            }

            if (escolha == 1) {
                break; 
            }
        } while (escolha != 2 && escolha != 3); 

    } while (1); 
}

int main() {
    Investidor investidores[MAX_INVESTIDORES];
    Criptomoeda criptos[MAX_CRYPTOS];

    int totalCriptos = carregarCriptomoedas(criptos, "criptomoedas.txt");
    int totalInvestidores = carregarDadosInvestidores(investidores, "usuarios.txt", criptos, totalCriptos);

    if (totalInvestidores > 0 && totalCriptos > 0) {
        exibirSaldo(investidores, totalInvestidores, criptos, totalCriptos); 
    } else {
        printf("Nenhum dado de investidor ou criptomoeda foi carregado.\n");
    }

    return 0;
}
