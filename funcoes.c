#include "funcoes.h" /*Inclue a biblioteca funcoes*/

#include <stdio.h>  /*Inclue a biblioteca com funções úteis para entrada e saída de dados*/

void criarConta(Conta *contas, int *totalContas) /*Essa funcao cria uma nova conta*/
{

    if (*totalContas < MAX_CONTAS) /*verifica se a quantidade de contas eh menor que a quantidade maxima de contas*/
    {

        printf("\nDigite o numero da conta: \n");    /*escreve na tela o que esta entre "" e o \n pula linha*/
        verificarNumeroDaConta(contas, totalContas, contas[*totalContas].numero); /*chama a funcao verificarNumeroDaConta passando contas, totalContas, e numero da conta por parametro*/

        printf("\nDigite o nome do cliente: \n");

        fflush(stdin);                      /*descarrega os buffers de saída de um fluxo de dados*/
        gets(contas[*totalContas].cliente); /*Armazena o nome digitado pelo usuario*/
        fflush(stdin);                      /*descarrega os buffers de saída de um fluxo de dados*/

        printf("\nA conta eh especial? (1 para sim, 0 para nao): \n");
        verificarStatusDaConta(contas, totalContas); /*chama a funcao verificarNumeroDaConta passando contas, totalContas por parametro*/

        printf("\nDigite o saldo atual: \n");
        scanf("%f", &contas[*totalContas].saldo); /*adiciona o saldo digitado pelo usuario no saldo da conta*/

        (*totalContas)++; /*Incrementa 1 no total de contas*/
        printf("\nConta adicionada com sucesso!\n");
    }
    else /*caso a quantidade de contas passe o maximo permitido ele exibira a mensagem abaixo*/
    {
        printf("\nLimite maximo de contas atingido.\n");
    }
}

void verificarNumeroDaConta(Conta *contas, int *contaAtual, int numero) /*Essa funcao verifica o numero da conta*/
{

    while (scanf("%d", &numero) != 1) /*Loop até que um número seja inserido*/
    {
        printf("\nEntrada invalida.\n");
        printf("\nDigite o numero da conta: \n");

        while (getchar() != '\n') /*Limpar o buffer de entrada para evitar loop infinito em caso de entrada inválida*/
            ;
    }
    contas[*contaAtual].numero = numero; /*Adiciona o numero a conta*/
}

void verificarStatusDaConta(Conta *contas, int *contaAtual) /*Essa funcao verifica o status da conta*/
{
    scanf("%d", &contas[*contaAtual].especial); /*adiciona valor ao saldo da conta*/

    while (contas[*contaAtual].especial < 0 || contas[*contaAtual].especial > 1) /*Loop para verifica se o numero digitado eh menor que 0 ou maior que 1*/
    {
        printf("\nNumero invalido digite 1 para sim, 0 para nao): \n");
        scanf("%d", &contas[*contaAtual].especial); /*Adiciona o status a conta*/
    }
}

int verificarConta(Conta *contas, int contaAtual) /*Essa funcao verifica se a conta existe ou nao*/
{
    if (contaAtual == 0) /*verifica se existe ao menos uma conta*/
    {
        printf("\nNenhuma conta existente.\n");
        return 0;
    }

    int numero;
    printf("Digite o numero da conta: \n");
    scanf("%d", &numero); /*pega o dado digitado pelo usuario*/
    printf("\n");

    int indice = -1;

    for (int i = 0; i < contaAtual; i++) /*loop */
    {
        if (contas[i].numero == numero) /*verifica o numero da conta eh igual ao numero digitado*/
        {
            indice = i;
            return indice; /*retorna o indice quando a funcao for chamada*/
        }
    }
    return 0;
}

void mostrarConta(Conta *contas, int indice) /*Essa funcao mostra os dados da conta*/
{

    printf("Dados da conta:\n");
    printf("Numero: %d\n", contas[indice].numero);                     /*mostra o campo numero da conta*/
    printf("Cliente: %s\n", contas[indice].cliente);                   /*mostra o nome da conta*/
    printf("Especial: %s\n", contas[indice].especial ? "Sim" : "Nao"); /*mostra se a conta eh especial ou nao*/
    printf("Saldo: %.2f\n", contas[indice].saldo);                     /*mostra o saldo da conta*/
}

void procurarConta(Conta *contas, int contaAtual) /*Essa funcao procura uma conta*/
{

    int indice = verificarConta(contas, contaAtual); /*chama a funcao verificarConta que vai retornar um dado que sera armazenado na variavel indice*/

    if (indice != -1) /*verifica se a variavel indice eh diferente de -1*/
    {
        printf("\nConta Existente!\n");
        printf("\nNumero da Conta: %d\n", contas[indice].numero); /*mostra o campo numero da conta*/
        printf("Nome do Cliente: %s\n", contas[indice].cliente);  /*mostra o nome da conta*/
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void abrirMenuDeAlteracao(Conta *contas, int contaAtual) /*Essa funcao abre o menu de alteracao*/
{

    int opcao;

    do
    {
        /*Inicio do Menu de Alteracoes*/
        printf("\n==================================================================================================\n");
        printf("\nMenu:\n");
        printf("1. Alterar Nome\n");
        printf("2. Alterar Numero da conta\n");
        printf("3. Alterar Cliente especial\n");
        printf("4. Sair\n");
        printf("\nEscolha uma opcao: \n");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao) /*Verifica a opcao escolhida*/
        {
        case 1:
            alterarNome(contas, contaAtual); /*chama a funcao alterarNome*/
            break;
        case 2:
            alterarNumeroDaConta(contas, contaAtual); /*chama a funcao alterarNumeroDaConta*/
            break;
        case 3:
            alterarStatusDaConta(contas, contaAtual); /*chama a funcao alterarStatusDaConta*/
            break;
        case 4:
            printf("\nCancelando alteracao.\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }
        printf("\n==================================================================================================\n");
    } while (opcao != 4);
    /*Fim do Menu de Alteracoes*/
}

void alterarNome(Conta *contas, int contaAtual) /*Essa funcao altera o nome da conta*/
{

    int indice = verificarConta(contas, contaAtual);

    if (indice != -1)
    {

        printf("\nDigite o novo nome para a conta: \n");

        fflush(stdin);
        gets(contas[indice].cliente);
        fflush(stdin);

        printf("\nNome alterado com sucesso!\n");
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void alterarNumeroDaConta(Conta *contas, int contaAtual) /*Essa funcao altera o numero da conta*/
{

    int indice = verificarConta(contas, contaAtual);

    if (indice != -1)
    {

        printf("\nDigite um novo numero para a conta: \n");
        scanf("%d", &contas[indice].numero);

        printf("\nNumero da conta alterado com sucesso!\n");
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void alterarStatusDaConta(Conta *contas, int contaAtual) /*Essa funcao altera o status da conta*/
{

    int indice = verificarConta(contas, contaAtual);

    if (indice != -1)
    {

        if (contas[indice].especial == 0)
        {
            contas[indice].especial = 1;
        }
        else
        {
            contas[indice].especial = 0;
        }

        printf("\nStatus da conta alterado com sucesso!\n");
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void listar(const Conta *contas, int contaAtual) /*Essa funcao lista todas as conta*/
{

    if (contaAtual == 0)
    {
        printf("\nNenhuma conta disponivel para listar.\n");
        return;
    }

    printf("\nListagem de Contas:\n");

    for (int i = 0; i < contaAtual; i++)
    {
        printf("\nNumero: %d, Cliente: %s, Especial: %s, Saldo: %.2f\n",
               contas[i].numero, contas[i].cliente,
               contas[i].especial ? "Sim" : "Nao", contas[i].saldo); /*exibe todos os dados de todas as contas em formato de lista*/
    }
}

void depositar(Conta *contas, int contaAtual) /*Essa funcao adiciona valores ao saldo da conta*/
{

    int indice = verificarConta(contas, contaAtual);
    float valor;

    if (indice != -1)
    {
        printf("\nDigite o valor do deposito: \n");
        scanf("%f", &valor);

        contas[indice].saldo += valor; /*acrescente valores ao saldo da conta*/
        printf("\nDeposito realizado com sucesso!\n");
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void sacar(Conta *contas, int contaAtual) /*Essa funcao subtrai valores do saldo da conta*/
{

    int indice = verificarConta(contas, contaAtual);
    float valor;

    if (indice != -1)
    {
        printf("\nDigite o valor do saque: \n");
        scanf("%f", &valor);

        if (contas[indice].saldo >= valor)
        {
            contas[indice].saldo -= valor; /*subtrai valores do saldo da conta*/
            printf("\nSaque realizado com sucesso!\n");
        }
        else
        {
            printf("\nSaldo insuficiente.\n");
        }
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void imprimir(Conta *contas, int contaAtual) /*Essa funcao exibe a conta*/
{

    int indice = verificarConta(contas, contaAtual);

    if (indice != -1)
    {
        mostrarConta(contas, indice);
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void saldoGeral(const Conta *contas, int contaAtual) /*Essa funcao soma o saldo de todas as conta*/
{

    if (contaAtual == 0)
    {
        printf("\nNenhuma conta disponivel para calculo do saldo geral.\n");
        return;
    }

    float saldoGeral = 0.0;
    for (int i = 0; i < contaAtual; i++)
    {
        saldoGeral += contas[i].saldo; /*soma o saldo da conta com o resto de todas as contas*/
    }

    printf("\nSaldo Geral de Todas as Contas: %.2f\n", saldoGeral);
}
