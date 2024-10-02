#include <stdio.h>
#include <stdlib.h>

void consultarExtrato(char *cpf) {
  FILE *file = fopen("extrato.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo de extrato.\n");
  } else {
    printf("\nExtrato de operações para o CPF: %s\n", cpf);
    char line[256];
    int found = 0; // Flag para verificar se há registros para o CPF

    while (fgets(line, sizeof(line), file)) {
      if (strstr(line, cpf)) { // Verifica se o CPF está na linha
        printf("%s", line);
        found = 1;
      }
    }

    if (!found) {
      printf("Nenhuma operação encontrada para o CPF: %s\n", cpf);
    }

    fclose(file);
  }

  int escolha;
  do {
    printf("\n1. Voltar ao menu\n2. Sair\nEscolha uma opção: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
      return; // Volta para o menu
    } else if (escolha == 2) {
      printf("Saindo...\n");
      exit(0);
    } else {
      printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }
  } while (1);
}
