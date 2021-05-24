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
	char *title = "Menor altura 3 pessoas";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float nums[3] = {0,0,0};
	float menor;
	char nomes[3][100];
	char menorPessoa[100];
	// Code
	for(int i = 0; i < 3; i++){
		// Nome
		printf("%s\n%6.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o nome da pessoa %i:\n> ",i+1);
		gets(nomes[i]);
		fflush(stdin);
		system("cls");
		// Altura
		printf("%s\n%6.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira a altura para %s:\n> ",nomes[i]);
		scanf("%f",&nums[i]);
		fflush(stdin);
		system("cls");
	}

	if(nums[0] < nums[1] && nums[0] < nums[2]){
		menor = nums[0];
		strcpy(menorPessoa,nomes[0]);
	}
	else if(nums[1] < nums[0] && nums[1] < nums[2]){
		menor = nums[1];
		strcpy(menorPessoa,nomes[1]);
	}
	else if(nums[2] < nums[0] && nums[2] < nums[1]){
		menor = nums[2];
		strcpy(menorPessoa,nomes[2]);
	} else {
		menor = nums[0];
		strcpy(menorPessoa,"Ninguem!");
	}
	
	printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
	printf("O mais baixo de todos é o: %s\n",menorPessoa);
	printf("Ele tem: %.2fm de altura!\n%s\n",menor,linha);
	system("PAUSE");
	
}
