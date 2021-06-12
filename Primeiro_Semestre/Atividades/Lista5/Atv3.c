// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

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
    setlocale(LC_ALL, "Portuguese-brazillian");

	// Vars
	char *title = "Conversor de caracter";
	char *linha = "========================================";
	
	// Vars Code
	char etc;
	// Code
	do{
		system("cls");
		strcenter(linha,title,32);
		printf("Digite qualquer caracter\n> ");
		scanf("%c",&etc);
		fflush(stdin);
		printf("Em Caracter: %c\n",etc);
		printf("Em Decimal: %d\n",etc);
		printf("Em Octal: %02o\n",etc);
		printf("Em Hexadecimal: %02X\n",etc);
		printf("%s\n",linha);
		system("PAUSE");
	} while (etc != 'x');
}