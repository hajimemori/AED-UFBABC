#include <stdio.h>

void imprimeVetor(int A[], int tam){
    int i;
    for (i=0; i<tam; i++){
        printf ("%d  ", A[i]);
    }
    printf("\n");
}

int inverteVetor(int A[], int tam){
    int i;
    int j=tam-1;
    int B[tam];
    for(i=0; i<tam; i++){
        B[i]=A[j];
        j--;
    }
    return B;
}

int main(void){
    int n=100;
    int i, j ;
    int A[n];
    int invertido[n];
    int cont = 0;
    int repeticao=4;
    while(repeticao == 4){
        printf("Escolha o numero correspondente ao comando desejado: \n1) Inserir um elemento no array.\n2) Apresentar o array original.\n3) Apresentar o array invertido. \n4) Sair do programa");
        printf("\n");
        scanf("%d", &i);
        switch(i){
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf ("%d", &j);
                A[cont] = j;
                cont++;
                break;
            case 2:
                imprimeVetor (A, cont);
                break;
            case 3:
                invertido = inverteVetor(A, cont);
                imprimeVetor (invertido, cont);
                break;
            case 4:
                repeticao = 5;

        }
    }
return 0;
}
