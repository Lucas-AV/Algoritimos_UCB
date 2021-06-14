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
	char *title = "Idade de até 100 pessoas";
	char *linha = "====================================================";

	// Vars Code
	int idades[100];

	// Code
	int i,c = 0;
	for(i = 0; i < 100; i++){
        system("cls");
        strcenter(linha,title,32);
		printf("Insira a idade da pessoa n%i (0 para sair)\n> ",i);
        scanf("%i",&idades[i]);
        fflush(stdin);
        if(idades[i] != 0){
            c++;
        } else {
            break;
        }
	}
    int temp, pos[100], cpos = 0;
    strcenter(linha,title,32);
    for(i = 0; i < c; i++){
        if(i == 0){
            temp = idades[i];
        }
        if(idades[i] > temp && i > 0){
            temp = idades[i];
        }
    }
    printf("A maior idade é: %i (pos: ",temp);
    for(i = 0; i < c; i++){
        if(idades[i] == temp){
            printf("%i",i);
        }
    }
    
    printf(")\n%s\n",linha);
}