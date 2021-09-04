/*Programa criado para ajudar a entender como o computador calcula logaritimos naturais. Por serie de Taylor (STA) e por função tangente hiperbólica (STH).
Tendo como entrada um numero que sera tirado o logaritimo natural, a quantidade de implementações em STA e a quantidade de implementações em STH.
Tendo como saida uma comparação inicialmente com o logaritimo feito pela propria função do computador, seguido pelo mesmo numero feito por STA e em seguida o numero feito por STH
Rafael Hajime Mori          RA:21045116*/

#include <stdio.h>
#include <math.h>

int main (){
    double Z, STA, STH;
    int I, J, p, q;
    scanf("%lf %d %d", &Z, &I, &J);
    printf("%.6lf ", log(Z));
    for(p=1; p<=I; p++){
        STA += -(pow((-1),p))*(pow((Z-1),p)/p);
    }
    printf("%.6lf ",STA);
    for(q=1; q<=2*J; q=q+2){
        STH+=(pow(((Z-1)/(Z+1)), q)/q);
    }
    STH=STH*2;
    printf("%.6lf\n",STH);

    return 0;
}
