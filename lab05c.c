/*O programa abaixo foi criado para intercalar 2 vetores (v1 e v2) em um terceiro vetor v3.
Tendo como entrada o tamanho do primeiro vetor (n1) e em seguida os elementos do primeiro vetor; e depois o tamanho do segundo vetor (n2) e em seguida os elementos do segundo vetor
E tendo como saida um vetor v3, com os elementos do primeiro e do segundo vetor ordenado em ordem crescente.
Rafael Hajime Mori      RA:21045116*/

#include <stdio.h>

void troca(int *v1, int *v2){
    int sw;
    sw = *v1;
    *v1 = *v2;
    *v2 = sw;
}
/*A função abaixo é o algoritmo de ordenação conhecido como bubble sort e a função acima é para o auxilio da função de ordenação*/
void ordena (int v3[], int n3){
    int i, j;
    for(i=0; i<n3-1; i++){
        for(j=0; j<n3-i-1; j++){
            if(v3[j]>v3[j+1]){
                troca (&v3[j], &v3[j+1]);
            }
        }
    }

}

/*a função abaixo junta os vetores v1 e v2 no terceiro vetor v3 e em seguida chama a função de ordenação*/
void intercala(int v1[], int n1, int v2[], int n2, int v3[]){
    int i, j, n3;
    n3=n1+n2;
    for(i=0; i<n1; i++){
        v3[i]=v1[i];
    }
    for(j=0; j<n2; j++){
        v3[j+n1]=v2[j];
    }
    ordena (v3, n3);

}

int main()
{
    int n1, n2, n3, i, j, k;
    scanf("%d", &n1);
    int v1[n1];
    for(i=0; i<n1; i++){
        scanf("%d", &v1[i]);
    }
    scanf("%d", &n2);
    int v2[n2];
    for(j=0; j<n2; j++){
        scanf("%d", &v2[j]);
    }
    n3=n1+n2;
    int v3[n3];
    intercala(v1, n1, v2, n2, v3);
    for(k=0; k<n3; k++){
        if(k!=n3-1){
            printf("%d ", v3[k]);
        }
        else{
            printf("%d\n", v3[k]);
        }
    }


    return 0;
}
