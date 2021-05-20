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
	char *title = "Calculadora de rolos!";
	char linha[30] = "=============================";
	int obra = 0,
	qntRolo = 0,
	sobra = 0,
	tmRolo = 50;

	// Code
	do{
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("De quantos metros de fio vai precisar?\n> ");
		scanf("%i",&obra);
		fflush(stdin);
		if(obra <= 0){
			printf("%s\nPor favor insira um válido e diferente de 0!\n%s\n",linha,linha);
			system("cls");
		}
	} while (obra <= 0);
	
	if (obra/tmRolo < 1){
		qntRolo = 1;
	} else {
		qntRolo = obra/tmRolo + obra%tmRolo;
		sobra = qntRolo*tmRolo - obra;
	}
	printf("%s\nVocê vai precisar de %i rolos (%im)\n",linha,qntRolo,qntRolo*tmRolo);
	if(sobra > 0){
		printf(">>> Vai sobrar %im de fio\n",sobra);
	}
	printf("%s\n",linha);
	system("PAUSE");
}