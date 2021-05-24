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
	char *title = "Calculo Atv4";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float H = 0;
	int N;
	// Code
	printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
	printf("Insira um valor inteiro para N\n> ");
	scanf("%i",&N);
	fflush(stdin);
	system("cls");
	printf("%s\n",linha);
	for(int i = 1; i < N+1; i++){
		H += 1.00/i;
		printf("1.00/%i: %f\n",i,H);
	}
	printf("%s\n",linha);
	system("PAUSE");

	system("cls");
	printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
	printf("O Resultado é: %.2f (%i vezes)\n",H, N);
	printf("%s\n",linha);
	system("PAUSE");
}