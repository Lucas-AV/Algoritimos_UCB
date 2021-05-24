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
	char *title = "Listagem de até 100 números";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int Lista[100], Contador = 0;
	// Code
	for(int i = 0; i < 100; i++){
		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor para o número %i\n> ",i+1);
		scanf("%i",&Lista[i]);
		fflush(stdin);
		if(Lista[i] < 0){
			system("cls");
			break;
		} else {
			Contador++;
			system("cls");
		}
	}
	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
	for(int i = 0; i < Contador; i++){
		printf("%i: %i\n",i+1,Lista[i]);
	}
	printf("Tamanho da lista: %i\n",Contador);
	printf("%s\n",linha);
	system("PAUSE");
}