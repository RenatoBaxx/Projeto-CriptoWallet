#include <stdio.h>
#include <stdlib.h>


void consultarSaldo(char *cpf);
void consultarExtrato(char *cpf);
void depositarReais(char *cpf);
void sacar(char *cpf);
void comprarCriptomoedas(char *cpf);
void venderCriptomoedas(char *cpf);


void cadastrarCriptomoeda(); 
void excluirCriptomoeda();   


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
        printf("7. Cadastrar Criptomoeda\n"); 
        printf("8. Excluir Criptomoeda\n");   
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        
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
                break;
            case 7:
                cadastrarCriptomoeda(); 
                break;
            case 8:
                excluirCriptomoeda();  
                break;
            case 9:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (1);
}
