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
	char *title = "Provedora de internet";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	char nome[100];
	int HorasBase = 20;
	int HorasUsadas = 0;
	float ValorBase = 30.00;
	float Total = 0;
	// Code
	do{
		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Qual seu nome?\n> ");
		gets(nome);
		fflush(stdin);
		system("cls");

		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Quantas Horas você consumiu de internet? (0 para sair)\n> ");
		scanf("%i",&HorasUsadas);
		fflush(stdin);
		if(HorasUsadas > HorasBase){
			Total = ValorBase*(1+(0.10*(HorasUsadas-HorasBase)));
		} else {
			Total = ValorBase;
		}
		if(HorasUsadas != 0){
			system("cls");
			printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
			printf("Nome: %s\n",nome);
			printf("Horas: %i Horas\n",HorasUsadas);
			printf("Preço: R$ %.2f\n",Total);
			printf("%s\n",linha);
			system("PAUSE");
			system("cls");
		} else {
			printf("%s\nSaindo do sistema...\n%s\n",linha,linha);
			system("PAUSE");
		}
	} while (HorasUsadas != 0);
	
	
	
	
}