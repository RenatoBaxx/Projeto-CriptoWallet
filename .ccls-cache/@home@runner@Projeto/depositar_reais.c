#include <stdio.h>
#include <time.h>

extern float saldoReais;

void salvarTransacao(const char* cpf, const char* operacao, float valor) {
    FILE *file = fopen("extrato.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de extrato para gravação.\n");
        return;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "CPF: %s | Operação: %s | Valor: %.2f | Data: %02d/%02d/%d %02d:%02d:%02d\n", 
            cpf, operacao, valor, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(file);
}

void depositarReais(char* cpf) {
    float valor;
    printf("Digite o valor a ser depositado (positivo): ");
    scanf("%f", &valor);

    if (valor > 0) {
        saldoReais += valor;
        printf("\nDepósito realizado com sucesso!\n");
        printf("Saldo atualizado: %.2f\n", saldoReais);
        salvarTransacao(cpf, "Depósito", valor);  
    } else {
        printf("Valor inválido! Tente novamente.\n");
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


