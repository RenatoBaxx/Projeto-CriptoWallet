#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define USER_DATA_FILE "usuarios.txt"

typedef struct {
    char cpf[12];
    char senha[20];
    float saldo_real;
    float saldo_btc;
    float saldo_eth;
    float saldo_xrp;
} Usuario;

void exibirMenu(); 

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

void cadastrarUsuario() {
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

    fprintf(file, "%s %s %.2f %.2f %.2f %.2f\n", 
            novo_usuario.cpf, 
            novo_usuario.senha, 
            novo_usuario.saldo_real, 
            novo_usuario.saldo_btc, 
            novo_usuario.saldo_eth, 
            novo_usuario.saldo_xrp);

    fclose(file);
    printf("Cadastro realizado com sucesso!\n");
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

    while (fscanf(file, "%s %s %f %f %f %f", 
                  usuario.cpf, 
                  usuario.senha, 
                  &usuario.saldo_real, 
                  &usuario.saldo_btc, 
                  &usuario.saldo_eth, 
                  &usuario.saldo_xrp) == 6) {
        if (strcmp(usuario.cpf, cpf) == 0 && strcmp(usuario.senha, senha) == 0) {
            fclose(file);
            printf("Login bem-sucedido!\n");
            exibirMenu(cpf);
            return 1;
        }
    }

    fclose(file);
    printf("CPF ou senha incorretos.\n");
    return 0;
}

int main() {
    int escolha;

    do {
        printf("1. Cadastrar\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                loginUsuario();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}
