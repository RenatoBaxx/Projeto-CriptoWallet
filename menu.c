#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void exibirMenu() {
  int escolha;

  do {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Investidor\n");
    printf("2. Cadastrar Criptomoeda\n");
    printf("3. Excluir Criptomoeda\n");
    printf("4. Consultar Saldo do Investidor\n");
    printf("5. Consultar Extrato do Investidor\n");
    printf("6. Atualizar Cotação\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      CadastrarInvestidor();
      break;
    case 2:
      cadastrarCriptomoeda();
      break;
    case 3:
      excluirCriptomoeda();
      break;
    case 4:
      ConsultarSaldo();
      break;
    case 5:
      ConsultarExtrato();
      break;
    case 6:
      AtualizarCotacao();
      break;
    case 7:
      printf("Saindo...\n");
      exit(0);
    default:
      printf("Opção inválida! Por favor, escolha uma opção válida.\n");
      break;
    }
  } while (1);
}

int main() {
    if (loginUsuario()) {
        exibirMenu();
    } else {
        printf("Falha no login. Encerrando o programa.\n");
    }
    return 0;
}
// salve

