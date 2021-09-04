/*
Prof Teoria - Emílio Francesquini
Prof Lab - Cláudio/Marcio Oikawa
RA 21014016 - Victor Hideki Fujii
RA 21045116 - Rafael Hajime Mori
*/
#include <stdio.h>
#include <string.h>

/*Zera os vetores de inteiros pra receber a proxima chamada*/
void zeraVetor(int vetor[], int tamV){
    int i;
    for(i=0; i<tamV; i++){
        vetor[i]=0;
    }
}
/*Cria numerao int ja invertido (para facilitar as operaçoes) a partir de uma
  string*/
int criaNumeraoDeString(char str[], int num[]){
    int i, j=1, tamanho;
    /*Para indicar se o numero é negativo ou positivo, utilizamos o primeiro
      espaço do vetor (v[0]). Caso o numero for negativo v[0]=0 e caso for
      positivo v[0]=1 */
    if(str[0] == '-'){
        num[0] = 0;
        i=1;
        tamanho = strlen(str) - 2;
        j=tamanho;
        for(i; i <= tamanho; i++){
        num[j]=str[i] - '0';
        j--;
       }
    }
    else{
        num[0] = 1;
        i=0;
        tamanho = strlen(str) - 1;

        j=tamanho;
        for(i; i < tamanho; i++){
        num[j]=str[i] - '0';
        j--;
       }
    }
    return tamanho;
}

/*Imprime Numerao*/
void imprimeNumerao(int num[], int tamNum){
    int i;
    /*Para imprimir */
    if(num[0] == 0){
        printf ("-");
    }
    for (i=tamNum; i>=1 ; i--){
        printf ("%d", num[i]);
    }
    printf ("\n");
}

/*Troca o valor de dois inteiros*/
void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/*SOMA: Para o resultado da soma iremos apenas alterar o vetor A.
  Portanto, caso o vetor B tenha um tamanho maior que A, iremos troca-los*/
int soma (int A[], int tamA, int B[], int tamB){
    int i;

    if(tamA < tamB){
        for(i=1; i<tamB; i++){
            troca(&A[i], &B[i]);
        }
        troca(&tamA, &tamB);
    }

    /*Soma termo a termo*/
    for(i=1; i<tamA+1; i++){
        A[i] += B[i];


        if(A[i]==10){
            A[i] = 0;
            A[i+1] += 1;
        }
        else if(A[i]>10){
            A[i] -= 10;
            A[i+1] += 1;
        }
    }
    if(A[tamA+1]!=0){
        tamA++;
    }
    /*Caso a soma der 0, devemos nos certificar que não há sinal
      de negativo antecedendo-o*/
    if(tamA==1 && A[1]==0){
	    A[0]=1;
    }
    return tamA;
}


/*Subtrai Termo a termo*/
int subAux(int A[], int B[],int j){
    if(A[j]>B[j]){
        return A[j]-B[j];
    }
    else if(A[j]==B[j]){
        return 0;
    }
    else{
        A[j]+=10;
        A[j+1]--;
        return A[j]-B[j];
    }
}

/*SUBTRAI: Para o resultado da subtração iremos apenas alterar o vetor A.
  Portanto, caso o vetor B seja maior que A, iremos troca-los*/
int subtrai (int A[], int tamA, int B[], int tamB){
    int i, aux;

    if(tamA < tamB){
        for(i=1; i<=tamB; i++){
            troca(&A[i], &B[i]);
        }
        troca(&tamA, &tamB);
        if(A[0]==0){
            A[0]=1;
        }
        else{
            A[0]=0;
        }
    }
    /*Caso os tamanhos dos numeros forem iguais, devemos deixar o maior sendo
      A[A]. Tambem há uma preocupação com o jogo de sinal envolvido (caso haja
      um numero negativo maior que o outro positivo, deve-se deixar o sinal
      negativo e etc)*/
    if (tamA == tamB){
        aux = 0;
        for(i=tamA; i>=1; i--){
            if(B[i]>A[i]){
                aux=1;
                break;
            }
            else if(A[i]>B[i]){
                break;
            }
        }
        if(aux==1){
            for(i=1; i<=tamA; i++){
                troca(&A[i], &B[i]);
            }
            if(A[0]==0){
                A[0]=1;
            }
            else{
                A[0]=0;
            }
        }
    }
    for(i=1; i <= tamA; i++){
        A[i] = subAux(A, B, i);
    }
    /*Devolve o tamanho do vetor*/
    while(A[tamA] == 0){
        tamA--;
        if(tamA==0){
            break;
        }
    }
    /*Caso nulo*/
    if(tamA==0){
        A[0]=1;
        tamA=1;
    }
    return tamA;
}
/* MAIN */
int main(){
    int numeraoA [1002];
    int numeraoB [1001];
    char strNumeraoA [1003];
    char strNumeraoB [1003];
    char sinal;
    int n, tamA, tamB;


    while(0==0){
        zeraVetor(numeraoA, 1002);
        zeraVetor(numeraoB, 1001);

        fgets(strNumeraoA, 1002, stdin);

        if(strNumeraoA[0] == 'F'){
            break;
        }

        /*Transforma vetor de string em inteiro e devolve o tamanho do vetor A*/
        tamA = criaNumeraoDeString(strNumeraoA, numeraoA);

        fgets(strNumeraoB, 1002, stdin);
        tamB = criaNumeraoDeString(strNumeraoB, numeraoB);
        /*Recebe o sinal da operação*/
        scanf ("%c", &sinal);

        /*Foi criado condições utilizando o jogo de sinais para facilitar
          as operações (como por exemplo, uma soma de dois numeros com
          sinais diferentes se transormaria em uma subtração e assim por
          diante)*/
        if(sinal == '+'){
            if(numeraoA[0]==numeraoB[0]){
                tamA = soma (numeraoA,tamA, numeraoB, tamB);
            }
            else{
                tamA = subtrai (numeraoA,tamA, numeraoB, tamB);
            }
            imprimeNumerao (numeraoA, tamA);
        }
        else if (sinal == '-'){
            if(numeraoA[0]==numeraoB[0]){
                tamA = subtrai (numeraoA, tamA, numeraoB, tamB);
            }
            else{
                tamA = soma (numeraoA,tamA, numeraoB, tamB);
            }
            imprimeNumerao (numeraoA, tamA);
        }
        // fgets(strNumeraoA, 1002, stdin);
    }
    return 0;
}
