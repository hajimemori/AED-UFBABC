/*O programa a seguir tem como objetivo mostrar a classificação para as oitavas de finais da copa do mundo.
Tendo como entrada 48 resultado de jogos da copa do mundo
E tendo como saida a tabela de pontuação das seleçoes e os confrontos das oitavas de finais
Rafael Hajime Mori      RA: 21045116*/

#include <stdio.h>
#include <string.h>

#define MAX_TIMES 4
#define MAX_GRUPO 8
#define MAX_NOME 15

struct Time {
    char nome[16];
    int pontos;
    int saldo_gols;
    int gols_feitos;
    int gols_sofridos;
};
typedef struct Time Time;

/*Função que vai preencher as tabelas */
void atualiza_tabela(Time tabela[MAX_TIMES][MAX_GRUPO], int j, char *nome, int gols_feitos, int gols_sofridos, int *num_times){
    int i, pos;
	/* busca seleção na tabela */
	pos = -1;
	for (i = 0; i<4 && pos == -1; i++){
		if (strcmp(nome, tabela[i][j].nome) == 0){
			pos = i;
		}
	}
	/*se a seleção nao esta na tabela... */
	if (pos == -1){
		pos = *num_times;
		(*num_times)++;
		strcpy (tabela[pos][j].nome, nome);
		tabela[pos][j].gols_feitos = gols_feitos;
		tabela[pos][j].gols_sofridos = gols_sofridos;
		if (gols_feitos > gols_sofridos){
			tabela[pos][j].pontos = 3;
		}
		else if (gols_feitos == gols_sofridos){
			tabela[pos][j].pontos = 1;
		}
		else if (gols_feitos < gols_sofridos){
            tabela[pos][j].pontos = 0;
		}
		tabela[pos][j].saldo_gols = gols_feitos - gols_sofridos;

		return;
	}
	/* se acha a seleção na tabela */
	tabela[pos][j].gols_feitos += gols_feitos;
	tabela[pos][j].gols_sofridos += gols_sofridos;
	if (gols_feitos > gols_sofridos){
		tabela[pos][j].pontos += 3;
		}
	else if (gols_feitos == gols_sofridos){
		tabela[pos][j].pontos += 1;
	}
	tabela[pos][j].saldo_gols += (gols_feitos - gols_sofridos);
	return;

}

/*Função auxiliar à função de ordenar a tabela, contendo os criterios de desempate*/
int eh_maior(Time t1, Time t2){
    if (t1.pontos > t2.pontos){
		return 1;
	}
	else{
        if (t1.pontos == t2.pontos){
            if (t1.saldo_gols > t2.saldo_gols){
                return 1;
            }
            else{
                if (t1.saldo_gols == t2.saldo_gols){
                    if (t1.gols_feitos > t2.gols_feitos){
                        return 1;
                    }
                    else{
                       if (t1.gols_feitos == t2.gols_feitos){
                            if (strcmp(t1.nome, t2.nome) < 0){
                                return 1;
                            }
                        }
                    }
                }
            }
        }
	}
	return 0;
}

/*função que troca a posição de dois times*/
void troca (Time *t1, Time *t2){
	Time aux;
	aux = *t1;
	*t1 = *t2;
	*t2 = aux;

	return;
}

/*A função que ira ordenar a tabela*/
void ordena_times(Time tabela[][MAX_GRUPO]){
    int i, j, k, max;
    for (k = 0; k < 8; k++){
        for (i = 0; i < 4; i++){
            max = i;
            for (j = i+1; j < 4; j++){
                if (eh_maior (tabela[j][k], tabela[max][k]) == 1){
                    max = j;
                }
            }
            troca (&tabela[i][k], &tabela[max][k]);
        }
    }
}
/*função que printa na tela o comfronto das oitavas de finais*/
void print_oitavas (Time tabela[MAX_TIMES][MAX_GRUPO ], int i){
    int j;
    if(i%2==0){
        j=i+1;
    }
    else{
        j=i-1;
    }
    printf("%15s x %s", tabela[0][i].nome, tabela[1][j].nome);
    printf("\n");
}
 /*Função que printa o grupo que o programa ira exibir na sequencia*/
void print_Grupo(int i){
    if (i==0){
        printf ("Grupo A:\n");
    }
    else if (i==1){
        printf ("Grupo B:\n");
    }
    else if (i==2){
        printf ("Grupo C:\n");
    }
    else if (i==3){
        printf ("Grupo D:\n");
    }
    else if (i==4){
        printf ("Grupo E:\n");
    }
    else if (i==5){
        printf ("Grupo F:\n");
    }
    else if (i==6){
        printf ("Grupo G:\n");
    }
    else if (i==7){
        printf ("Grupo H:\n");
    }
}


int main()
{
    char nome_time1[MAX_NOME], nome_time2[MAX_NOME];
    int i, j, gols1, gols2, num_times;
    Time tabela[MAX_TIMES][MAX_GRUPO ];

    for (j=0; j<8; j++){
        num_times=0;
        for (i=0; i<6; i++){
            scanf("%s %d x %d %s", nome_time1, &gols1, &gols2, nome_time2);
            atualiza_tabela(tabela, j, nome_time1, gols1, gols2, &num_times);
            atualiza_tabela(tabela, j, nome_time2, gols2, gols1, &num_times);
        }
    }

    ordena_times(tabela);
    for (j=0; j<8; j++){
        print_Grupo(j);
        for (i=0; i<4; i++){
            printf("%-15s %3d %3d %3d %3d\n", tabela[i][j].nome, tabela[i][j].pontos, tabela[i][j].gols_feitos, tabela[i][j].gols_sofridos, tabela[i][j].saldo_gols);
        }
        printf ("\n");
    }
    printf ("Oitavas de final:\n");

    for(i=0; i<8; i++){
        print_oitavas (tabela, i);
    }
    return 0;
}
