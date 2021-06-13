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
	char *title = "Números primos entre 2 números";
	char linha[30] = "=============================";
	char spaces = 256;
	int N1 = 0;
	int N2 = 0;
	// Code
	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
	printf("Valor para N1\n> ");
	scanf("%i",&N1);
	system("cls");

	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);	
	printf("Valor para N2\n> ");
	scanf("%i",&N2);
	system("cls");

	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);	
	for(int i = N1; i < (N2+1); i++){
		if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0){
			printf("Primo: %i\n",i);
		}
		else if(i == 2 || i == 3 || i == 5 || i == 7){
			printf("Primo: %i\n",i);
		}
	}
	printf("%s\n",linha);
	system("PAUSE");
}