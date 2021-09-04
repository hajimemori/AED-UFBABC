#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(int *conj, int elementos);
void limpa(int *conj, int elementos);

int *novo(int capacidade, int *elementos);
void aumenta_capacidade(int **conj, int *capacidade, int elementos);
void deleta(int *conj);
int pertence(int *conj, int elementos, int num);
int contido(int *conj1, int elems1,  int *conj2, int elems2);
void adicao(int **conj, int *elementos, int *capacidade, int num);
void subtracao(int *conj, int *elementos, int num);
int *uniao(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems);
int *intersecao(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems);
int *diferenca(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems);

int cmp(const void *A, const void *B) {
    int *a = (int *)A;
    int *b = (int *)B;
    if (*a == *b) {
        printf("Dois elementos iguais: %d", *a);
    }
    return *a - *b;
}

void imprime(int *conj, int elementos) {
    int i;
    int repetidos = 0;
    printf("{");
    if (elementos > 0){
        int *copia = malloc(elementos*sizeof(int));
        memcpy(copia, conj, elementos*sizeof(int));
        qsort(copia, elementos, sizeof(int), cmp);

        printf("%d", copia[0]);
        for (i = 1; i< elementos; i++) {
            printf(", %d", copia[i]);
            repetidos += copia[i] == copia[i-1];
        }
        free(copia);
    }
    printf("}\n");

    if(repetidos)
        printf("%d numeros repetidos\n", repetidos);
}

/* Funcao: analisa_atribuicao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto de saida
 *    tam: tamanho final do conjunto 'conj'
 *
 * Retorno:
 *   'conj' contem o conjunto reinicializado e incluido todos os elementos
 *   atribuidos e 'tam' tambem e atualizado com o novo tamanho.
 *   Nao ha retorno da funcao.
 *
 * Descricao:
 *   Na atribuicao o conteudo de um dos conjuntos e substituido pelos valores
 *   entre chaves da leitura.
 *   Essa funcao apaga o conteudo do conjunto 'conj' reiniciando o seu tamanho.
 *   Em seguida le da entrada padrao o conteudo a ser atribuido ao conjunto, um
 *   valor por vez, adicionando os valores ao conjunto.
 */
void analisa_atribuicao(int **conj, int *elementos, int *capacidade) {
    int num = 0;
    *elementos = 0;
    scanf(" { ");
    while (0 < scanf(" %d ,", &num)) {
        adicao(conj, elementos, capacidade, num);
    }
}

/* Funcao: analisa_add_sub
 *
 * Parametros:
 *     op: qual operacao realizar, valores: adicao '+' ou subtracao '-'
 *   conj: vetor contendo o conjunto de entrada
 *    tam: tamanho do conjunto 'conj'
 *
 * Retorno:
 *   'conj' contem o conjunto atualizado com a adicao ou remocao de um elemento
 *   e 'tam' tambem e atualizado com o novo tamanho.
 *   Nao ha retorno da funcao.
 *
 * Descricao:
 *   Le da entrada padrao o numero a ser adicionado ou subtraido do conjunto
 *   'conj' e chama a funcao correspondente indicada pela operacao 'op'.
 */
void analisa_add_sub(char op, int **conj, int *elementos, int *capacidade) {

    int num = 0;
    scanf("%d", &num);
    if (op == '+') {
        adicao(conj, elementos, capacidade, num);
    } else {
        subtracao(*conj, elementos, num);
    }
}

/* Funcao: analisa_operacao
 *
 * Parametros:
 *     conj1: vetor contendo o conjunto de entrada do primeiro operando
 *     conj2: vetor contendo o conjunto de entrada do segundo operando
 *      tam1: tamanho do conjunto 'conj1'
 *      tam2: tamanho do conjunto 'conj2'
 *     nome1: nome do primeiro conjunto. valores: 'A' ou 'B'
 *     nome2: nome do segundo conjunto. valores: o inverso de 'nome1'
 *
 * Retorno:
 *   Se a operacao for sobre modificar 1 conjunto (+=, -=, =), entao 'conj1' e
 *   alterado com os novos valores assim como 'tam1' para refletir o novo
 *   tamanho. Se for qualquer outra operacao, nenhum dos conjuntos de entrada
 *   sao modificados.
 *   Nao ha retorno da funcao.
 *
 * Descricao:
 *   Le da entrada padrao qual operacao deve ser realizada e chama a funcao
 *   correspondente. Essa funcao analiza todas as operacoes menos a de pertence,
 *   pois assume que as operacoes sao uma das que comecam com a definicao de um
 *   conjunto, e qual o primeiro conjunto e indicado pelo 'conj1', sendo 'conj2'
 *   o segundo conjunto. Todas as operacoes, com excessao do pertence 'e'
 *   comecam com um conjunto, seguido da operacao (com excessao da de impressao)
 *   e o segundo conjunto.
 *   Ela le da entrada padrao a operacao, chama as funcoes correspondente de
 *   cada operacao e no final imprime o resultado. Para operacoes sobre um unico
 *   conjunto, o resultado a ser impresso e o proprio conjunto 'conj1'. Para
 *   operacoes sobre os dois conjuntos, o resultado a ser impresso esta em um
 *   conjunto novo 'conjRes' e o nome a ser impresso e a operacao com os
 *   conjuntos na ordem dada, assim como na entrada.
 */
void analisa_operacao(int **conj1, int *elems1, int *capac1,
                      int **conj2, int *elems2, int *capac2,
                      char nome1, char nome2) {

    int *res = NULL;
    int capRes = -1;
    int eleRes = -1;
    char b[20] = "\0";
    char op;

    scanf("%*[\t ]");
    scanf("%19[-=+cu^\\]", b);
    op = b[0];

    switch (op) {
    case '+':
    case '-':
        analisa_add_sub(op, conj1, elems1, capac1);
        break;
    case '=':
        analisa_atribuicao(conj1, elems1, capac1);
        break;
    case 'u':
        res = uniao(*conj1, *elems1, *conj2, *elems2, &capRes, &eleRes);
        break;
    case '^':
        res = intersecao(*conj1, *elems1, *conj2, *elems2, &capRes, &eleRes);
        break;
    case '\\':
        res = diferenca(*conj1, *elems1, *conj2, *elems2, &capRes, &eleRes);
        break;
    case 'c':
        if (0 == contido(*conj1, *elems1, *conj2, *elems2)) {
            printf("falso\n");
        } else {
            printf("verdadeiro\n");
        }
        return;
    }

    if (op == '+' || op == '-' || op == '=' || op == '\0') {
        printf("%c = ", nome1);
        imprime(*conj1, *elems1);
    } else if (op == 'c' || op == 'u' || op == '^' || op == '\\') {
        printf("%c %c %c = ", nome1, op, nome2);
        imprime(res, eleRes);
        deleta(res);
    }

}

/* Funcao: analisa_pertence
 *
 * Parametros:
 *   palavra: valor ja lido da entrada, que sera analizado novamente, deve
 *            conter o numero a ser realizado a operacao de pertence.
 *         A: vetor contendo o conjunto de nome 'A'
 *         B: vetor contendo o conjunto de nome 'B'
 *     tam_A: tamanho do conjunto 'A'
 *     tam_B: tamanho do conjunto 'B'
 *
 * Retorno:
 *   Nao ha retorno da funcao.
 *
 * Descricao:
 *   Le da entrada padrao o conjunto a se aplicar a funcao pertente e tambem le
 *   o numero a ser utillizado a partir da string 'palavra'. Ao final ela
 *   imprime o resultado da operacao.
 */
void analisa_pertence(char *palavra, int *A, int elemsA, int *B, int elemsB) {

    int res = 0;
    int num = 0;
    char c = '\0';

    sscanf(palavra, "%d", &num);
    scanf(" e %c", &c);
    if (c == 'A') {
        res = pertence(A, elemsA, num);
    } else {
        res = pertence(B, elemsB, num);
    }
    if (res == 0) {
        printf("falso\n");
    } else {
        printf("verdadeiro\n");
    }
}

/* Funcao: main
 *
 * Descricao:
 *   Esse programa le as operacoes sobre os conjuntos 'A' e 'B', uma por linha e
 *   as realiza em ordem. Os conjuntos estao inicialmente vazios.
 *
 *   A logica da main e a seguinte. Ler da entrada padrao  a primeira palavra de
 *   cada linha, o que indica se uma operacao comeca com a letra de um conjunto
 *   ('A' ou 'B'), e o comando 'q' para terminar o programa ou a operacao de
 *   pertence, que comeca com um numero. Apos ela chama funcoes para cada um
 *   desses 3 tipos (ou termina o programa) e antes de ler uma nova linha, le da
 *   entrada padrao o resto da linha que nao tenha sido lido.
 */
int main() {

    char palavra[20] = "\0";
    int *A, *B;
    int elemsA, elemsB, capA, capB;
    capA = 10;
    capB = 10;
    A = novo(capA, &elemsA);
    B = novo(capB, &elemsB);

    if (!(A && B)) {
        printf("Conjuntos nao alocados.\n");
    }

    while (palavra[0] != 'q' && EOF != scanf("%19s", palavra)) {
        char op = palavra[0];
        switch (op) {
        case 'A':
            analisa_operacao(&A, &elemsA, &capA, &B, &elemsB, &capB, 'A', 'B');
            break;
        case 'B':
            analisa_operacao(&B, &elemsB, &capB, &A, &elemsA, &capA, 'B', 'A');
            break;
        case 'q':
            break;
        default:
            analisa_pertence(palavra, A, elemsA, B, elemsB);
        }
        scanf("%*[^\n]\n");
    }

    deleta(B);
    deleta(A);

    return 0;
}
