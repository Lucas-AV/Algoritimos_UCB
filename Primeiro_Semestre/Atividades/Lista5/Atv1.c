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
	char *title = "Percentual de um número relação a 555";
	char *linha = "====================================================";
	
	// Vars Code
	float num;
	const float div = 555;
	// Code
	do{
		system("cls");
		strcenter(linha,title,32);
		printf("Digite um valor inteiro: (-1 para sair)\n> ");
		scanf("%f",&num);
		fflush(stdin);
		printf("Percentual: %.2f%% em relação a %0.f\n",(num/div)*100,div);
		printf("%s\n",linha);
		system("PAUSE");
	} while (num != (-1));
}