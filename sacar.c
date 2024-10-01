extern float saldoReais;

void sacar(char* cpf) {
    float valor;
    printf("Digite o valor a ser sacado: ");
    scanf("%f", &valor);

    if (valor > 0 && valor <= saldoReais) {
        saldoReais -= valor;
        printf("\nSaque realizado com sucesso!\n");
        printf("Saldo atualizado: %.2f\n", saldoReais);
        salvarTransacao(cpf, "Saque", valor); 
    } else {
        printf("Valor inválido ou saldo insuficiente.\n");
    }

    int escolha;
    do {
            printf("\n1. Voltar ao menu\n2. Sair\nEscolha uma opção: ");
            scanf("%d", &escolha);

            if (escolha == 1) {
                return; 
            } else if (escolha == 2) {
                printf("Saindo...\n");
                exit(0);
            } else {
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
            }
        } while (1);
    }