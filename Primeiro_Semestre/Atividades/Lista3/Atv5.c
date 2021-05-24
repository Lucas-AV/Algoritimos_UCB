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
	char *title = "Cálculo Vetorial com loop";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int Vetorial, Resultado;	
	// Code
	do{
		Resultado = 1;
		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira um valor inteiro: (0 para sair)\n> ");
		scanf("%i",&Vetorial);
		fflush(stdin);
		for(int i = 0; i < Vetorial; i++){
			Resultado *= i+1;
		}
		if(Vetorial != 0){
			system("cls");
			printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
			printf("O Resultado de %i! é: %i\n",Vetorial,Resultado);
			printf("%s\n",linha);
			system("PAUSE");
			system("cls");
		} else {
			char close;
			printf("%s\nTem certeza de quer mesmo sair? (S/N)\n> ",linha);
			scanf("%c",&close);
			fflush(stdin);
			if(close == 'S' || close == 's'){
				printf("%s\nSaindo do sistema...\n%s\n",linha,linha);
				system("PAUSE");
			} else{
				Vetorial = 1; // Usado apenas para n sair do código
				Resultado = 1; // 0! = 1
				system("cls");
				printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
				printf("O Resultado de %i! é: %i\n",Vetorial,Resultado);
				system("PAUSE");
				system("cls");
			}
			
		}
	} while(Vetorial != 0);
}