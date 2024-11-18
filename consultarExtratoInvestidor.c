#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACOES 100

typedef struct {
    char cpf[12];
    char descricao[100];
    float valor;
    char data[11];
} Transacao;

int carregarTransacoes(Transacao transacoes[], const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", caminhoArquivo);
        return 0;
    }

    int count = 0;
    while (fscanf(arquivo, "%11s %99[^"] %f %10s", 
                  transacoes[count].cpf, 
                  transacoes[count].descricao, 
                  &transacoes[count].valor, 
                  transacoes[count].data) == 4) {
        count++;
        if (count >= MAX_TRANSACOES) {
            break;
        }
    }

    fclose(arquivo);
    return count;
}

void consultarExtrato(Transacao transacoes[], int totalTransacoes) {
    char cpfBusca[12];
    int encontrado = 0;

    printf("Digite o CPF do investidor (apenas números): ");
    scanf("%11s", cpfBusca);

    printf("\nExtrato de transações para o CPF: %s\n", cpfBusca);
    printf("----------------------------------------\n");

    for (int i = 0; i < totalTransacoes; i++) {
        if (strcmp(transacoes[i].cpf, cpfBusca) == 0) {
            printf("Data: %s | Descrição: %s | Valor: %.2f\n", 
                   transacoes[i].data, 
                   transacoes[i].descricao, 
                   transacoes[i].valor);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhuma transação encontrada para o CPF %s.\n", cpfBusca);
    }

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

int main() {
    Transacao transacoes[MAX_TRANSACOES];
    int totalTransacoes = carregarTransacoes(transacoes, "extrato.txt");

    if (totalTransacoes > 0) {
        consultarExtrato(transacoes, totalTransacoes);
    } else {
        printf("Nenhum dado de transação foi carregado.\n");
    }

    return 0;
}
