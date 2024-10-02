#include <stdio.h>

// Definindo os saldos
float saldoReais = 0.00;
double saldoBitcoin = 0.00;
double saldoEthereum = 0.00;
double saldoXRP = 0.00;

// Função para exibir o saldo
void consultarSaldo(char *cpf) {
  printf("\nCPF: %s\n", cpf);
  printf("Saldo em Real: %.2f\n", saldoReais);
  printf("Saldo em Bitcoin: %f\n", saldoBitcoin);
  printf("Saldo em Ethereum: %f\n", saldoEthereum);
  printf("Saldo em XRP: %f\n", saldoXRP);

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
