#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char caractere[100];
    int top;
} pilha;

pilha criar_pilha(){
    pilha p;
    p.top = -1;
    return p;
}

pilha *push (pilha *p, char x){
    if (p->top+1 < 100){
        ++p->top;
        p->caractere[p->top] = x;
        return p;
    }
    else{
        return NULL;
    }
}

pilha *pop (pilha *p){
    if (p->top == -1){
        return NULL;
    }
    else{
        --p ->top;
        return &(p->caractere[p->top+1]);
    }
}
