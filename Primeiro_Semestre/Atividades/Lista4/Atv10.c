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
	char *title = "Adega de vinhos";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int vinhos[2];
	char *nomes[2] = {"Tinto","Branco"};

	// Code
	for(int i = 0; i < 2; i++){
		printf("%s\n%8.c%s\n%s\n",linha,spaces,title,linha);
		printf("Quantidade de vinhos %s\n> ",nomes[i]);
		scanf("%i",&vinhos[i]);
		fflush(stdin);
		system("cls");
	}
	
	printf("%s\n%8.c%s\n%s\n",linha,spaces,title,linha);
	printf("Total de vinhos na adega: %i\n",vinhos[0]+vinhos[1]);
	for(int i = 0; i < 2; i++){
		printf("Vinhos tipo %s: %i (%0.f%%)\n",nomes[i],vinhos[i],(float)vinhos[i]/(vinhos[i]+vinhos[(i+1)%2])*100);	
	}
	printf("%s\n",linha);
	
	system("PAUSE");
}