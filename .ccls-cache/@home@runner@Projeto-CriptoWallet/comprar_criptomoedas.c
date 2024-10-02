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

void comprarCriptomoedas() {
  char moeda[10];
  float valorCompra, valorFinal, quantidade;
  float taxa = 0;

  printf("-----------------------------------\n");
  printf(
      "Digite qual moeda gostaria de comprar: Bitcoin, Ethereum ou Ripple\n");
  scanf("%s", moeda);

  printf("Digite o valor em reais que deseja investir:\n");
  scanf("%f", &valorCompra);

  if (strcmp(moeda, "Bitcoin") == 0) {
    taxa = 0.02;
    quantidade = valorCompra / PRECO_BITCOIN;
  } else if (strcmp(moeda, "Ethereum") == 0) {
    taxa = 0.01;
    quantidade = valorCompra / PRECO_ETHEREUM;
  } else if (strcmp(moeda, "Ripple") == 0) {
    taxa = 0.01;
    quantidade = valorCompra / PRECO_RIPPLE;
  } else {
    printf("Moeda não suportada.\n");
    return;
  }

  float valorTaxa = valorCompra * taxa;
  valorFinal = valorCompra + valorTaxa;

  if (saldoReais < valorFinal) {
    printf("Saldo insuficiente! Saldo disponível: R$ %.2f\n", saldoReais);
    return;
  }

  saldoReais -= valorFinal;

  if (strcmp(moeda, "Bitcoin") == 0) {
    saldoBitcoin += quantidade;
  } else if (strcmp(moeda, "Ethereum") == 0) {
    saldoEthereum += quantidade;
  } else if (strcmp(moeda, "Ripple") == 0) {
    saldoXRP += quantidade;
  }

  printf("Você escolheu comprar %s.\n", moeda);
  printf("Valor da compra: R$ %.2f\n", valorCompra);
  printf("Taxa aplicada: %.2f%%\n", taxa * 100);
  printf("Valor final com taxa: R$ %.2f\n", valorFinal);
  printf("Quantidade adquirida: %.4f %s\n", quantidade, moeda);
}
