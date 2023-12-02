#define MAX_CONTAS 50 /*Define a quantidade maxima de contas*/
#define MAX_NOME 51 /*Defiine o tamanho maximo dos nomes*/

typedef struct
{
    int numero;
    char cliente[MAX_NOME];
    int especial;
    float saldo;
} Conta; /*cria um novo tipo de variavel*/

void criarConta(Conta *contas, int *totalContas); /*Diz ao programa que sera criado uma funcao com o nome criarConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void verificarNumeroDaConta(Conta *contas, int *contaAtual, int numero); /*Diz ao programa que sera criado uma funcao com o nome verificarNumeroDaConta que vai receber como parametro um ponteiro do tipo contas, um inteiro e uma variavel do tipo inteiro*/

void verificarStatusDaConta(Conta *contas, int *contaAtual); /*Diz ao programa que sera criado uma funcao com o nome verificarStatusDaConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

int verificarConta(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome verificarConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void mostrarConta(Conta *contas, int indice); /*Diz ao programa que sera criado uma funcao com o nome mostrarConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void procurarConta(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome procurarConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void abrirMenuDeAlteracao(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome abrirMenuDeAlteracao que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void alterarNome(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome alterarNome que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void alterarNumeroDaConta(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome alterarNumeroDaConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void alterarStatusDaConta(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome alterarStatusDaConta que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void listar(const Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome listar que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void depositar(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome depositar que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void sacar(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome sacar que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void imprimir(Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome imprimir que vai receber como parametro um ponteiro do tipo contas e um inteiro*/

void saldoGeral(const Conta *contas, int contaAtual); /*Diz ao programa que sera criado uma funcao com o nome saldoGeral que vai receber como parametro um ponteiro do tipo contas e um inteiro*/