#include <stdio.h>

int main()
{

    int opcao;

    do
    {
        puts("==================================================================================================");
        puts("\nMenu:\n");
        puts("1. Inserir nova conta");
        puts("2. Alterar conta");
        puts("3. Procurar conta");
        puts("4. Listar contas");
        puts("5. Realizar deposito");
        puts("6. Realizar saque");
        puts("7. Imprimir dados da conta");
        puts("8. Calcular saldo geral");
        puts("9. Sair\n");

        puts("Escolha uma opcao:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("inserirConta");
            break;
        case 2:
            printf("abrirMenuDeAlteracao");
            break;
        case 3:
            printf("procurarConta");
            break;
        case 4:
            printf("listar");
            break;
        case 5:
            printf("depositar");
            break;
        case 6:
            printf("sacar");
            break;
        case 7:
            printf("imprimir");
            break;
        case 8:
            printf("saldoGeral");
            break;
        case 9:
            puts("Saindo do programa.\n");
            break;
        default:
            puts("Opcao invalida. Tente novamente.\n");
        }
        puts("\n==================================================================================================\n");
    } while (opcao != 9);

    return 0;
}