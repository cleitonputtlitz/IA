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
int gerPopulacaoInicial(int n){
	return rand()%n;		
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
	int X = contaTamanhoMatriz(arq); // X contém o tamanho da matriz
	int i=0, j=0;
	int indice;
	int maxLig, repete, para, ligacoes, ultPosicao, matriz[X][X], erro;
	int vetorTomada[X];
	
	rewind(arq);
	if(arq != NULL){
		i = 0;
		j = 0;
		while(!feof(arq)){
			nElementos += fscanf(arq, "%d;", &valor);
			matriz[i][j] = valor;
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
			printf("%d;", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("Digite o numero de ligações possiveis para cara tomada: ");
	scanf("%d",&ligacoes);
	
	
	if(ligacoes > 11){
		maxLig = 11;
		repete = X * 11;
	}	
	else{
		maxLig = ligacoes;
		repete = X * (X-1);
	}
	
	int caminho[repete];
	for(i = 0; i < repete; i++){
		caminho[i] = -1;
	}
	
	for(i = 0; i < X; i++){
		vetorTomada[i] = 0;
	}
	
	caminho[0] = 0;
	ultPosicao = 0;
	vetorTomada[0] = 1;
	indice = gerPopulacaoInicial(X);
	para = 0;
	
	
	printf("\n   %d\n",indice);
	
	erro = 0;
	while(para == 0){
		erro = 0;
		if(matriz[ultPosicao][indice] <= 0){
			erro = 1;
		}
		if(caminho[ultPosicao] == indice){
			erro = 1;
		}/*
		if(ultPosicao >= 2 && caminho[ultPosicao - 2] == indice){
			erro = 1;
		}*/
		if(vetorTomada[caminho[ultPosicao]] > 0 && vetorTomada[indice] > 0){
			erro = 1;
		}		
		if(erro == 0){
			for(i = 0; i < ultPosicao; i++){
				if(caminho[i] == caminho[ultPosicao] && caminho[i+1] == indice){
					i = ultPosicao;
					erro = 1;
				}	
				if(caminho[i] == indice && caminho[i+1] == caminho[ultPosicao]){
					i = ultPosicao;
					erro = 1;
				}			
			}
		}

		if(erro == 0){
			if(vetorTomada[indice] == maxLig)
				erro = 1;
			else
				vetorTomada[indice] ++;
		}
		if(erro == 0){
			caminho[ultPosicao + 1] = indice;	
			ultPosicao ++;	
		}
		indice = gerPopulacaoInicial(X);
		j = 0;
		for(i = 0; i< X; i++)
		{
			if(vetorTomada[i] > 0){
				j++;
			}
			printf("%d",vetorTomada[i]);

		}
		printf("\n%d  %d\n",i,j);
		if(j == X)
			para = 1;
			
		/*for(i = 0; i< n; i++)
		{
			printf("%d",vetorTomada[i]);
		}
		printf("   %d\n",indice);
		scanf("\n%d",&i);*/	
		printf("\n");
		for(i = 0; i< repete; i++)
		{
			if(caminho[i] > -1)
				printf("%d  ",caminho[i]);
		}	
	}
	
	
	return 0;
}