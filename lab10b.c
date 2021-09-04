/*o objetivo deste laboratorio eh implementar um codigo que leia os resultados de partidas de futebol, e dê como saida a tabela de pontos com seus criterios de desempate
Rafael Hajime Mori    RA: 21045116*/
#include <stdio.h>
#include <string.h>

/* Tamanho maximo de um nome de time */
#define MAX_NOME 26
/* Numero maximo de partidas */
#define MAX_TIMES 400

struct Time {
    char nome[MAX_NOME];
    int pontos;
    int gols_feitos;
    int saldo_gols;
    int num_vitorias;
};
typedef struct Time Time;

/* Atualiza os atributos de um time na tabela de classificacao */
void atualiza_tabela(Time tabela[], int *num_times, char *nome, int gols_feitos, int gols_sofridos) {
	int i, pos;
	/* busca o time na tabela */
	pos = -1;
	for (i = 0; i< *num_times && pos == -1; i++){
		if (strcmp(nome, tabela[i].nome) == 0)
			pos = i;
	}

	/*se o time nao esta na tabela... */
	if (pos == -1){
		pos = *num_times;
		(*num_times)++;
		strcpy (tabela[pos].nome, nome);
		tabela[pos].gols_feitos = gols_feitos;
		if (gols_feitos > gols_sofridos){
			tabela[pos].pontos = 3;
			tabela[pos].num_vitorias = 1;
		}
		else if (gols_feitos == gols_sofridos){
			tabela[pos].pontos = 1;
		}
		tabela[pos].saldo_gols = gols_feitos - gols_sofridos;
		return;
	}

	/* se acho o time na tabela */
	tabela[pos].gols_feitos += gols_feitos;
	if (gols_feitos > gols_sofridos){
		tabela[pos].pontos += 3;
		tabela[pos].num_vitorias += 1;
	}
	else if (gols_feitos == gols_sofridos){
		tabela[pos].pontos += 1;
	}
	tabela[pos].saldo_gols += (gols_feitos - gols_sofridos);
}

/* Determina qual dos dois times eh o mais bem classificado.
 * Retorna 1 se t1 é o melhor e 0 caso contrário */
int eh_maior(Time t1, Time t2) {
	if (t1.pontos > t2.pontos){
		return 1;
	}
	else {
		if (t1.pontos == t2.pontos){
			if (t1.num_vitorias > t2.num_vitorias){
				return 1;
			}
			else{
				if (t1.num_vitorias == t2.num_vitorias){
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
		}
	}




    return 0;
}

void troca (Time *t1, Time *t2){
	Time aux;
	aux = *t1;
	*t1 = *t2;
	*t2 = aux;

	return;
}


/* Ordena a tabela de times por selection sort */
void ordena_times(Time tabela[], int n) {

	int i, j, max;

	for (i = 0; i < n; i++){
		max = i;
		for (j = i+1; j < n; j++){
			if (eh_maior (tabela[j], tabela[max]) == 1){
				max = j;
			}
		}
		troca (&tabela[i], &tabela[max]);
	}

}

int main() {

    int num_jogos, num_times, i;
    int gols1, gols2;
    char nome_time1[MAX_NOME], nome_time2[MAX_NOME];
    Time tabela[MAX_TIMES];

    /* Lendo a entrada */
    scanf("%d", &num_jogos);
    for (i = 0; i < num_jogos; i++) {
        scanf("%s %d x %d %s", nome_time1, &gols1, &gols2, nome_time2);
        atualiza_tabela(tabela, &num_times, nome_time1, gols1, gols2);
        atualiza_tabela(tabela, &num_times, nome_time2, gols2, gols1);
    }

    /* Ordenando a tabela de times */
    ordena_times(tabela, num_times);

    /* Escrevendo a saida */
    for (i = 0; i < num_times; i++) {
        printf("%-30s %5d %5d %5d %5d\n", tabela[i].nome, tabela[i].pontos,
                tabela[i].num_vitorias, tabela[i].saldo_gols, tabela[i].gols_feitos);
    }

    return 0;
}
