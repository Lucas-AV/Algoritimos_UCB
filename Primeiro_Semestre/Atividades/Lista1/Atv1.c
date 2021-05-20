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
	char *title = "Horas para minutos e segundos";
	char linha[30] = "=============================";
	int horas = 0, 
	minutos = 0, 
	segundos = 0;

	// Code
	do{
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Insira um valor inteiro para horas:\n> ");
		scanf("%i",&horas);
		fflush(stdin);
		if(horas <= 0){
			system("cls");
		};
	} while(horas <= 0);
	minutos = horas*60;
	segundos = horas*3600;
	printf("%s\n%i horas em minutos são: %i minutos!\n",linha,horas,minutos);
	printf("%i horas em segundos são: %i segundos!\n%s\n",horas,segundos,linha);
	system("PAUSE");
}