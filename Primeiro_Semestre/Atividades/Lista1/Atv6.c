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
	char *title = "Calcular média de duas notas!";
	char linha[30] = "=============================";
	float notas[2] = {0, 0};
	float media = 0;

	// Code
	for (int i = 0; i < 2; i++){
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Nota %i:\n> ",i+1);
		scanf("%f",&notas[i]);
		fflush(stdin);
		system("cls");
	}
	printf("%s\n%s\n%s\n",linha,title,linha);
	for(int i = 0; i < 2; i++){
		printf("Nota %i: %.2f\n",i+1,notas[i]);
	}
	media = (notas[0]*3.5 + notas[1]*7.5)/11;
	printf("%s\nA média deste aluno é de: %.2f\n%s\n",linha,media,linha);
	system("PAUSE");
}