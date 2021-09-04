#include <stdio.h>


typedef enum ENUM_ORDEM {CRESCENTE, DECRESCENTE, DESORDENADA} ordem_t;

void busca_binaria(int vet[], int ini, int fim, int ra, ordem_t ordem) {
    int meio = (ini+fim)/2;
    if (fim < ini){
        printf("\n%d nao esta na lista!", ra);
        return;
    }

    printf("%d ", meio);
    if(vet[meio] == ra){
        printf("\n%d esta na posicao: %d", ra, meio);
        return;
    }

    if(ordem == CRESCENTE){
        if (ra < vet[meio]){
            busca_binaria(vet, ini, meio-1, ra, ordem);
        }
        else{
            busca_binaria(vet, meio+1, fim, ra, ordem);
        }
    }
    else{
        if (ra > vet[meio]){
            busca_binaria(vet, ini, meio-1, ra, ordem);
        }
        else{
            busca_binaria(vet, meio+1, fim, ra, ordem);
        }
    }
}

int encontra_pos(int vet[], int ini, int fim, int ra, ordem_t ordem) {
     int achei;
     int i;
     for(i=0; i<fim; i++){
        if(vet[i] == ra){
            achei = i;
            return achei;
        }
     }
     return -1;
}

int main() {
    int i, n, j;
    int aux;  /*variavel para auxiliar na troca das posiÁoes do vetor*/
    int pos; /*variavel para auxiliar na ordenaÁ„o do vetor*/
    int lista[150];
    char op;
    ordem_t ordenacao = DESORDENADA;

    /* lendo quantidade de alunos e RA de cada um: */
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    do {
        scanf("%c", &op);
        switch(op) {
            case 'p':
                /* Opera√ß√£o de impress√£o da lista atual */
                if (n > 0) {
                    for (i = 0; i < n; i++)
                        printf("%d ", lista[i]);
                    printf("\n");
                }
                break;

            case 'c':
                /* Ordenar de forma crescente a lista
                 * Vamos usar Selection Sort */

                /* IMPLEMENTAR */

                for(i=0; i<n-1; i++){
                    pos=i;
                    for(j=i+1; j<n; j++){
                        if(lista[j]<lista[pos]){    /*Esse sinal que ordena de forma crescente ou decrescente*/
                            pos=j;
                        }
                    }
                    aux = lista[pos];
                    lista[pos] = lista[i];
                    lista[i] = aux;
                }
                ordenacao = CRESCENTE;
                break;

            case 'd':
                /* Ordenar de forma decrescente a lista
                 * Vamos usar Selection Sort */

                /* IMPLEMENTAR */
                for(i=0; i<n-1; i++){
                    pos=i;
                    for(j=i+1; j<n; j++){
                        if(lista[j]>lista[pos]){
                            pos=j;
                        }
                    }
                    aux = lista[pos];
                    lista[pos] = lista[i];
                    lista[i] = aux;
                }

                ordenacao = DECRESCENTE;
                break;

            case 'b':
                /* Fazer busca na lista apenas se ela estiver ordenada de alguma forma */
                scanf("%d", &aux);
                if (ordenacao == DESORDENADA)
                    printf("Vetor nao ordenado!");
                else
                    busca_binaria(lista, 0, n-1, aux, ordenacao);
                printf("\n");
                break;

            case 'i':
                /* Inserir aluno novo apenas se houver espa√ßo na turma */
                scanf("%d", &aux);

                if (n == 150) {
                    printf("Limite de vagas excedido!\n");
                    break;
                }
                else{
                /*verificar se o RA ja esta no vetor*/
                    pos = -1;
                    for(i=0; i<n; i++){
                        if(lista[i] == aux){
                            printf("Aluno ja matriculado na turma!\n");
                            pos = i;
                            break;
                        }
                    }
                    if(pos == -1){
                        if(ordenacao == DESORDENADA){
                            lista[n] = aux;
                            n =n + 1;
                        }
                        else{
                            if (ordenacao == CRESCENTE){

                                i=n-1;
                                while(lista[i]>aux && i>=0){
                                    lista[i+1]=lista[i];
                                    i=i-1;
                                }
                                lista[i+1]=aux;
                                n=n+1;
                            }
                            else if(ordenacao == DECRESCENTE){
                                i=n-1;
                                while(lista[i]<aux && i>=0){
                                    lista[i+1]=lista[i];
                                    i=i-1;
                                }
                                lista[i+1]=aux;
                                n=n+1;
                            }
                        }
                    }
                }
                break;

            case 'r':
                /* Remover aluno da lista apenas se ele existir */
                scanf("%d", &aux);

                if (n == 0) {
                    printf("Nao ha alunos cadastrados na turma!\n");
                    break;
                }
                pos = encontra_pos(lista, 0, n, aux, ordenacao);
                if (pos == -1){
                    printf("Aluno nao matriculado na turma!\n");
                    break;
                }
                else{
                    for(i=pos; i<n-1; i++){
                        lista[i]=lista[i+1];
                    }
                    n -= 1;

                }
                break;

            case 's':
                break;
        }
    } while(op != 's');

    return 0;
}
