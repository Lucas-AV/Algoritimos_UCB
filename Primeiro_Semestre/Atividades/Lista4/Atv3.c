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
	char *title = "Media de informações";
	char linha[200] = "=============================";
	char spaces = 256;
	
	// Vars Code
	char *vencedor;
	char paises[3][100];
	int Ouro[3] = {0,0,0};
	int Prata[3] = {0,0,0};
	int Bronze[3] = {0,0,0};
	int pontos[3] = {0,0,0};

	// Code
	for(int i = 0; i < 3; i++){
		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o nome do país %i\n> ",i+1);
		gets(paises[i]);
		fflush(stdin);
		system("cls");

		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Medalhas de ouro para %s\n> ",paises[i]);
		scanf("%i",&Ouro[i]);
		fflush(stdin);
		system("cls");

		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Medalhas de prata para %s\n> ",paises[i]);
		scanf("%i",&Prata[i]);
		fflush(stdin);
		system("cls");

		printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
		printf("Medalhas de bronze para %s\n> ",paises[i]);
		scanf("%i",&Bronze[i]);
		fflush(stdin);
		system("cls");

		pontos[i] += Ouro[i]*3 + Prata[i]*2 + Bronze[i]*1;
	}
	printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
	for(int i = 0; i < 3; i++){
		if(pontos[i] > pontos[(i+1)%3] && pontos[i] > pontos[(i+2)%3]){
			vencedor = paises[i];
			printf("Primeiro Lugar: %s\n",vencedor);
			if(pontos[(i+1)%3] > pontos[(i+2)%3]){
				printf("Segundo Lugar: %s\n",paises[(i+1)%3]);
				printf("Terceiro Lugar: %s\n",paises[(i+2)%3]);
			} else {
				printf("Segundo Lugar: %s\n",paises[(i+2)%3]);
				printf("Terceiro Lugar: %s\n",paises[(i+1)%3]);
			}
			break;
		}
		else if(i == 2){
			printf("Houve um empate!\n");
		}
	}

	printf("%s\n",linha);
	system("PAUSE");
}