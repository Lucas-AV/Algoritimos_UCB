// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Pesquisa etnica";
	char linha[30] = "=============================";
	char spaces = 256;
	
	// Vars Code
	char *olhos[4];
	olhos[0] = "Azuis";
	olhos[1] = "Verdes";
	olhos[2] = "Castanhos";
	olhos[3] = "Pretos";
	char *cabelos[3];
	cabelos[0] = "Loiro";
	cabelos[1] = "Castanhos";
	cabelos[2] = "Pretos";

	int idades[100];
	int IdadeAtual = 0;
	int maiorIdade = 0;
	char nomes[100][100];
	char sexos[100];
	char Olhos[100][10];
	char Cabelos[100][10];
	int Contador = 0;
	int Especial = 0;
	// Code
	do{
		system("cls");
		printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
		printf("Qual é o nome da pessoa %i?\n> ",Contador+1);
		gets(nomes[Contador]);
		fflush(stdin);
		system("cls");
		
		do{
			printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
			printf("Qual é o sexo para %s?\n> ",nomes[Contador]);
			scanf("%c",&sexos[Contador]);
			fflush(stdin);
			system("cls");
		}while(sexos[Contador] != 'M' && sexos[Contador] != 'm' && sexos[Contador] != 'F' && sexos[Contador] != 'f');
		
		// Olhos
		int option;
		do{
			printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
			for(int i = 0; i < 4; i++){
				printf("%i. %s\n",i+1,olhos[i]);
			}
			printf("> ");
			scanf("%i",&option);
			fflush(stdin);
			strcpy(Olhos[Contador],olhos[option-1]);
			system("cls");
		}while(option > 4 || option < 1);
		
		// Cabelos
		
		int option2;
		do{
			printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
			for(int i = 0; i < 3; i++){
				printf("%i. %s\n",i+1,cabelos[i]);
			}
			printf("> ");
			scanf("%i",&option2);
			fflush(stdin);
			strcpy(Cabelos[Contador],cabelos[option2-1]);
			system("cls");
		}while(option2 > 3 || option2 < 1);

		// Idade
		do{
			printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
			printf("Insira a idade para %s\n> ",nomes[Contador]);
			scanf("%i",&idades[Contador]);
			fflush(stdin);
			system("cls");
			IdadeAtual = idades[Contador];
			if(IdadeAtual > 0){
				break;
			} else if(IdadeAtual == (-1)){
				break;
			}
		} while(idades[Contador] != (-1) || idades[Contador] < 0);
		
		if(IdadeAtual != (-1)){
			if(idades[Contador] >= 18 && idades[Contador] <= 35 && Cabelos[Contador] == cabelos[0] && Olhos[Contador] == olhos[1] && sexos[Contador] == 'F' || sexos[Contador] == 'f' && idades[Contador] >= 18 && idades[Contador] <= 35 && Cabelos[Contador] == cabelos[0] && Olhos[Contador] == olhos[1]){
				Especial++;
			}
			if(idades[Contador] > maiorIdade){
				maiorIdade = idades[Contador];
			}
			Contador++;
		}
		
	}while(IdadeAtual != (-1));

	printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
	for(int i = 0; i < Contador; i++){
		printf("Nome: %s\n",nomes[i]);
		printf("Sexo: %c\n",sexos[i]);
		printf("Cabelo: %s\n",Cabelos[i]);
		printf("Olhos: %s\n",Olhos[i]);
		if(i < Contador - 1){
			printf("Idade: %i\n",idades[i]);
			printf("%s\n",linha);
		} else {
			printf("Idade: %i\n\n",idades[i]);
		}
		
	}
	printf("Maior idade: %i anos\n",maiorIdade);
	printf("Mulheres de 18 a 35 anos com:\n- Cabelos Loiros\n- Olhos Verdes\n> ");
	float Proporcao = (float)Especial/(float)Contador;
	if (Proporcao < 0){
		Proporcao = 0.00;
	}
	printf("De %i pessoas %i (%0.f%%) delas são assim!\n",Contador,Especial,Proporcao*100);
	printf("%s\n",linha);
	system("PAUSE");
}