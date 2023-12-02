#include "funcoes.c" /*Inclue a biblioteca funcoes*/

int main()
{

    Conta contas[MAX_CONTAS]; /*cria uma variavel do tipo Conta*/
    int totalContas = 0; /*cria uma variavel do tipo inteiro que mostrara a quantidade de contas*/
    int opcao = 0; /*cria uma variavel do tipo inteiro que sera usado no menu*/

    do/*cria uma loop que so termina quando o usuario digitar "9"*/
    {   
        /*Inicio do Menu*/
        puts("==================================================================================================");
        puts("\nMenu:\n");
        puts("1. Criar uma nova conta");
        puts("2. Alterar conta");
        puts("3. Procurar conta");
        puts("4. Listar contas");
        puts("5. Realizar deposito");
        puts("6. Realizar saque");
        puts("7. Imprimir dados da conta");
        puts("8. Calcular saldo geral");
        puts("9. Sair\n");

        puts("Escolha uma opcao:");
        scanf("%d", &opcao); /*Pega o que numero que o usuario digitou*/

        switch (opcao)
        {
        case 1:
            criarConta(contas, totalContas); /*Chama a funcao criarConta passando contas e totalContas para a funcao por parametro*/
            break;
        case 2:
            abrirMenuDeAlteracao(contas, totalContas);/*Chama a funcao abrirMenuDeAlteracao passando contas e totalContas para a funcao por parametro*/
            break;
        case 3:
            procurarConta(contas, totalContas);/*Chama a funcao procurarConta passando contas e totalContas para a funcao por parametro*/
            break;
        case 4:
            listar(contas, totalContas);/*Chama a funcao listar passando contas e totalContas para a funcao por parametro*/
            break;
        case 5:
            depositar(contas, totalContas);/*Chama a funcao depositar passando contas e totalContas para a funcao por parametro*/
            break;
        case 6:
            sacar(contas, totalContas);/*Chama a funcao sacar passando contas e totalContas para a funcao por parametro*/
            break;
        case 7:
            imprimir(contas, totalContas);/*Chama a funcao imprimir passando contas e totalContas para a funcao por parametro*/
            break;
        case 8:
            saldoGeral(contas, totalContas);/*Chama a funcao saldoGeral passando contas e totalContas para a funcao por parametro*/
            break;
        case 9:
            puts("Saindo do programa.\n");
            break;
        default:
            puts("Opcao invalida. Tente novamente.\n");
        }
        puts("\n==================================================================================================\n");
    } while (opcao != 9);

    /*Fim do Menu*/
    return 0;
}