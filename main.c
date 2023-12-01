#include "funcoes.c"

int main()
{

    Conta contas[MAX_CONTAS];
    int totalContas = 0;
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
            inserirConta(contas, &totalContas);
            break;
        case 2:
            abrirMenuDeAlteracao(contas, totalContas);
            break;
        case 3:
            procurarConta(contas, totalContas);
            break;
        case 4:
            listar(contas, totalContas);
            break;
        case 5:
            depositar(contas, totalContas);
            break;
        case 6:
            sacar(contas, totalContas);
            break;
        case 7:
            imprimir(contas, totalContas);
            break;
        case 8:
            saldoGeral(contas, totalContas);
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