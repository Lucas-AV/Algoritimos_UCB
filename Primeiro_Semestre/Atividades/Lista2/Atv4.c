// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Tratamento de pessoas por sexo";
	char *linha = "=============================";
	char spaces = 256;
	char *tratamentos[2] = {"ilmo. Sr.","ilma. Sra."};
	char nome[100];
	char sexo;
	int sex;
	// Code
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("Insira seu nome:\n> ");
	gets(nome);
	do{
		system("cls");
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Insira seu sexo (M/F):\n> ");
		scanf("%c",&sexo);
		fflush(stdin);
		switch (sexo) {
			case 'M':
				printf("%s\nBem vindo %s %s\n%s\n",linha,tratamentos[0],nome,linha);
				sex = 0;
				break;

			case 'F':
				printf("%s\nBem vinda %s %s\n%s\n",linha,tratamentos[1],nome,linha);
				sex = 0;
				break;

			case 'm':
				printf("%s\nBem vindo %s %s\n%s\n",linha,tratamentos[0],nome,linha);
				sex = 0;
				break;
				
			case 'f':
				printf("%s\nBem vinda %s %s\n%s\n",linha,tratamentos[1],nome,linha);
				sex = 0;
				break;

			default:
				printf("%s\nInsira um valor igual a F/f ou M/m!\n%s\n",linha,linha);
				system("PAUSE");
				system("cls");
				break;
		}
	} while (sex != 0);
	system("PAUSE");
}
