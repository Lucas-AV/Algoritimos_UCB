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
	char *title = "Mercado de Frutas!";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	char *Frutas[3];
	Frutas[0] = "Abacaxi";
	Frutas[1] = "Maça";
	Frutas[2] = "Pera";
	int Pedidos[3] = {0,0,0};
	int option;
	// Code
	do{
		printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
		for(int i = 0; i < 3; i++){
			printf("%i. %s\n",i+1,Frutas[i]);
		}
		printf("%s\nSelecione uma fruta (0 para finalizar)\n> ",linha);
		scanf("%i",&option);
		fflush(stdin);
		if(option >= 1 && option <= 3){
			if(option == 1){
				Pedidos[0] += 1;
			}
			else if(option == 2){
				Pedidos[1] += 1;
			}
			else if(option == 3){
				Pedidos[2] += 1;
			}
			system("cls");
		} 
		else if(option != 0 && option > 3 && option < 1){
			printf("%s\nCódigo não encontrado!\n%s\n");
			system("PAUSE");
			system("cls");
		}
	} while(option != 0);
	system("cls");
	printf("%s\n%7.c%s\n%s\n",linha,spaces,title,linha);
	printf("Resumo do pedido:\n");
	for(int i = 0; i < 3; i++){
		printf("- %i %s\n",Pedidos[i],Frutas[i]);
	}
	printf("%s\n",linha);
	system("PAUSE");
}