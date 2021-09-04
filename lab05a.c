#include <stdio.h>
int analisar (int n1, char silence[], int n2, char RNA[]){
    int i, j, aux;
    for(i=0; i<n2; i++){
        j=0;
        aux=i;
        if(silence[j]==RNA[i]){
            for(j=0; j<n1; j++, aux++){
                if(RNA[aux]!=silence[j]){
                    break;
                }
                if(j==n1-1){
                    return i;
                }
            }
        }
    }
    return -1;
}

void transformar (int n, char v[]){
    int i;
    for(i=0; i<n; i++){
        if (v[i]== 'U'){
            v[i] = 'A';
        }
        else if (v[i]== 'A'){
            v[i] = 'U';
        }
        else if (v[i]== 'C'){
            v[i] = 'G';
        }
        else if (v[i]== 'G'){
            v[i] = 'C';
        }
    }
}

void inverter (int n, char v[]){
    int i, j;
    char aux;
    j=n;
    i=0;
    while(i<((n+1)/2)){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i++;
        j--;
    }

}

int main()
{
    int nPrin, nSec, i, j, retorno;
    scanf("%d", &nPrin);
    scanf("%d", &nSec);

    char RNA[nPrin+1];
    char silence[nSec+1];
    for (i=0; i<=nPrin; i++){
        scanf("%c", &RNA[i]);
    }
    for (j=0; j<=nSec; j++){
        scanf("%c", &silence[j]);
    }
    inverter(nSec, silence);
    transformar (nSec, silence);
    /*for(i=0; i<nSec; i++){
        printf ("%c", silence[i]);
    }*/
    retorno =  analisar (nSec, silence, nPrin, RNA);
    if(retorno!=-1){
        printf("Silenciado em %d\n", retorno);
    }
    else{
        printf("Nao silenciado\n");
    }
    return 0;
}
