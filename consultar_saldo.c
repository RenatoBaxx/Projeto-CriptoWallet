#include <stdio.h>

float saldoReais = 0.00;  
float saldoBitcoin = 0.00; 
float saldoEthereum = 0.00; 
float saldoXRP = 0.00;  

void consultarSaldo(char* cpf) {
    printf("\nCPF: %s\n", cpf);
    printf("Saldo em Real: %.2f\n", saldoReais);
    printf("Saldo em Bitcoin: %.2f\n", saldoBitcoin);
    printf("Saldo em Ethereum: %.2f\n", saldoEthereum);
    printf("Saldo em XRP: %.2f\n", saldoXRP);

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