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
	char *title = "Altura de 10 pessoas com While";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int numPessoas = 10;
	int contador = 0;
	char nomes[10][100], menorPessoa[100];
	float alturas[10];
	float alturaAntiga;
	// Code
	do{
		printf("%s\n%1.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira nome da pessoa %i\n> ",contador+1);
		gets(nomes[contador]);
		fflush(stdin);
		system("cls");
		
		printf("%s\n%1.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira a altura para %s\n> ",nomes[contador]);
		scanf("%f",&alturas[contador]);
		fflush(stdin);
		system("cls");
		if(contador == 0){
			alturaAntiga = alturas[contador];
		}
		if(alturas[contador] < alturaAntiga){
			alturaAntiga = alturas[contador];
			strcpy(menorPessoa,nomes[contador]);
		}
		contador++;

	} while (contador < numPessoas);
	printf("%s\n%1.c%s\n%s\n",linha,spaces,title,linha);
	printf("A pessoa mais alta é: %s\n",menorPessoa);
	printf("Sua altura é de: %.2f\n",alturaAntiga);
	printf("%s\n",linha);
	system("PAUSE");
}