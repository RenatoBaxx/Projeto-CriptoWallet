// usuario.h
#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
  char cpf[12];         // CPF do usuário
  char senha[20];       // Senha do usuário
  float saldo_reais;    // Saldo em Reais
  float saldo_bitcoin;  // Saldo em Bitcoin
  float saldo_ethereum; // Saldo em Ethereum
  float saldo_ripple;   // Saldo em Ripple
} Usuario;

// Função para obter o usuário pelo CPF
Usuario *obterUsuarioPorCpf(const char *cpf);

#endif // USUARIO_H
