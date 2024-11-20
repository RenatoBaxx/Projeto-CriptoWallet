#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

void trim(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (isspace((unsigned char)str[start])) start++;
    while (end >= start && isspace((unsigned char)str[end])) end--;

    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

void consultarExtrato() {
    char cpf[12];
    printf("Digite o CPF (somente números): ");
    scanf("%s", cpf);

    FILE *file = fopen("extrato.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        return;
    } else {
        printf("\nExtrato de operações para o CPF: %s\n", cpf);
        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);

            char fileCpf[12]; 
            char *token = strtok(line, " | ");

            if (token != NULL) {
                strncpy(fileCpf, token, sizeof(fileCpf));
                fileCpf[11] = '\0'; 

                trim(fileCpf);

                printf("CPF do arquivo: %s\n", fileCpf);

                if (strcmp(cpf, fileCpf) == 0) { CPF no arquivo
                    printf("Operação encontrada: %s", line);
                    found = 1;
                }
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
            return; 
        } else if (escolha == 2) {
            printf("Saindo...\n");
            return; 
        } else {
            printf("Opção inválida! Por favor, escolha uma opção válida.\n");
        }
    } while (1);
}

int main() {
    consultarExtrato();
    return 0;
}
