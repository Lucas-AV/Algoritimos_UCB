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
	char linha[30] = "=============================";
	char spaces = 256;
	char *tratamentos[2] = {"ilmo. Sr.","ilma. Sra."};
	char nome[100];
	char sexo;
	int masc = 0, fem = 0;
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
		if (sexo == 'M' || sexo == 'm'){
			masc = 1;
			break;
		} 
		else if(sexo == 'F' || sexo == 'f'){
			fem = 1;
			break;
		}
		else {
			printf("%s\nInsira um valor igual a F/f ou M/m!\n%s\n",linha,linha);
			system("PAUSE");
			system("cls");
		}
	} while (fem < 1 || masc < 1);
	float altura, peso;
	system("cls");
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("Insira sua altura:\n> ");
	scanf("%f",&altura);
	fflush(stdin);
	printf("%s\n",linha);
	if(masc == 1){
		peso = (72.5 * altura) - 58; // homem
		printf("Bem vindo %s %s\n",tratamentos[0],nome);
	} 
	else if (fem == 1){
		peso = (62.1 * altura) - 44.7; // mulher
		printf("Bem vinda %s %s\n",tratamentos[1],nome);
	}
	printf("Seu peso ideal é: %.2f\n%s\n",peso,linha);
	system("PAUSE");
}