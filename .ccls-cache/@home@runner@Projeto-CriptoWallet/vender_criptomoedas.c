#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern float saldoReais;
extern double saldoBitcoin;
extern double saldoEthereum;
extern double saldoXRP;

#define PRECO_BITCOIN 50000.00
#define PRECO_ETHEREUM 3000.00
#define PRECO_RIPPLE 5.00

void venderCriptomoedas(char *cpf) {
  char moeda[10];
  double quantidade;
  double valorVenda;
  float taxa = 0;

  printf("-----------------------------------\n");
  printf("Digite qual moeda gostaria de vender: Bitcoin, Ethereum ou Ripple\n");
  scanf("%s", moeda);

  printf("Digite a quantidade que deseja vender:\n");
  scanf("%lf", &quantidade);

  if (strcmp(moeda, "Bitcoin") == 0) {
    if (quantidade > saldoBitcoin) {
      printf("Saldo insuficiente de Bitcoin! Saldo disponível: %.4f\n",
             saldoBitcoin);
      return;
    }
    taxa = 0.02;
    valorVenda = quantidade * PRECO_BITCOIN;
  } else if (strcmp(moeda, "Ethereum") == 0) {
    if (quantidade > saldoEthereum) {
      printf("Saldo insuficiente de Ethereum! Saldo disponível: %.4f\n",
             saldoEthereum);
      return;
    }
    taxa = 0.01;
    valorVenda = quantidade * PRECO_ETHEREUM;
  } else if (strcmp(moeda, "Ripple") == 0) {
    if (quantidade > saldoXRP) {
      printf("Saldo insuficiente de Ripple! Saldo disponível: %.4f\n",
             saldoXRP);
      return;
    }
    taxa = 0.01;
    valorVenda = quantidade * PRECO_RIPPLE;
  } else {
    printf("Moeda não suportada.\n");
    return;
  }

  double valorTaxa = valorVenda * taxa;
  double valorFinal = valorVenda - valorTaxa;

  if (strcmp(moeda, "Bitcoin") == 0) {
    saldoBitcoin -= quantidade;
  } else if (strcmp(moeda, "Ethereum") == 0) {
    saldoEthereum -= quantidade;
  } else if (strcmp(moeda, "Ripple") == 0) {
    saldoXRP -= quantidade;
  }

  saldoReais += valorFinal;

  printf("Você escolheu vender %s.\n", moeda);
  printf("Quantidade vendida: %.4f %s\n", quantidade, moeda);
  printf("Valor de venda: R$ %.2f\n", valorVenda);
  printf("Taxa aplicada: %.2f%%\n", taxa * 100);
  printf("Valor final após taxa: R$ %.2f\n", valorFinal);
}
