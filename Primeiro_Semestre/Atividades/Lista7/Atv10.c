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
    setlocale(LC_ALL, "Portuguese");

	// Vars
	char *title = "Leitor de nomes!";
	char *linha = "====================================================";

	// Vars Code
	char nome[120];
	
	// Code
    int i;
	strcenter(linha,title,32);
	printf("Digite seu nome completo\n> ");
    gets(nome);
    system("cls");
    strcenter(linha,title,32);
    printf("Seu nome é: \n> ");
    for(i = 0; i < strlen(nome); i++){
        if(nome[i] == '#'){
            break;
        } else {
            printf("%c",nome[i]);
        }
    }

}