#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//veteranice
#define VETBAIXAI 0 //baixa inicial
#define VETBAIXAF 50//baixa final
#define VETMEDIAI 35//media inicial
#define VETMEDIAF 75//media final
#define VETALTAI 60//alta inicial
#define VETALTAF 100//alta final

//media
#define MEDBAIXAI 0//baixa inicial
#define MEDBAIXAF 50//baixa final
#define MEDMEDIAI 40//media inicial
#define MEDMEDIAF 80//media final
#define MEDALTAI 70//alta inicial
#define MEDALTAF 100//alta final

//reincidencia
#define REIBAIXAI 0//baixa inicial
#define REIBAIXAF 60//baixa final
#define REIMEDIAI 40//media inicial
#define REIMEDIAF 80//media final
#define REIALTAI 60//alta inicial
#define REIALTAF 100//alta final

//aceitação
#define ACEMBAIXAI 0//muito baixa inicial
#define ACEMBAIXAF 30//muito baixa final
#define ACEBAIXAI 20//baixa final
#define ACEBAIXAF 50//baixa inicial *** arrumar
#define ACEMEDIAI 30//media inicial
#define ACEMEDIAF 60//media final
#define ACEALTAI 50//alta inicial
#define ACEALTAF 80//alta final
#define ACEMALTAI 70//muito alta inicial
#define ACEMALTAF 100//muito alta final

#define T100 100
#define NREGRAS 39

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
void initVet(int vet[T100], int conjuntoAceitacao[NREGRAS], int conjuntoValores[NREGRAS]);
void imprimeMenu();
void imprimirAluno(TLista *lista);
void calcAceitacao(TAluno *aluno);
void limpaLista(TLista *lista);
void limpaTela();

//valores da função veteranice baixa mapeadas no vetor
int vetVeteraniceB[T100] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
							45, 40, 35, 30, 25, 20, 15, 10, 5, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função veteranice media mapeadas no vetor
int vetVeteraniceM[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 5, 10, 15, 20, 25,
							30, 35, 40, 45, 50, 55, 60, 65, 70, 75,
							80, 85, 90, 95, 100, 95, 90, 85, 80, 75,
							70, 65, 60, 55, 50, 45, 40, 35, 30, 25,
							20, 15, 10, 5, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função veteranice alta mapeadas no vetor
int vetVeteraniceA[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
							55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
//valores da função reincidencia baixa mapeadas no vetor
int vetReincidenciaB[T100] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 97, 94, 91, 89, 86,
							83, 80, 77, 74, 71, 69, 66, 63, 60, 57,
							54, 51, 49, 46, 43, 40, 37, 34, 31, 29,
							26, 23, 20, 17, 14, 11, 9, 6, 3, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função reincidencia media mapeadas no vetor
int vetReincidenciaM[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
							55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
							95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
							45, 40, 35, 30, 25, 20, 15, 10, 5, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função reincidencia alta mapeadas no vetor
int vetReincidenciaA[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							7, 13, 20, 27, 33, 40, 47, 53, 60, 67,
							73, 80, 87, 93, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
							100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
//valores da função media baixa mapeadas no vetor
int vetMediaB[T100] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 93, 87, 80, 73, 67,
						60, 53, 47, 40, 33, 27, 20, 13, 7, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função media media mapeadas no vetor
int vetMediaM[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 4, 8, 12, 16, 20,
						24, 28, 32, 36, 40, 44, 48, 52, 56, 60,
						64, 68, 72, 76, 80, 84, 88, 92, 96, 100,
						96, 92, 88, 84, 80, 76, 72, 68, 64, 60,
						56, 52, 48, 44, 40, 36, 32, 28, 24, 20,
						16, 12, 8, 4, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função media alta mapeadas no vetor
int vetMediaA[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						7, 13, 20, 27, 33, 40, 47, 53, 60, 67,
						73, 80, 87, 93, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
//valores da função aceitacao muito baixa mapeadas no vetor
int vetAceitacaoMB[T100] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						90, 80, 70, 60, 50, 40, 30, 20, 10, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função aceitacao baixa mapeadas no vetor
int vetAceitacaoB[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
						95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
						45, 40, 35, 30, 25, 20, 15, 10, 5, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função aceitacao media mapeadas no vetor
int vetAceitacaoM[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
						55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
						95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
						45, 40, 35, 30, 25, 20, 15, 10, 5, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função aceitacao alta mapeadas no vetor						
int vetAceitacaoA[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
						55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
						90, 80, 70, 60, 50, 40, 30, 20, 10, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//valores da função aceitacao muito alta mapeadas no vetor
int vetAceitacaoMA[T100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
						100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

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
			if(novo->v >= 100) novo->v = 99;
		} while(novo->v < 0 || novo->v >= 100);

		do{
			printf("Digite a media do aluno: ");
			scanf("%lf", &media);
			novo->m = (int)(media * 10);
			if(novo->m >= 100) novo->m = 99;
		} while(novo->m < 0 || novo->m >= 100);

		do{
			printf("Digite a quantidade de reincidencia do aluno: ");
			scanf("%d", &novo->r);
			novo->r = novo->r * 20;
			if(novo->r >= 100) novo->r = 99;
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
	if(a == 0 || b == 0 || c == 0) return -1;
	int min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	
	return min;
}

void calcAceitacao(TAluno *aluno){
	/* 1 - muito baixo
	 * 2 - baixo
	 * 3 - medio
	 * 4 - alto
	 * 5 - muito alto
	 */
	int conjuntoAceitacao[NREGRAS];
	int conjuntoValores[NREGRAS];
	int indiceAceitacao[T100];
	initVet(indiceAceitacao, conjuntoAceitacao, conjuntoValores);
	
	//int minAluno = 0;
	int pos = 0, i = 0, j = 0;
	int indiceA = 0, indiceB = 0; // menor indice, maior indice
	
	if(aluno->v == 0 || aluno->r == 0 || aluno->m == 0){
		aluno->a = -1;
		return;
	}
	
	//o min dos valores é o indice nos vetores...
	//precisa identificar de qual entrada é o minAluno, se é de vet, rein, med... também ter cuidado com valores iguais no minAluno
	
	if(aluno->v > VETBAIXAI && aluno->v <= VETBAIXAF){
		if(aluno->r > REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / baixo / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaB[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / baixo / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaB[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / baixo / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaB[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
		}
		if(aluno->r > REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / medio / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaM[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / medio / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaM[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / medio / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaM[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
		}
		if(aluno->r > REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// baixo / alto / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaA[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// baixo / alto / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaA[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// baixo / alto / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceB[aluno->v], vetReincidenciaA[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
	}
	if(aluno->v > VETMEDIAI && aluno->v <= VETMEDIAF){
		if(aluno->r > REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / baixo / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaB[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 1; // muito baixa
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / baixo / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaB[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// medio / baixo / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaB[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
		if(aluno->r > REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / medio / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaM[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 2; // baixa
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / medio / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaM[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// medio / medio / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaM[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
		}
		if(aluno->r > REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// medio / alto / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaA[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// medio / alto / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaA[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// medio / alto / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceM[aluno->v], vetReincidenciaA[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
		}
	}
	if(aluno->v > VETALTAI && aluno->v <= VETALTAF){
		if(aluno->r > REIBAIXAI && aluno->r <= REIBAIXAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / baixo / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaB[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / baixo / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaB[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 3; // media
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// alto / baixo / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaB[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
		}
		if(aluno->r > REIMEDIAI && aluno->r <= REIMEDIAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / medio / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaM[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / medio / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaM[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// alto / medio / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaM[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 5; // muito alto
			}
		}
		if(aluno->r > REIALTAI && aluno->r <= REIALTAF){
			if(aluno->m > MEDBAIXAI && aluno->m <= MEDBAIXAF){
				// alto / alto / baixo
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaA[aluno->r], vetMediaB[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m > MEDMEDIAI && aluno->m <= MEDMEDIAF){
				// alto / alto / medio
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaA[aluno->r], vetMediaM[aluno->m]);
				conjuntoAceitacao[pos++] = 4; // alto
			}
			if(aluno->m > MEDALTAI && aluno->m <= MEDALTAF){
				// alto / alto / alto
				conjuntoValores[pos] = calcMin(vetVeteraniceA[aluno->v], vetReincidenciaA[aluno->r], vetMediaA[aluno->m]);
				conjuntoAceitacao[pos++] = 5; // muito alto
			}
		}
	}
		
	for(i = 0; i < NREGRAS && i < pos; i++){
		if(conjuntoAceitacao[i] == 1){ // na posição de I disparou a regra no conjunto muito baixa
			for(j = ACEMBAIXAI; j < ACEMBAIXAF; j++){
				if(vetAceitacaoMB[j] < conjuntoValores[i]){
					if(indiceAceitacao[j] < vetAceitacaoMB[j]){
						indiceAceitacao[j] = vetAceitacaoMB[j];
					}
				}else{
					if(indiceAceitacao[j] < conjuntoValores[i]){
						indiceAceitacao[j] = conjuntoValores[i];
					}
				}
				if(indiceA > j) indiceA = j;
				if(indiceB < j) indiceB = j;
			}
		}
		if(conjuntoAceitacao[i] == 2){
			for(j = ACEBAIXAI; j < ACEBAIXAF; j++){
				if(vetAceitacaoB[j] < conjuntoValores[i]){
					if(indiceAceitacao[j] < vetAceitacaoB[j]){
						indiceAceitacao[j] = vetAceitacaoB[j];
					}
				}else{
					if(indiceAceitacao[j] < conjuntoValores[i]){
						indiceAceitacao[j] = conjuntoValores[i];
					}
				}
				if(indiceA > j) indiceA = j;
				if(indiceB < j) indiceB = j;
			}
		}
		if(conjuntoAceitacao[i] == 3){
			for(j = ACEMEDIAI; j < ACEMEDIAF; j++){
				if(vetAceitacaoM[j] < conjuntoValores[i]){
					if(indiceAceitacao[j] < vetAceitacaoM[j]){
						indiceAceitacao[j] = vetAceitacaoM[j];
					}
				}else{
					if(indiceAceitacao[j] < conjuntoValores[i]){
						indiceAceitacao[j] = conjuntoValores[i];
					}
				}
				if(indiceA > j) indiceA = j;
				if(indiceB < j) indiceB = j;
			}
		}
		if(conjuntoAceitacao[i] == 4){
			for(j = ACEALTAI; j < ACEALTAF; j++){
				if(vetAceitacaoA[j] < conjuntoValores[i]){
					if(indiceAceitacao[j] < vetAceitacaoA[j]){
						indiceAceitacao[j] = vetAceitacaoA[j];
					}
				}else{
					if(indiceAceitacao[j] < conjuntoValores[i]){
						indiceAceitacao[j] = conjuntoValores[i];
					}
				}
				if(indiceA > j) indiceA = j;
				if(indiceB < j) indiceB = j;
			}
		}
		if(conjuntoAceitacao[i] == 5){
			for(j = ACEMALTAI; j < ACEMALTAF; j++){
				if(vetAceitacaoMA[j] < conjuntoValores[i]){
					if(indiceAceitacao[j] < vetAceitacaoMA[j]){
						indiceAceitacao[j] = vetAceitacaoMA[j];
					}
				}else{
					if(indiceAceitacao[j] < conjuntoValores[i]){
						indiceAceitacao[j] = conjuntoValores[i];
					}
				}
				if(indiceA > j) indiceA = j;
				if(indiceB < j) indiceB = j;
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
	
	return --i;
}

void initVet(int vet[T100], int conjuntoAceitacao[NREGRAS], int conjuntoValores[NREGRAS]){
	int i;
	
	for(i=0; i < T100; i++){
		vet[i] = 0;
	}
	
	for(i=0; i < NREGRAS; i++){
		conjuntoAceitacao[i] = 0;
		conjuntoValores[i] = 0;
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
	limpaTela();
	TAluno *aux = lista->head;
	if(aux == NULL) printf("Lista de alunos vazia!\n\n");
	else{
		printf("\n\tAlunos cadastrados:\n\n");
		while(aux != NULL){
			printf("Nome: %s\t\t\tAceitacao: %d\n", aux->nome, aux->a);
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
	free(lista);
}

void limpaTela(){
	#ifdef LINUX
		system("clear");
	#elif WIN32
		system("cls");
	#else
		printf("Plataforma nao suportada\n");
	#endif
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
	imprimirAluno(lista);
	limpaLista(lista);
	return 0;
}
