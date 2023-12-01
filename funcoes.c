#include "funcoes.h"

#include <stdio.h>
#include <string.h>

void inserirConta(Conta *contas, int *totalContas)
{

    if (*totalContas < MAX_CONTAS)
    {

        printf("\nDigite o numero da conta: \n");
        verificarNumeroDaConta(contas, totalContas, contas[*totalContas].numero);

        printf("\nDigite o nome do cliente: \n");
        fflush(stdin);
        gets(contas[*totalContas].cliente);
        fflush(stdin);

        printf("\nA conta eh especial? (1 para sim, 0 para nao): \n");
        verificarStatusDaConta(contas, totalContas);

        printf("\nDigite o saldo atual: \n");
        scanf("%f", &contas[*totalContas].saldo);

        (*totalContas)++;
        printf("\nConta adicionada com sucesso!\n");
    }
    else
    {
        printf("\nLimite maximo de contas atingido.\n");
    }
}

void verificarNumeroDaConta(Conta *contas, int *contaAtual, int numero)
{

    // Loop até que um número seja inserido
    while (scanf("%d", &numero) != 1)
    {
        printf("\nEntrada invalida.\n");
        printf("\nDigite o numero da conta: \n");

        // Limpar o buffer de entrada para evitar loop infinito em caso de entrada inválida
        while (getchar() != '\n')
            ;
    }
    contas[*contaAtual].numero = numero;
}

void verificarStatusDaConta(Conta *contas, int *contaAtual)
{
    scanf("%d", &contas[*contaAtual].especial);
    while (contas[*contaAtual].especial < 0 || contas[*contaAtual].especial > 1)
    {
        printf("\nNumero invalido digite 1 para sim, 0 para nao): \n");
        scanf("%d", &contas[*contaAtual].especial);
    }
}

int verificarConta(Conta *contas, int contaAtual)
{
    if (contaAtual == 0)
    {
        printf("\nNenhuma conta existente.\n");
        return 0;
    }

    int numero;
    printf("Digite o numero da conta: \n");
    scanf("%d", &numero);
    printf("\n");

    int indice = -1;

    for (int i = 0; i < contaAtual; i++)
    {
        if (contas[i].numero == numero)
        {
            indice = i;
            return indice;
        }
    }
    return 0;
}

void mostrarConta(Conta *contas, int indice)
{

    printf("Dados da conta:\n");
    printf("Numero: %d\n", contas[indice].numero);
    printf("Cliente: %s\n", contas[indice].cliente);
    printf("Especial: %s\n", contas[indice].especial ? "Sim" : "Nao");
    printf("Saldo: %.2f\n", contas[indice].saldo);
}

void procurarConta(Conta *contas, int contaAtual)
{

    int indice = verificarConta(contas, contaAtual);

    if (indice != -1)
    {
        printf("\nConta Existente!\n");
        printf("\nNumero da Conta: %d\n", contas[indice].numero);
        printf("Nome do Cliente: %s\n", contas[indice].cliente);
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void abrirMenuDeAlteracao(Conta *contas, int contaAtual)
{

    int opcao;

    do
    {
        printf("\n==================================================================================================\n");
        printf("\nMenu:\n");
        printf("1. Alterar Nome\n");
        printf("2. Alterar Numero da conta\n");
        printf("3. Alterar Cliente especial\n");
        printf("4. Sair\n");
        printf("\nEscolha uma opcao: \n");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao)
        {
        case 1:
            alterarNome(contas, contaAtual);
            break;
        case 2:
            alterarNumeroDaConta(contas, contaAtual);
            break;
        case 3:
            alterarStatusDaConta(contas, contaAtual);
            break;
        case 4:
            printf("\nCancelando alteracao.\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }
        printf("\n==================================================================================================\n");
    } while (opcao != 4);
}

void alterarNome(Conta *contas, int contaAtual)
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

void alterarNumeroDaConta(Conta *contas, int contaAtual)
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

void alterarStatusDaConta(Conta *contas, int contaAtual)
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

void listar(const Conta *contas, int contaAtual)
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
               contas[i].especial ? "Sim" : "Nao", contas[i].saldo);
    }
}

void depositar(Conta *contas, int contaAtual)
{

    int indice = verificarConta(contas, contaAtual);
    float valor;

    if (indice != -1)
    {
        printf("\nDigite o valor do deposito: \n");
        scanf("%f", &valor);

        contas[indice].saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
    }
    else
    {
        printf("\nConta nao encontrada.\n");
    }
}

void sacar(Conta *contas, int contaAtual)
{

    int indice = verificarConta(contas, contaAtual);
    float valor;

    if (indice != -1)
    {
        printf("\nDigite o valor do saque: \n");
        scanf("%f", &valor);

        if (contas[indice].saldo >= valor)
        {
            contas[indice].saldo -= valor;
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

void imprimir(Conta *contas, int contaAtual)
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

void saldoGeral(const Conta *contas, int contaAtual)
{

    if (contaAtual == 0)
    {
        printf("\nNenhuma conta disponivel para calculo do saldo geral.\n");
        return;
    }

    float saldoGeral = 0.0;
    for (int i = 0; i < contaAtual; i++)
    {
        saldoGeral += contas[i].saldo;
    }

    printf("\nSaldo Geral de Todas as Contas: %.2f\n", saldoGeral);
}
