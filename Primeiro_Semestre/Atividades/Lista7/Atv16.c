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
	char *title = "Soma de A e B para C";
	char *linha = "====================================================";

	// Vars Code
	int A[10],B[10],C[10];
	// Code
	int i, j;
	
    // Resultado
    for(i = 0; i < 10; i++){
        system("cls");
        strcenter(linha,title,32);
        printf("Valor para A[%i]\n> ",i);
        scanf("%i",&A[i]);
        fflush(stdin);
        printf("Valor para B[%i]\n> ",i);
        scanf("%i",&B[i]);
        fflush(stdin);
        C[i] = A[i] + B[i];
    }
    system("cls");
    strcenter(linha,title,32);
    printf("Resultado de A+B = C\n");
    for(i = 0; i < 10; i++){
        printf("%i + %i = %i\n",A[i],B[i],C[i]);
    }
    int opt;
    printf("%s\n",linha);
    printf("Digite um valor para pesquisar em C\n> ");
    scanf("%i",&opt);
    for(i = 0; i < 10; i++){
        if(C[i] == opt){
            printf("%i encontrado na posição C[%i]",opt,i);
        }
    }
    printf("%s\n",linha);
}