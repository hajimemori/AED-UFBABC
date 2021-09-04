/**/
#include <stdio.h>

int main()
{
    int M, N, j, i;
    scanf ("%d", &M);
    scanf ("%d", &N);
    int A[M];
    for(i=0; i<M; i++){
        scanf("%d", &A[i]);
    }
    for(j=0; j<M; j++){
        printf("%d \n", A[j]);
    }

    return 0;
}

