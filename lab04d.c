/*Esse programa foi desenvolvido para auxiliar a JMob no desenvolvimento do seus produtos. Para ver se seu produto esta equilibrado ou nao e ver seu peso.
Tendo como entrada os pesos e as distacias do peso à corda presa na barra barra(caso o peso seja 0, significa que há uma no barra pendurada nessa extremidade
E tendo como saida o peso total do produto e dizendo se esta totalmente equilibrado ou nao.
Rafael Hajime Mori              RA:21045116*/

#include <stdio.h>
/*aqui foi declarado uma variavel global para analise do equilibrio do produto*/
int equilibrio=0  ;
/*Utilizando a recursão, foi criado uma função que le os pesos, soma os pesos e, caso esteja desequilibrado, soma 1 na variavel global*/
int pesoTot(){
    int peso,esquerda, aux, direita, Pe, De, Pd, Dd;
    scanf("%d %d %d %d", &Pe, &De, &Pd, &Dd);
    /*Caso algum dos pesos sejam igual a 0, é chamado a propria função novamente*/
    if(Pe==0){
        Pe=pesoTot();
    }
    if(Pd==0){
        Pd=pesoTot();
    }
    /*soma dos pesos*/
    peso=Pe+Pd;
    /*analise do equilibrio do produto*/
    esquerda=Pe*De;
    direita=Pd*Dd;
    if(esquerda!=direita){
        equilibrio += 1;
    }
    return peso;

}

int main(){
    int a;
    a=pesoTot();

    if(equilibrio==0){
        printf("Mobile equilibrado\n");
    }
    else{
        printf("Mobile desequilibrado\n");
    }
    printf("Peso total: %d\n", a);
    return 0;
}
