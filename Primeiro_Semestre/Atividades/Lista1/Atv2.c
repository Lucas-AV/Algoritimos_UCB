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
	char *title = "Calcuar área de um círculo";
	char linha[30] = "=============================";
	float pi = 3.14,
	raio = 0.00,
	area = 0.00;
	
	// Code
	do{
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Insira um valor para o raio (cm\\m):\n> ");
		scanf("%f",&raio);
		fflush(stdin);
		if(raio <= 0){
			system("cls");
		};
	} while(raio <= 0);
	
	area = pi*(raio*raio);
	printf("%s\nA área do círculo mede: %.2f (cm\\m)²\n%s\n",linha,area,linha);
	system("PAUSE");
}