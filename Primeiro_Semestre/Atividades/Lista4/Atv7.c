// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Sexo e altura de 50 pesssoas";
	char *linha = "=============================";
	char spaces = 256;
	char nomes[50][100];
	char sexos[50];
	float alturas[50];
	float aMulheres = 0.00;
	int mulheres = 0.00;
	float menor, maior = 0.00;
	char nMenor[100], nMaior[100];
	// Code
	for(int i = 0; i < 50; i++){
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Nome da pessoa %i\n> ",i+1);
		gets(nomes[i]);
		fflush(stdin);
		system("cls");
		do{
			printf("%s\n%s\n%s\n",linha,title,linha);
			printf("Sexo para %s\n> ",nomes[i]);
			scanf("%c",&sexos[i]);
			fflush(stdin);
			system("cls");
		}while (sexos[i] != 'm' && sexos[i] != 'M' && sexos[i] != 'f' && sexos[i] != 'F');

		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Altura para %s\n> ",nomes[i]);
		scanf("%f",&alturas[i]);
		fflush(stdin);
		system("cls");
		
		if(sexos[i] == 'F' || sexos[i] == 'f'){
			aMulheres += alturas[i];
			mulheres++;
		}
		if(alturas[i] > maior){
			maior = alturas[i];
			strcpy(nMaior,nomes[i]);
		}
		if(alturas[i] < menor || i == 0){
			menor = alturas[i];
			strcpy(nMenor,nomes[i]);
		}
	}
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("A pessoa mais alta é: %s\n> %.2fm!\n",nMaior,maior);
	printf("A pessoa mais baixa é: %s\n> %.2fm!\n",nMenor,menor);
	printf("A Altura média das mulheres é de:\n> %.2fm (Mulheres: %i)\n",aMulheres/mulheres,mulheres);
	printf("%s\n",linha);
	system("PAUSE");
}