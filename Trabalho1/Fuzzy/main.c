#include <stdio.h>
#include <stdlib.h>

#define VET 100
#define MED 100
#define REI 100

typedef struct _aluno{
	int v; // veteranice
	int m; // media do curso
	int r; // reincidencia
	int a; // indice de aceitação
	struct _aluno *prox;
}TAluno;

typedef struct _lista{
	TAluno *head;
}TLista;

TLista *initLista(){
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->head = NULL;
	
	return novo;
}

int inserirAluno(TpLista *lista){
	TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
	
	if(novo != NULL){
		double media = 0.0;
		do{
			printf("Digite o periodo do aluno: ");
			scanf("%d", novo->v);
			novo->v *= 10;
		} while(novo->v < 0 || novo->v > VET);

		do{
			printf("Digite a media do aluno: ");
			scanf("%lf", alunos->m);
			novo->m = (int)(mediaAux * 10);
		} while(novo->m < 0 || novo->m > MED);

		do{
			printf("Digite a quantidade de reincidencia do aluno: ");
			scanf("%d", novo->r);
			novo->r = novo->r * 20;
			if(novo->r > 100) novo->r = 100;
		} while(novo->r < 0);
	}
	return 0;
}

void imprimeMenu(){
	printf("**************************************************\n");
	printf("*   1 - Inserir aluno                            *\n");
	printf("*   2 - Imprimir alunos cadastrados              *\n");
	printf("*                                                *\n");
	printf("*   0 - Sair                                     *\n");
	printf("**************************************************\n");
}

int main(){
	TLista *lista = (TLista*)malloc(sizeof(TLista));
	lista = initLista();
	
	int opc = 0;
	
	do{
		imprimeMenu();
		printf("Opcao: ");
		scanf("%d", &opc);
		
		switch(&opc){
			case 1:
				inserirAluno(lista);
			
			case 2:
				imprimirAluno();
		}

	} while(&opc != 0);

/*	do{
		printf("Digite o periodo do aluno: ");
		scanf("%d", alunos->v);
		alunos->v *= 10;
	} while(alunos->v < 0 || alunos->v > VET);

	do{
		printf("Digite a media do aluno: ");
		scanf("%lf", alunos->m);
		alunos->m = (int)(mediaAux * 10);
	} while(alunos->m < 0 || alunos->m > MED);

	do{
		printf("Digite a quantidade de reincidencia do aluno: ");
		scanf("%d", alunos->r);
		alunos->r = alunos->r * 20;
		if(alunos->r > 100) alunos->r = 100;
	} while(alunos->r < 0);
*/
/*
	if(veteranice >= 0 && veteranice <= 50){ // veteranice conjunto baixo
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
	}
	if(veteranice >= 35 && veteranice <= 75){ // veteranice conjunto medio
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
	}
	if(veteranice >= 60 && veteranice <= VET){ // veteranice conjunto alto
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
		if(){
			if(){
			}
			if(){
			}
			if(){
			}
		}
	}
*/
    return 0;
}
