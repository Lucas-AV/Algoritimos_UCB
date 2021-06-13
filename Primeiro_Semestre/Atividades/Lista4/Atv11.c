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
	char *title = "Média Aritmética";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int nums = 0;
	int Contador = 0, temp;

	// Code
	do{
		printf("%s\n%6.c%s\n%s\n",linha,spaces,title,linha);
		printf("Valor do número %i\n> ",Contador);
		scanf("%i",&temp);
		if(temp % 2 == 0 && temp != 0){
			nums += temp;
			Contador++;
		}
		if(temp == 0){
			system("cls");
			printf("%s\n%6.c%s\n%s\n",linha,spaces,title,linha);
			printf("A média aritmética:\n> %i/%i = %i\n",nums,Contador,nums/Contador);
			printf("%s\n",linha);
			system("PAUSE");
			break;
		}
		system("cls");
	} while (temp != 0);
}