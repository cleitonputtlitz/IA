#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TM 9

void criaArquivoEntrada(){
	FILE *f = fopen("entrada.txt", "w+");
	
	int m[TM][TM];
	int i, j, numero;
	
	for(i=0; i < TM; i++){
		for(j = i; j < TM; j++){
			if(i == j) m[i][j] = 0;
			else{
				numero = rand()%20;
				if(numero <= 1){
					numero = -1;
				}else{
					numero = rand()%20;
					numero += 1;
				}
				m[i][j] = numero;
				m[j][i] = numero;
			}
		}
	}
	
	if(f == NULL){
		return;
	}else{
		for(i=0; i < TM; i++){
			for(j=0; j < TM; j++){
				if(i == j){
					fprintf(f, "%d;", 0);
				}else{
					fprintf(f, "%d;", m[i][j]);
				}
			}
			fprintf(f, "\n");
		}
		fclose(f);
	}
}

int contaTamanhoMatriz(FILE *fp){
	int nElementos = 1;
	int valor = 0;
	rewind(fp);
	if(fp != NULL){
		while(!feof(fp)){
			nElementos += fscanf(fp, "%d;", &valor);
		}
	}
	return (int)sqrt(nElementos);
}

int main(){
	srand(time(NULL));
	criaArquivoEntrada();
	FILE *arq = fopen("entrada.txt", "r");
	int nElementos = 1;
	int valor = 0;
	int X = contaTamanhoMatriz(arq);
	int tabela[X][X];
	int i=0, j=0;
	
	rewind(arq);
	if(arq != NULL){
		i = 0;
		j = 0;
		while(!feof(arq)){
			nElementos += fscanf(arq, "%d;", &valor);
			tabela[i][j] = valor;
			j++;
			if(i >= X) break;
			if(j >= X){
				j = 0;
				i++;
			}
		}
		fclose(arq);
	}
	
	for(i=0; i < X; i++){
		for(j=0; j < X; j++){
			printf("%d;", tabela[i][j]);
		}
		printf("\n");
	}
	return 0;
}