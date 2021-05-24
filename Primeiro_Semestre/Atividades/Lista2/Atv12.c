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
	char *title = "Identificador de DDD";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int DDD;
	char cidade[100];
	// Code
	do{
		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira um valor para DDD (0 para sair)\n> ");
		scanf("%i",&DDD);
		fflush(stdin);
		switch(DDD){
			case 61:
				strcpy(cidade,"Brasília");
				break;
			case 71:
				strcpy(cidade,"Salvador");
				break;
			case 11:
				strcpy(cidade,"São Paulo");
				break;
			case 21:
				strcpy(cidade,"Rio de Janeiro");
				break;
			case 32:
				strcpy(cidade,"Juiz de Fora");
				break;
			case 19:
				strcpy(cidade,"Campinas");
				break;
			case 27:
				strcpy(cidade,"Vitória");
				break;
			case 31:
				strcpy(cidade,"Belo Horizonte");
				break;
			default:
				strcpy(cidade,"Não identificado");
				break;
		}
		if(DDD != 0){
			printf("%s\nO DDD %i é de: %s\n%s\n",linha,DDD,cidade,linha);
			system("PAUSE");
			system("cls");
		} else {
			printf("%s\nSaindo do sistema...\n%s\n",linha,linha);
			system("PAUSE");
		}
	}while (DDD != 0);
}