// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void strcenter(char *line, char *string, char digit){
    int Mid = strlen(line)-strlen(string); // len(line) - len(string) == Lenght difference between line and string
    printf("%s\n",line);
    if(strlen(line) % 2 != 0){
        Mid += 1; // Acts like a counter
    }
    for(int i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in left-side
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // Print the main string

    for(int i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in right-side
    }
    printf("\n%s\n",line); // Print the final line with \n
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Números pares até 2000";
	char *linha = "=======================================";
	// Vars Code
	int num,pares = 0;
	// Code
	do{
		system("cls");
		strcenter(linha,title,32); // 32 == Espaço vazio com setlocale
		printf("Insira um número menor ou igual a 2000\n%s\n> ",linha);
		scanf("%i",&num);
		
		if(num > 2000){
			strcenter(linha,"Limite de cálculo excedido!",32);
			system("PAUSE");
		}
	}while(num > 2000);
	printf("%s\n",linha);
	for(int i = 0; i < num+1; i++){
		if(i%2 == 0){
			printf("%i\n",i);
			pares++;
		}
	}
	char strTotal[100];
	sprintf(strTotal,"Total de pares: %i",pares); // strcpy para string formatada! >>> 
	strcenter(linha,strTotal,32);
}