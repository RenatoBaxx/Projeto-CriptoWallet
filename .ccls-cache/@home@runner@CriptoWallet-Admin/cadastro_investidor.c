#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_DATA_FILE "usuarios.txt"

typedef struct {
  char cpf[12];
  char senha[20];
  float saldo_real;
  float saldo_btc;
  float saldo_eth;
  float saldo_xrp;
} Usuario;


void CadastrarInvestidor() {
  Usuario novo_usuario;
  FILE *file = fopen(USER_DATA_FILE, "a");

  if (!file) {
    printf("Erro ao abrir o arquivo para cadastro.\n");
    return;
  }

  do {
    printf("Digite o CPF (11 números): ");
    scanf("%s", novo_usuario.cpf);
    if (!validarCPF(novo_usuario.cpf)) {
      printf("CPF inválido! O CPF deve conter exatamente 11 números.\n");
    }
  } while (!validarCPF(novo_usuario.cpf));

  printf("Digite a senha: ");
  scanf("%s", novo_usuario.senha);

  novo_usuario.saldo_real = 0.0;
  novo_usuario.saldo_btc = 0.0;
  novo_usuario.saldo_eth = 0.0;
  novo_usuario.saldo_xrp = 0.0;

  fprintf(file, "%s %s %.2f %.2f %.2f %.2f\n", novo_usuario.cpf,
          novo_usuario.senha, novo_usuario.saldo_real, novo_usuario.saldo_btc,
          novo_usuario.saldo_eth, novo_usuario.saldo_xrp);

  fclose(file);
  printf("Cadastro realizado com sucesso!\n");
}
