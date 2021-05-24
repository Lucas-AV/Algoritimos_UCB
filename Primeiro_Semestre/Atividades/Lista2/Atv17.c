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
	char *title = "Dias que já foram vividos";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	char nome[100];
	int dias = 0, Bissextos;
	int AnoAtual, AnoNasc;
	// Code
	do{
		Bissextos = 0;
		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Qual seu nome?\n> ");
		gets(nome);
		fflush(stdin);
		system("cls");

		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Em que ano você nasceu? (0 para sair)\n> ");
		scanf("%i",&AnoNasc);
		fflush(stdin);
		system("cls");

		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Em que ano você está? (0 para sair)\n> ");
		scanf("%i",&AnoAtual);
		fflush(stdin);
		system("cls");
		int idade = (AnoAtual-AnoNasc);
		dias = idade*365;
		for(int i = 0; i < idade; i++){
			if((AnoNasc+i)%4 == 0 && (AnoNasc+i)%100 != 0){
				dias++;
				Bissextos++;
			}
		}
		if(AnoNasc != 0 && AnoAtual != 0){
			system("cls");
			printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
			printf("Nome: %s\n",nome);
			printf("Anos: %i (%i-%i)\n",idade,AnoNasc,AnoAtual);
			printf("Anos Bissextos: %i\n",Bissextos);
			printf("Dias: %i\n",dias);
			printf("%s\n",linha);
			system("PAUSE");
			system("cls");
		} else {
			printf("%s\nSaindo do sistema...\n%s\n",linha,linha);
			system("PAUSE");
		}
	} while(AnoNasc != 0 && AnoAtual != 0);
}
