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
	char *title = "Leitor de frases";
	char *linha = "====================================================";

	// Vars Code
	char notas[80], dupla[2];
	
	// Code
	int i;
    int esp = 0, na = 0, pospar[80], par = 0;
	strcenter(linha,title,32);
    printf("Insira uma string aqui\n> ");
	gets(notas);
    printf("Insira um par de letras para detectar\n> ");
    gets(dupla);
    for(i = 0; i < strlen(notas); i++){
        if(notas[i] == ' '){
            esp++;
        }
        else if(notas[i] == 'a' || notas[i] == 'A'){
            na++;
        }
        if(dupla[0] == notas[i] && dupla[1] == notas[(i+1)%strlen(notas)]){
            pospar[par] == i; 
            par++;
        }
    }
    printf("%s\n",linha);
    printf("Números de espaços:\t%i\n",esp);
    printf("Números de letras A:\t%i\n",na);
    printf("Vezes que as letras %s aparecem juntas:\t%i\n",dupla,par);
    printf("%s\n",linha);
}