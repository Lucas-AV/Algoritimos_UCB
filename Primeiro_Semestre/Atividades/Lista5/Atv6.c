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
	char *title = "Regiões do Brasil";
	char *linha = "================================================";
	
	// Vars Code
	char *regioes[6] = {
		"Norte",
		"Nordeste",
		"Centro-Oeste",
		"Sudeste",
		"Sul",
		"Sair do programa",
	};
	char *detalhes[6];
	int opt;

	// Code
	do{
		system("cls");
		strcenter(linha,title,32);
		for(int i = 0; i != 6; i++){
			printf("%i - %s\n",(i+1)%6,regioes[i]);
		};
		printf("%s\n> ",linha);
		scanf("%i",&opt);
		fflush(stdin);
		if(opt <= 5 && opt >= 0){
			system("cls");
			strcenter(linha,title,32);
			printf("Região escolhida: %s\n",regioes[opt+1]);
			printf("%s\n",linha);
			system("PAUSE");
		}
	} while (opt != 0);
	
	
}