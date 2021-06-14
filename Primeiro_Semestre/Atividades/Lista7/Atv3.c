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
	int i;
    if(strlen(line) % 2 != 0){
        Mid += 1; // Acts like a counter
    }
    for(i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in left-side
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // Print the main string

    for(i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in right-side
    }
    printf("\n%s\n",line); // Print the final line with \n
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese-brazillian");

	// Vars
	char *title = "Soma de até 100 números";
	char *linha = "====================================================";

	// Vars Code
	float notas[30];
	int n[100];
    int c = 0;
	// Code
	int i = 0;
	int soma = 0;
	do{
        system("cls");
        strcenter(linha,title,32);
        printf("Insira um valor para o número na posição: %i (-1 para encerrar)\n> ",c);
        scanf("%i",&n[c]);
        fflush(stdin);
        if(n[c] != (-1)){
            soma += n[c];
            c++;
        }else{
            break;
        }
    } while (c < 99 || n[c] != (-1));   // 0 a 100
    system("cls");
    strcenter(linha,"RESULTADOS",32);
    printf("> Você digitou %i números\nSoma:\t%i\nMédia:\t%.2f\n%s",c,soma,(float)soma/c,linha);
}