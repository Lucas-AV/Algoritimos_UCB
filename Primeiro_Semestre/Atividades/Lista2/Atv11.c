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

	// Vars Decorators
	char *title = "Formação de triângulo";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int lados[3] = {0, 0, 0};
	char tipo[100];
	// Code
	for(int i = 0; i < 3; i++){
		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor do lado %i\n> ",i+1);
		scanf("%i",&lados[i]);
		fflush(stdin);
		system("cls");
	}

	printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
	if(lados[0] + lados[1] >= lados[2] && lados[0] + lados[2] >= lados[1] && lados[1] + lados[2] >= lados[0]){
		if(lados[0] == lados[1] && lados[1] == lados[2]){
			strcpy(tipo,"EQUILÁTERO (Todos os lados iguais)");
		}
		else if(lados[0] == lados[1] && lados[1] != lados[2] || lados[0] == lados[2] && lados[2] != lados[1] || lados[2] == lados[1] && lados[1] != lados[0]){
			strcpy(tipo,"ISÓCELES (Dois lados iguais)");
		}
		else if(lados[0] != lados[1] && lados[1] != lados[2]){
			strcpy(tipo,"QUALQUER (Todos os lados diferentes)");
		}
		printf("Triângulo %s formado com sucesso! (%ix%ix%i)\n",tipo,lados[0],lados[1],lados[2]);
	} else {
		printf("Tamanho inválido para formar um triângulo!");
	}
	printf("%s\n",linha);
	system("PAUSE");
}