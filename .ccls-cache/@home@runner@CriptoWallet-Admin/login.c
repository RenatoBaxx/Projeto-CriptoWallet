#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_DATA_FILE "admin.txt"

typedef struct {
  char cpf[12];
  char senha[20];
} Usuario;

int validarCPF(char cpf[]) {
  if (strlen(cpf) != 11) {
    return 0;
  }
  for (int i = 0; i < 11; i++) {
    if (!isdigit(cpf[i])) {
      return 0;
    }
  }
  return 1;
}

int loginUsuario() {
  Usuario usuario;
  char cpf[12], senha[20];
  FILE *file = fopen(USER_DATA_FILE, "r");

  if (!file) {
    printf("Erro ao abrir o arquivo para login.\n");
    return 0;
  }

  printf("Digite o CPF: ");
  scanf("%s", cpf);
  printf("Digite a senha: ");
  scanf("%s", senha);

  while (fscanf(file, "%s %s", usuario.cpf, usuario.senha) == 2) {
    if (strcmp(usuario.cpf, cpf) == 0 && strcmp(usuario.senha, senha) == 0) {
      fclose(file);
      printf("Login bem-sucedido!\n");
      // exibirMenu(cpf);
      return 1;
    }
  }

  fclose(file);
  printf("CPF ou senha incorretos.\n");
  return 0;
}