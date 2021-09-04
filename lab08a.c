#include <stdio.h>
#include <stdlib.h>

/* Funcao: novo
 *
 * Cria um novo conjunto vazio (sem elementos) com um vetor numeros de determinada capacidade.
 * O conjunto deve ser alocado dinamicamente assim como o vetor elementos do mesmo.
 *
 * Parametros:
 *   capacidade: tamanho do vetor numeros que deve ser alocado
 *    elementos: ponteiro para a variável que controla os elementos
 *
 * Retorno:
 *   O endereço do novo conjunto alocado.
 *   A funcao deve ainda setar os campos elementos e capacidade corretamente.
 */
int *novo(int capacidade, int *elementos) {

    return NULL;
}

/* Funcao: aumenta_capacidade
 *
 * Aumenta a capacidade de um determinado conjunto.
 * Deve-se criar um novo vetor numeros com a capacidade especificada e trocar com o anterior,
 * onde, neste caso, lembre-se de liberar o vetor antigo que nao esta mais em uso.
 * O ponteiro do conjunto nao deve ser modificado, apenas seus dados internos.
 *
 * Parametros:
 *             conj: ponteiro do conjunto que tera a capacidade aumentada
 *       capacidade: capacidade atual
 *        elementos: número de elementos contidos em conj
 *   novaCapacidade: nova capacidade
 *   A funcao deve setar os campos elementos e capacidade corretamente.
 */
void aumenta_capacidade(int **conj, int *capacidade, int elementos, int novaCapacidade) {
    /* Implementar a funcao */
    return;
}

/* Funcao: deleta
 *
 * Libera a memoria alocada para o vetor elementos de um determinado conjunto.
 * A função deve também liberar a memória alocada para o conjunto.
 *
 * Parametros:
 *   conj: ponteiro do conjunto a ser deletado
 */
void deleta(int *conj) {
    /* Implementar a funcao */
    return;
}

/* Funcao: pertence
 *
 * Verifica se o conjunto apontado por conj possui o elemento num.
 * O conjunto nao deve ser modificado.
 *
 * Parametros:
 *        conj: ponteiro do conjunto de entrada
 *   elementos: número de elementos em conj
 *         num: elemento a ser verificado
 *
 * Retorno:
 *   1 se num pertence a conj, e 0 caso contrario
 */
int pertence(int *conj, int elementos, int num) {
    /* Implementar a funcao e trocar o valor de retorno */
    return -1;
}

/* Funcoes: contido
 *
 * Verifica se o conjunto apontado por conj1 esta contido no conjunto apontado por conj2.
 * Os conjuntos nao devem ser modificados.
 *
 * Parametros:
 *    conj1: ponteiro do conjunto de entrada que sera o primeiro operando
 *   elems1: número de elementos em conj1
 *    conj2: ponteiro do conjunto de entrada que sera o segundo operando
 *   elems21: número de elementos em conj1
 *
 * Retorno:
 *   0 se o conjunto 1 nao esta contido no conjunto 2,
 *   qualquer valor diferente caso contrario.
 */
int contido(int *conj1, int elems1,  int *conj2, int elems2) {
    /* Implementar a funcao e trocar o valor de retorno */
    return -1;
}



/* Funcoes: adicao
 *
 * Inclui um elemento no conjunto sem permitir duas ou mais copias do mesmo elemento.
 * A quantidade de elementos no conjunto deve ser atualizada se o elemento for inserido.
 * Pode ser necessario aumentar a capacidade do conjunto.
 *
 * Parametros:
 *        conj: ponteiro do conjunto de entrada
 *   elememtos: número de elementos em conj
 *  capacidade: capacidade de conj
 *   num: elemento a ser incluido
 */
void adicao(int **conj, int *elementos, int *capacidade, int num) {
    /* Implementar a funcao */
    return;
}

/* Funcoes: subtracao
 *
 * Remove um elemento de um conjunto apontado por conj.
 * A quantidade de elementos no conjunto deve ser atualizada se o elemento for removido.
 *
 * Parametros::
 *        conj: ponteiro do conjunto de entrada
 *   elememtos: número de elementos em conj
 *         num: elemento a ser removido
 */
void subtracao(int *conj, int *elementos, int num) {
    /* Implementar a funcao */
    return;
}


/* Funcoes: uniao, intersecao, diferenca
 *
 * Realiza a operacao do nome da funcao entre o conjunto conj1 e o conj2, respectivamente.
 * O resultado deve ser armazenado num novo conjunto alocado para esta finalidade.
 * Os conjuntos conj1 e conj2 nao devem ser modificados.
 *
 * Parametros:
 *       conj1: ponteiro do conjunto de entrada que sera o primeiro operando
 *      elems1: número de elementos em conj1
 *       conj2: ponteiro do conjunto de entrada que sera o segundo operando
 *      elems2: número de elementos em conj1
 *  capacidade: capacidade do conjunto resultado
 *   elementos: número de elementos do conjunto resultado
 *
 * Retorno:
 *   Ponteiro para um novo conjunto que contem o resultado da operacao
 */
int *uniao(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems) {
    /* Implementar a funcao e trocar o valor de retorno */
    return NULL;
}

int *intersecao(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems) {
    /* Implementar a funcao e trocar o valor de retorno */
    return NULL;
}

int *diferenca(int *conj1, int elems1, int *conj2, int elems2, int *capacidade, int *elems) {
    return NULL;
}
