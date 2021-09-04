#include <stdio.h>

/* Funcao: busca
 * A funcao deve encontrar a posi��o (i,j) do jogador no tabuleiro.
 * O jogador � representado pelo valor -1.
 * O retorno da posicao se da pelo vetor parametro pos.
 *
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabSize: largura e altura do tabuleiro (o tabuleiro � sempre quadrado)
 *      pos: posicao do jogador no tabuleiro
 *
 * Retorno:
 *   Em pos[0] deve ser setado a linha i onde esta o jogador.
 *   Em pos[1] deve ser setado a coluna j onde esta o jogador.
 */
void busca(int **tab, int tabSize, int pos[2]) {
    int i, j;
    for (i=0; i<tabSize; i++){
        for (j=0; j<tabSize; j++){
            if(tab[i][j] == -1){
                pos[0] = i;
                pos[1] = j;
                return;
            }
        }
    }

}

/* Funcao: visiveis
 * Retorna os monstros visiveis nas 8 posi��es adjacentes em ordem.
 * A posi��o 0 representa o canto superior esquerdo e a posi��o 7 o canto
 * inferior direito.
 * 0 1 2
 * 3 J 4
 * 5 6 7
 * As posi��es devem ter o identificador da especie do monstro presente ou zero se a
 * posi��o n�o tiver um monstro.
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabSize: largura e altura do tabuleiro (o tabuleiro � sempre quadrado)
 *        v: Identificadores das posi��es adjacentes
 *
 * Retorno:
 *    Para cada posicao v[i], onde i=0,1,..7, deve ser setado
 *    o identificador da especie do monstro naquela posi��o ou 0 se a posicao
 *    estiver vazia.
 */
void visiveis(int **tab, int tabSize, int v[8]) {
    int i, j, pos[2], aux=0;
    busca(tab, tabSize, pos);
    for (i=pos[0]-1; i<=pos[0]+1; i++){
        for (j=pos[1]-1; j<=pos[1]+1; j++){
            if(i<0 || i>=tabSize || j<0 || j>=tabSize){
                v[aux] = 0;
                aux++;
            }
            else if (tab[i][j] != -1){
                v[aux] = tab[i][j];
                aux++;
            }



        }
    }
    return;
}

/* Funcao: proximos
 * Retorna quais tipos de monstros est�o presentes nas 16 posi��es proximas ao
 * jogador mas n�o adjacentes a ele.
 * O valor de p[i] deve ser setado para 1 se existir ao menos uma ocorr�ncia do monstro de
 * identificador i+1 em alguma das 16 posi��es proximas, ou 0 caso contr�rio.
 *
 * Parametros:
 *       tab: tabuleiro
 *   tabsize: tamanho do tabuleiro (sempre quadrado)
 *         p: Monstros proximos
 *  monstros: tamanho de p
 *
 * Retorno:
 *    Note que o parametro p eh um vetor de tamanho igual ao numero de especies de monstros (especies).
 *    Para cada posi��o i, p[i] deve ser setado com 1 se um monstro de especie (i+1) esta proximo
 *    e 0 caso contrario.
 */
void proximos(int **tab, int tabSize, int *p, int especies) {
    int i, j, pos[2], aux;


    busca(tab, tabSize, pos);

    i=pos[0]-2;
    for (j=pos[1]-2; j<=pos[1]+2; j++){
        if(i>=0 && j>=0 && i<tabSize && j<tabSize){
            if(tab[i][j]!=0){
               aux = tab[i][j];
               p[aux-1] = 1;
            }
        }
    }
    i=pos[0]+2;
    for (j=pos[1]-2; j<=pos[1]+2; j++){
        if(i>=0 && j>=0 && i<tabSize && j<tabSize){
            if(tab[i][j]!=0){
               aux = tab[i][j];
               p[aux-1] = 1;
            }
        }
    }
    j=pos[1]-2;
    for(i=pos[0]-1; i<=pos[0]+1; i++){
        if(i>=0 && j>=0 && i<tabSize && j<tabSize){
            if(tab[i][j]!=0){
               aux = tab[i][j];
               p[aux-1] = 1;
            }
        }
    }
    j=pos[1]+2;
    for(i=pos[0]-1; i<=pos[0]+1; i++){
        if(i>=0 && j>=0 && i<tabSize && j<tabSize){
            if(tab[i][j]!=0){
               aux = tab[i][j];
               p[aux-1] = 1;
            }
        }
    }

    return;
}

/* Funcao: movimenta
 * Movimenta o jogador, que � representado no tabuleiro pelo valor -1.
 * O jogador deve sempre permanecer dentro do tabuleiro.
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabsize: tamanho do tabuleiro (sempre quadrado)
 *      desloca: contem o deslocamento que deve ser aplicado ao jogador.
                 desloca[0] contem o deslocamento em linhas (-1, 0, ou 1)
 *               desloca[1] contem o deslocamento em colunas (-1, 0, ou 1)
 *
 * Retorno:
 *   Especie do monstro encontrado na nova posicao do jogador
 *   ou 0 se nao houver monstro nesta posicao.
 */
int movimenta(int **tab, int tabSize, int desloca[2]) {
    int i, j, pos[2], novaPos[2], monstro=0;
    busca(tab, tabSize, pos);
    i=pos[0];
    j=pos[1];
    novaPos[0] = pos[0] + desloca[0];
    novaPos[1] = pos[1] + desloca[1];
    if (novaPos[0]>=0 && novaPos[1]>=0 && novaPos[0]<tabSize && novaPos[1]<tabSize){
        i=novaPos[0];
        j=novaPos[1];
        monstro = tab[i][j];
        tab[pos[0]][pos[1]] = 0;
        tab[i][j] = -1;
    }
    return monstro;
}

/* Funcao: captura
 * Verifica se o jogador pode capturar o monstro de uma especie que esta na posicao do jogador.
 * Armazena o monstro capturado no vetor capturados e retorna 1 se conseguiu
 * capturar, ou 0 caso contrario.
 * Um monstro de especie 1 sempre eh capturado.
 *
 * Parametros:
 *   capturados: vetor de tamanho n_especies com a quantidade de monstros de cada especie
 *               que o jogador possui. Desta forma, capturados[i] possui a quantidade de monstros
 *               da especie (i+1) que o jogador possui.
 *   n_especies: tamanho do vetor capturados
 *   especie: numero da especie que pretende-se capturar.
 *
 * Retorno:
 *   1 se o monstro foi capturado, e 0 caso contrario.
 *   Note que o vetor capturados deve ser atualizado caso o monstro tenha sido capturado.
 */
int captura(int *capturados, int n_especies,  int especie) {
    int E=0, i;
    if(especie==1){
        capturados[0] += 1;
        return 1;
    }
    else{
        for (i=1; i<n_especies; i++){
            E += capturados[i-1] * i;
        }
        if(E >= especie){
            capturados[especie-1] += 1;
            return 1;
        }
    }
    return 0;
}
