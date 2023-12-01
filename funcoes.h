#define MAX_CONTAS 50
#define MAX_NOME 51

typedef struct
{
    int numero;
    char cliente[MAX_NOME];
    int especial;
    float saldo;
} Conta;

void inserirConta(Conta *contas, int *totalContas);

void verificarNumeroDaConta(Conta *contas, int *contaAtual, int numero);

void verificarStatusDaConta(Conta *contas, int *contaAtual);

int verificarConta(Conta *contas, int contaAtual);

void mostrarConta(Conta *contas, int indice);

void procurarConta(Conta *contas, int contaAtual);

void abrirMenuDeAlteracao(Conta *contas, int contaAtual);

void alterarNome(Conta *contas, int contaAtual);

void alterarNumeroDaConta(Conta *contas, int contaAtual);

void alterarStatusDaConta(Conta *contas, int contaAtual);

void listar(const Conta *contas, int contaAtual);

void depositar(Conta *contas, int contaAtual);

void sacar(Conta *contas, int contaAtual);

void imprimir(Conta *contas, int contaAtual);

void saldoGeral(const Conta *contas, int contaAtual);