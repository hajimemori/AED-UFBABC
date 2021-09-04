/*O programa a seguir foi desenvolvido para ser utilizado na mudança de base de um numero em base 10.
Como entrada ele contem um numero que sera mudado de base e outro numero que sera usado como base.
Como saida ele mostra o numero na outra base em ordem invertida.
Rafael Hajime Mori    RA:21045116*/
#include <stdio.h>

int main(){
    int X, Y, rest, aux;
    scanf("%d", &X);
    scanf("%d", &Y);
    /*Sera utilizado aux como numero que ira variar ao longo do programa*/
    aux=X;
    while(aux!=0){
        rest=aux%Y;
        aux=aux/Y;
        printf("%d", rest);
    }
    printf("\n");
    return 0;
}
