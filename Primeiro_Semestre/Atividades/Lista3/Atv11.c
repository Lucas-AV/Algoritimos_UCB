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
	char *title = "Finalistas do Concurso!";
	char linha[100] = "=============================";
	char spaces = 256;
	// Vars Code
	char nomes[3][100];
	int notas[3] = {0,0,0};
	int juizes = 0;
	// Code
	for(int i = 0; i < 3; i++){
		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o nome do participante %i\n> ",i+1);
		gets(nomes[i]);
		fflush(stdin);
		system("cls");
	}
	do{
		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira a quantidade de juizes do concurso\n> ");
		scanf("%i",&juizes);
		fflush(stdin);
		if(juizes <= 0){
			printf("%s\nInsira um valor inteiro e que seja maior do que 0!\n%s\n",linha,linha);
			system("PAUSE");
		}
		system("cls");
	}while(juizes <= 0);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < juizes; j++){
			int nota;
			printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
			printf("Juiz %i\n",j+1);
			printf("Nota do participante %s\n> ",nomes[i]);
			scanf("%i",&nota);
			fflush(stdin);
			notas[i] += nota;
			system("cls");
		}
	}
	printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
	printf("Vencedor: ");
	if(notas[0] > notas[1] && notas[0] > notas[2]){
		printf("%s (%i pts)\n",nomes[0],notas[0]);
		if(notas[1] > notas[2]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[1],notas[1],nomes[2],notas[2]);
		} 
		else if(notas[2] > notas[1]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[2],notas[2],nomes[1],notas[1]);
		}
	}
	
	else if(notas[1] > notas[2] && notas[1] > notas[2]){
		printf("%s (%i pts)\n",nomes[1],notas[1]);
		if(notas[0] > notas[2]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[0],notas[0],nomes[2],notas[2]);
		}
		else if(notas[2] > notas[0]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[2],notas[2],nomes[0],notas[0]);
		}
	}
	
	else if(notas[2] > notas[0] && notas[2] > notas[1]){
		printf("%s (%i pts)\n",nomes[2],notas[2]);
		if(notas[1] > notas[0]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[1],notas[1],nomes[0],notas[0]);
		} 
		else if(notas[0] > notas[1]){
			printf("Segundo Lugar: %s (%i pts)\nTerceiro Lugar: %s (%i pts)\n",nomes[0],notas[0],nomes[1],notas[1]);
		}
	} else {
		printf("Ninguém!\n");
		printf("Houve um empate!\n");
	}
	printf("%s\n",linha);
	system("PAUSE");
}