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
	char *title = "Vou pensar em número de 1 a 50";
	char *linha = "=============================";
	char spaces = 256;
	// Vars Code
	int adivinhar, vezes = 0, chute;

	// Code
	srand(time(NULL)); // Inicia o comando para rand()
	adivinhar = rand() % 50;
	do{
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Chute %i\n> ",vezes+1,adivinhar);
		scanf("%i",&chute);
		system("cls");
		vezes++;
	} while(chute != adivinhar);
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("Você precisou chutar %i vezes!\n",vezes);
	printf("Resposta: %i!\n",chute,vezes);
	printf("%s\n",linha);
	system("PAUSE");
}