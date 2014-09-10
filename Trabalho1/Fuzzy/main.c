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
#define NRegras 39

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
int calcMin(int a, int b, int c);
int calcIndiceAceitacao(int vet[T100], int indiceA, int indiceB);
void initVetAceitacao(int vet[T100]);
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
//	system("clear");
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
	
	if(lista->head == NULL){//adiciona no início
		lista->head = novo;
	}else{
		TAluno *aux = lista->head;
		TAluno *ant = NULL;
		//adiciona por ordem de aceitação
		while(1){
			if(aux->a > novo->a){
				//busca proximo elemento da lista
				ant = aux;
				aux  = aux ->prox;
				if(aux == NULL){//se chegou ao fim da lista, insere
					ant->prox = novo;
					break;
				}
			}else{
				if(lista->head == aux){ //insere no inicio da lista
					novo->prox = lista->head;
					lista->head = novo;
					break;
				}else{ //insere no meio
					novo->prox = aux;
					ant->prox = novo;
					break;
				}
			}
		}
	}
	lista->qtd += 1;
	printf("Aluno[%d] criado com sucesso!\n", lista->qtd);
	return 0;
}

int calcMin(int a, int b, int c){
	int min = a;
	if(min >= b) min = b;
	if(min >= c) min = c;
	
	return min;
}

void calcAceitacao(TAluno *aluno){
	/* 1 - muito baixo
	 * 2 - baixo
	 * 3 - medio
	 * 4 - alto
	 * 5 - muito alto
	 */
	int conjuntoAceitacao[NRegras];
	int indiceAceitacao[T100];
	initVetAceitacao(indiceAceitacao);
	int minAluno = 0;
	int pos = 0, i = 0, j = 0;
	int indiceA = 0, indiceB = 0; // menor indice, maior indice
	
	if(aluno->v > 0 && aluno->r > 0 && aluno->m > 0){
		minAluno = calcMin(aluno->v, aluno->r, aluno->m); // pega o min
	}else{
		aluno->a = -1;
		return;
	}
	
/*	for(i=0; i<T100; i++){
		printf("vetor: %d\t%d\n", indiceAceitacao[i], i);
	}
*/
	
	if(aluno->v >= VETBAIXAI && aluno->v <= VETBAIXAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / baixo / baixo
				//mapear para conjunto
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / baixo / medio
				//mapear para conjunto
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / baixo / alto
				//mapear para conjunto
				conjuntoAceitacao[pos++] = 2; // baixa
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / medio / baixo
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / medio / medio
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / medio / alto
				conjuntoAceitacao[pos++] = 2; // baixa
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / alto / baixo
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / alto / medio
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / alto / alto
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
	}
	if(aluno->v >= VETMEDIAI && aluno->v <= VETMEDIAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / baixo / baixo
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / baixo / medio
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / baixo / alto
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / medio / baixo
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / medio / medio
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / medio / alto
				conjuntoAceitacao[pos++] = 4; // alto
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / alto / baixo
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / alto / medio
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// medio / alto / alto
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
	}
	if(aluno->v >= VETALTAI && aluno->v <= VETALTAF){
		if(aluno->r >= REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / baixo / baixo
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / baixo / medio
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / baixo / alto
				conjuntoAceitacao[pos++] = 4; // alto
			}
		}
		if(aluno->r >= REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / medio / baixo
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / medio / medio
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / medio / alto
				conjuntoAceitacao[pos++] = 5; // muito alto
			}
		}
		if(aluno->r >= REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m >= MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / alto / baixo
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m >= MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / alto / medio
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m >= MEDALTAI && aluno->m <= MEDALTAF){
				// alto / alto / alto
				conjuntoAceitacao[pos++] = 5; // muito alto
			}
		}
	}
	
	for(i = 0; i < NRegras && i < pos; i++){
		if(conjuntoAceitacao[i] == 1){ // na posição de I disparou a regra no conjunto muito baixa
			for(j = ACEMBAIXAI; j <= ACEMBAIXAF; j++){
				if(minAluno > indiceAceitacao[j]){
					indiceAceitacao[j] = minAluno;
					if(indiceA > j) indiceA = j;
					if(indiceB < j) indiceB = j;
				}
			}
		}
		if(conjuntoAceitacao[i] == 2){
			for(j = ACEBAIXAI; j <= ACEBAIXAF; j++){
				if(minAluno > indiceAceitacao[j]){
					indiceAceitacao[j] = minAluno;
					if(indiceA > j) indiceA = j;
					if(indiceB < j) indiceB = j;
				}
			}
		}
		if(conjuntoAceitacao[i] == 3){
			for(j = ACEMEDIAI; j <= ACEMEDIAF; j++){
				if(minAluno > indiceAceitacao[j]){
					indiceAceitacao[j] = minAluno;
					if(indiceA > j) indiceA = j;
					if(indiceB < j) indiceB = j;
				}
			}
		}
		if(conjuntoAceitacao[i] == 4){
			for(j = ACEALTAI; j <= ACEALTAF; j++){
				if(minAluno > indiceAceitacao[j]){
					indiceAceitacao[j] = minAluno;
					if(indiceA > j) indiceA = j;
					if(indiceB < j) indiceB = j;
				}
			}
		}
		if(conjuntoAceitacao[i] == 5){
			for(j = ACEMALTAI; j <= ACEMALTAF; j++){
				if(minAluno > indiceAceitacao[j]){
					indiceAceitacao[j] = minAluno;
					if(indiceA > j) indiceA = j;
					if(indiceB < j) indiceB = j;
				}
			}
		}
	}
	
	//calcular o indice de aceitação
	aluno->a = calcIndiceAceitacao(indiceAceitacao, indiceA, indiceB);
}

int calcIndiceAceitacao(int vet[T100], int a, int b){
	int i, j;
	int areaA = vet[a], areaB = vet[b];
	for(i = a, j = b; i <= j; ){
		if(areaA <= areaB){
			areaA += vet[i++];
		}else{
			areaB += vet[j--];
		}
	}
	return vet[--i];
}

void initVetAceitacao(int vet[T100]){
	int i;
	
	for(i=0; i < T100; i++){
		vet[i] = 0;
	}
	return;
}

void imprimeMenu(){
	printf("\n**************************************************\n");
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
		printf("\n\tAlunos cadastrados:\n");
		while(aux != NULL){
			printf("Nome: %s\tAceitacao: %d\n", aux->nome, aux->a);
			aux = aux->prox;
		}
	}
}

void limpaLista(TLista *lista){//verificar
	TAluno *aux = lista->head;
	TAluno *prox = NULL;
	while(aux != NULL){
		printf("Limpando aluno: %s!\n", aux->nome);
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
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

