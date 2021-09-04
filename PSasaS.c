#include <stdio.h>
#include <stdlib.h>

int ConReq (char reqf[100],char reqnf[100],char reqdom[100],char reqdado[100]){
    printf ("Analisando a consistencia dos requisitos.\n");
    printf ("Requisitos consistentes!!\n");
    int consist = 1;
    return consist;
}

int projeto(char reqf[100],char reqnf[100],char reqdom[100],char reqdado[100]){
    printf ("O projeto esta sendo desenvolvido com base nos requisitos funcionais, não funcionais, de dominio e de dados\n");
    printf ("O projeto esta quase pronto\n");
    printf ("O projeto esta pronto!!\n");
    int proj = 1;    
    return proj;
}
int construcao(int proj){
    printf ("Vamos criar agora o codigo com base no projeto! \n");
    printf ("Criando o codigo... \n");
    printf ("Codigo criado com sucesso!!!!\n");
    int codigo = 1;
    
    return codigo;
}

int testeuni (int codigo){
    int resultadoesperado = 1;
    printf("Testando código...\n");
    if(resultadoesperado == 1){
        printf("Teste unitário terminado com sucesso.\n");
        return 1;
    }
    else{
        printf("Teste unitário falhou, melhor rever a parte da construção do codigo.\n");
        return 0;
    }
}
int testealfa(int codigo){
    int resultadoesperado = 1;
    printf("Iniciando teste alfa...\n");
    if(resultadoesperado == 1){
        printf("Teste alfa terminado com sucesso.\n");
        return 1;
    }
    else{
        printf("Teste alfa falhou, melhor rever a parte do projeto.\n");
        return 0;
    }
}

void implementa(int codigo){
    printf("Implementando código\n");
    printf("Software construído com sucesso!\n");
    return;
}



int main(){
    //Os requisitos foram tratatados como strings de tamanho  100 para representar didaticamente como uma concatenação dos requisitos de cada tipo
    char reqf[100], reqnf[100], reqdom[100], reqdado[100];
    //A seguir é criado uma funçao que vai ver a consistencia dos requisitos
    int consistReq = 0;
    int cod;
    while (consistReq == 0){
        consistReq = ConReq (reqf, reqnf, reqdom, reqdado);
    }
    int passoutestealfa = 0, passoutesteuni = 0;
    
    while(passoutestealfa == 0){       
        int proj = projeto (reqf,reqnf,reqdom,reqdado);
        while(passoutesteuni == 0){
            cod = construcao (proj);
            passoutesteuni = testeuni(cod);
            
            if(passoutesteuni == 0){
                printf ("Melhor rever algo na parte da construcao do codigo\n");
            }
        }
        passoutestealfa = testealfa(cod);
        if(passoutestealfa == 0){
            printf ("Melhor rever algo na parte do projeto\n");
        }
    }
    if(passoutesteuni == 1 && passoutestealfa == 1){
        implementa(cod);

    }
    return 0;
}