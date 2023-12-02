<h1 align="center"> SimplesBankC </h1>

<br>

## 🚀 Tecnologias

Esse projeto foi desenvolvido com as seguintes tecnologias:

- C
- Visual Studio Code
- Clion

## 💻 Projeto

Projeto SimplesBankC foi feito para o aprendizado da linguagem C, no projeto final do segundo semestre da Fatec de linguagem de programação.

O Projeto tem um menu inicial com 9 opções onde você pode criar uma nova conta, fazer alterações nas contas, Procurar por uma conta, Listar as contas,
Realizar deposito na conta, Realizar saque na conta, Imprimir os dados da conta, Calcular saldo de todas as contas e por fim sair.

Funções Disponiveis:

- void criarConta(contas, totalContas);
    Essa função cria uma nova conta.

- void verificarNumeroDaConta(Conta *contas, int *contaAtual, int numero);
    Essa função verifica o numero da conta

- void verificarStatusDaConta(Conta *contas, int *contaAtual);
    Essa função verifica o status da conta.

- int verificarConta(Conta *contas, int contaAtual);
    Essa função verifica se a conta existe ou não.

- void mostrarConta(Conta *contas, int indice);
    Essa função mostra os dados da conta.

- void procurarConta(contas, totalContas);
    Essa função procura uma conta.

- void abrirMenuDeAlteracao(contas, totalContas);
    Essa função abre o menu de alteração.

- void alterarNome(Conta *contas, int contaAtual);
    Essa função altera o nome da conta

- void alterarNumeroDaConta(Conta *contas, int contaAtual);
    Essa função altera o numero da conta.

- void alterarStatusDaConta(Conta *contas, int contaAtual);
    Essa função altera o status da conta.

- void listar(contas, totalContas);
    Essa função lista todas as conta.

- void depositar(contas, totalContas);
    Essa função adiciona valores ao saldo da conta.

- void sacar(contas, totalContas);
    Essa função subtrai valores do saldo da conta.

- void imprimir(contas, totalContas);
    Essa função exibe a conta.

- void saldoGeral(contas, totalContas);
    Essa função soma o saldo de todas as conta.

---

Feito com ♥ by Pedro Kleinfelder, Rodrigo Mantovani, Lucas Martins, Pedro Antonio.