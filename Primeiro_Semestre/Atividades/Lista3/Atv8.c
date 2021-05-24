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
	char *title = "Cadastro e aumento de produtos";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	char Produtos[100][100];
	int Quantidade[100];
	float Precos[100];
	int Contador = 0;
	float precoAtual;
	float Aumento = 1.10;
	// Code
	do{
		system("cls");
		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o nome do produto\n> ");
		gets(Produtos[Contador]);
		fflush(stdin);
		system("cls");

		do{
			printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
			printf("Insira a quantidade de %s\n> ",Produtos[Contador]);
			scanf("%i",&Quantidade);
			fflush(stdin);
			system("cls");
		} while(Quantidade <= 0);
		
		do{
			printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
			printf("Insira o preço para %s\n> ",Produtos[Contador]);
			scanf("%f",&Precos[Contador]);
			fflush(stdin);
			system("cls");
		}while (Precos[Contador] == 0 || Precos[Contador] < (-1));

		precoAtual = Precos[Contador];
		if(precoAtual != (-1)){
			printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
			printf("O preço de %s será aumentando em 10%%!\n",Produtos[Contador]);
			printf("Antes: R$ %.2f\n",Precos[Contador]);
			Precos[Contador] *= 1.10;
			printf("Depois: R$ %.2f\n",Precos[Contador]);
			printf("%s\n",linha);
			system("PAUSE");
			Contador++;
		}
	}while(precoAtual != (-1));

	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
	for(int i = 0; i<Contador; i++){
		printf("Produto: %s\n",Produtos[i]);
		printf("Quantidade: %i\n",Quantidade[i]);
		printf("Preço: R$ %.2f (%.2f/p)\n",Precos[i],Precos[i]/Quantidade[i]);
		printf("%s\n",linha);
	}
	
	system("PAUSE");
}