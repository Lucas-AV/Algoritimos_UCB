// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars Decorators
	char *title = "Calculadora de módulo";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float num;
	int modulo;
	// Code
	printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
	printf("Insira o valor do número\n> ");
	scanf("%f",&num);
	fflush(stdin);
	modulo = ceil(num);
	if(modulo < 0){
		modulo *= (-1);
	}
	system("cls");
	printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
	printf("O módulo de %.2f é: %i\n%s\n",num,modulo,linha);
	system("PAUSE");
}
