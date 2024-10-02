#include <stdio.h>
#include <stdlib.h>

// Declaração das funções
void consultarSaldo(char *cpf);
void consultarExtrato(char *cpf);
void depositarReais(char *cpf);
void sacar(char *cpf);
void comprarCriptomoedas(char *cpf);
void venderCriptomoedas(char *cpf);

// Função para exibir o menu
void exibirMenu(char *cpf) {
  int escolha;

  do {
    printf("\n--- Menu ---\n");
    printf("1. Consultar Saldo (Conta)\n");
    printf("2. Consultar Extrato de Operações\n");
    printf("3. Depositar Reais na Carteira\n");
    printf("4. Sacar\n");
    printf("5. Comprar Criptomoedas\n");
    printf("6. Vender Criptomoedas\n");
    printf("7. Atualizar Cotação\n");
    printf("8. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    // Realizando a operação correspondente com base na escolha
    switch (escolha) {
    case 1:
      consultarSaldo(cpf);
      break;
    case 2:
      consultarExtrato(cpf);
      break;
    case 3:
      depositarReais(cpf);
      break;
    case 4:
      sacar(cpf);
      break;
    case 5:
      comprarCriptomoedas(cpf);
      break;
    case 6:
      venderCriptomoedas(cpf);
    break
        case 7:
          venderCriptomoedas(cpf);
          break;
    case 8:
      printf("Saindo...\n");
      exit(0);
    default:
      printf("Opção inválida! Por favor, escolha uma opção válida.\n");
      break;
    }
  } while (1);
}
