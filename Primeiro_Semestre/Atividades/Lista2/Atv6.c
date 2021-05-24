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
	char *title = "Definir PAR ou ÍMPAR";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int num;
	// Code
	do{
		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira um valor númerico inteiro (0 para sair)\n> ");
		scanf("%i",&num);
		fflush(stdin);
		if(num == 0){
			printf("%s\nSaindo do programa...\n%s\n",linha,linha);
			system("PAUSE");
			break;
		} else {
			printf("%s\n",linha);
			if(num % 2 == 0){
				printf("O número %i é PAR\n%s\n",num,linha);
			} else {
				printf("O número %i é ÍMPAR\n%s\n",num,linha);
			}
			system("PAUSE");
			system("cls");
		}
	} while(num != 0);
}