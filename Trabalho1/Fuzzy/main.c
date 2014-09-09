#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//veteranice
#define VET 100
#define VETBAIXAI 0 //baixa inicial
#define VETBAIXAF 50//baixa final
#define VETMEDIAI 35//media inicial
#define VETMEDIAF 75//media final
#define VETALTAI 60//alta inicial
#define VETALTAF 100//alta final

//media
#define MED 100
#define MEDBAIXAI 0//baixa inicial
#define MEDBAIXAF 50//baixa final
#define MEDMEDIAI 40//media inicial
#define MEDMEDIAF 80//media final
#define MEDALTAI 70//alta inicial
#define MEDALTAF 100//alta final

//reincidencia
#define REI 100
#define REIBAIXAI 0//baixa inicial
#define REIBAIXAF 60//baixa final
#define REIMEDIAI 40//media inicial
#define REIMEDIAF 80//media final
#define REIALTAI 60//alta inicial
#define REIALTAF 100//alta final

//aceitação ****************************************ARRUMAR OS DADOS
#define ACEMBAIXAI 0//muito baixa inicial
#define ACEMBAIXAF 10//muito baixa final
#define ACEBAIXAI 20//baixa final
#define ACEBAIXAF 30//baixa inicial
#define ACEMEDIAI 40//media inicial
#define ACEMEDIAF 50//media final
#define ACEALTAI 60//alta inicial
#define ACEALTAF 70//alta final
#define ACEMALTAI 80//muito alta inicial
#define ACEMALTAF 90//muito alta final

#define T100 100

typedef struct _aluno{
	char nome[T100 + 1];
	int v; // veteranice
	int m; // media do curso
	int r; // reincidencia
	int a; // indice de aceitação
	struct _aluno *prox;
}TAluno;

typedef struct _lista{
	TAluno *head;
	int qtd;
}TLista;


TLista *initLista();
int inserirAluno(TLista *lista);
void imprimeMenu();
void imprimirAluno(TLista *lista);
void calcAceitacao(TAluno *aluno);
void limpaLista(TLista *lista);

TLista *initLista(){
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->head = NULL;
	novo->qtd = 0;
	
	return novo;
}

int inserirAluno(TLista *lista){
	TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
	system("clear");
	if(novo != NULL){
		double media = 0.0;

		printf("Digite o nome do aluno: ");
		scanf("%s[^\n]", novo->nome);
		getchar();
		do{
			printf("Digite o periodo do aluno: ");
			scanf("%d", &novo->v);
			novo->v *= 10;
		} while(novo->v < 0 || novo->v > VET);

		do{
			printf("Digite a media do aluno: ");
			scanf("%lf", &media);
			novo->m = (int)(media * 10);
		} while(novo->m < 0 || novo->m > MED);

		do{
			printf("Digite a quantidade de reincidencia do aluno: ");
			scanf("%d", &novo->r);
			novo->r = novo->r * 20;
			if(novo->r > 100) novo->r = 100;
		} while(novo->r < 0);
		
		novo->prox = NULL;
		novo->a = T100;
	}else{
		printf("Falha ao criar aluno!\n");
		return -1;
	}
	
	calcAceitacao(novo);
	
	if(lista->head == NULL){
		lista->head = novo;
	}else{
		TAluno *aux = lista->head;
		TAluno *ant = NULL;

		if(lista->head->prox == NULL){
			if(lista->head->a >= novo->a){//se aux é maior que novo **Verificar
				novo->prox = lista->head;
				lista->head = novo;
			}else{
				novo->prox  = lista->head->prox;
				lista->head = novo;
			}
		}else{
			while(aux->prox != NULL){
				ant = aux;
				aux = aux->prox;
				if(aux->a < novo->a){//se aux é maior que novo
					if (lista->head == aux){
						novo->prox = lista->head->prox;
						lista->head = novo;
					}else{
						novo->prox = ant->prox;
						ant->prox = novo;
					}
				}else{}
					
			}
		}
	}
	lista->qtd += 1;
	printf("Aluno[%d] criado com sucesso!\n", lista->qtd);
	return 0;
}

void calcAceitacao(TAluno *aluno){
	/* 1 - muito baixo
	 * 2 - baixo
	 * 3 - medio
	 * 4 - alto
	 * 5 - muito alto
	 */
	int conjuntoAceitacao = 0;
	
	int indice_calculado = 0;
	
	if(aluno->v >= VETBAIXAI && aluno->v <= VETBAIXAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / baixo / baixo
				//mapear para conjunto
				conjuntoAceitacao = 1;
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / baixo / medio
				//mapear para conjunto
				conjuntoAceitacao = 1;
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / baixo / alto
				//mapear para conjunto
				conjuntoAceitacao = 1;
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / medio / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / medio / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / medio / alto
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / alto / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / alto / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / alto / alto
			}
		}
	}
	if(aluno->v >= VETMEDIAI && aluno->v <= VETMEDIAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / baixo / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / baixo / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / baixo / alto
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / medio / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / medio / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / medio / alto
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / alto / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / alto / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / alto / alto
			}
		}
	}
	if(aluno->v >= VETALTAI && aluno->v <= VETALTAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / baixo / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / baixo / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / baixo / alto
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / medio / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / medio / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / medio / alto
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / alto / baixo
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / alto / medio
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / alto / alto
			}
		}
	}
	
	if(conjuntoAceitacao >= ACEMBAIXAI && conjuntoAceitacao <= ACEMBAIXAF){
		
	}
	if(conjuntoAceitacao >= ACEBAIXAI && conjuntoAceitacao <= ACEBAIXAF){
		
	}
	if(conjuntoAceitacao >= ACEMEDIAI && conjuntoAceitacao <= ACEMEDIAF){
		
	}
	if(conjuntoAceitacao >= ACEALTAI && conjuntoAceitacao <= ACEALTAF){
		
	}
	if(conjuntoAceitacao >= ACEMALTAI && conjuntoAceitacao <= ACEMALTAF){
		
	}
	//mapear a variavel no conjunto e aplicar regra max/min
	//calcular o indice de aceitação
	aluno->a = indice_calculado;
}

void imprimeMenu(){
	printf("**************************************************\n");
	printf("*   1 - Inserir aluno                            *\n");
	printf("*   2 - Imprimir alunos cadastrados              *\n");
	printf("*                                                *\n");
	printf("*   0 - Sair                                     *\n");
	printf("**************************************************\n");
	return;
}

void imprimirAluno(TLista *lista){
	TAluno *aux = lista->head;
	if(aux == NULL) printf("Lista de alunos vazia!\n");
	else{
		while(aux != NULL){
			printf("Imprime Nome: %s\n", aux->nome);
			aux = aux->prox;
		}
	}
}

void limpaLista(TLista *lista){//verificar
	TAluno *aux = lista->head;
	TAluno *prox = NULL;
	while(aux != NULL){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	free(lista->head);
	free(lista);
	printf("Limpou dados\n");
}

int main(){
	TLista *lista = (TLista*)malloc(sizeof(TLista));
	lista = initLista();
	
	int opc = 0;
	
	do{
		imprimeMenu();
		printf("Opcao: ");
		scanf("%d", &opc);
		
		if(opc == 1){
			inserirAluno(lista);
		}else if(opc == 2){
			imprimirAluno(lista);
		}

	} while(opc != 0);
	
	limpaLista(lista);
	return 0;
}
/*
	if(veteranice >= 0 && veteranice <= 50){ // veteranice conjunto baixo
		if(reincidencia >= 0  && reincidencia <=60){ // reincidencia conjutno baixo
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 40 && reincidencia <= 80){ // reincidencia conjunto medio
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 60 && reincidencia <= 100){ // reincidencia conjunto alto
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
	}
	if(veteranice >= 35 && veteranice <= 75){ // veteranice conjunto medio
		if(reincidencia >= 0  && reincidencia <=60){ // reincidencia conjutno baixo
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 40 && reincidencia <= 80){ // reincidencia conjunto medio
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 60 && reincidencia <= 100){ // reincidencia conjunto alto
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
	}
	if(veteranice >= 60 && veteranice <= VET){ // veteranice conjunto alto
		if(reincidencia >= 0  && reincidencia <=60){ // reincidencia conjutno baixo
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 40 && reincidencia <= 80){ // reincidencia conjunto medio
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
		if(reincidencia >= 60 && reincidencia <= 100){ // reincidencia conjunto alto
			if(media >= 0 && media <= 50){ // media conjunto baixo
			}
			if(media >= 40 && media <= 80){ // media conjunto medio
			}
			if(media >= 70 && media <= 100){ // media conjunto alto
			}
		}
	}
*/

