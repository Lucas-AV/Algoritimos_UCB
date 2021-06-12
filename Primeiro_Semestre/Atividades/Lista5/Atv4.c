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
	char *Equips[5] = {
		"Cadeira", 
		"Mesa de computador", 
		"Estante de livros", 
		"Mesa de impressora",
		"Estante de CD"
	};
	int opt;
	// Code
	do{
		system("cls");
		strcenter(linha,title,32);
		for(int i = 0; i < 5; i++){
			printf("%i. %s\n",i+1,Equips[i]);
		}
		printf("%s\n",linha);
		printf("Insira o código do equipamento desejado: (-1 para sair)\n> ");
		scanf("%i",&opt);
		fflush(stdin);

		system("cls");
		char Format[100];
		if(opt <= 5 && opt >= 0){
			strcenter(linha,title,32);
			sprintf(Format,"Equipamento escolhido: %s",Equips[opt-1]);
			strcenter(linha,Format,32);
		} 
		else if(opt == (-1)){
			break;
		} 
		else {
			strcenter(linha,title,32);
			strcenter(linha,"O equipamento ainda não está disponível!",32);
		}
		system("PAUSE");
	} while(opt != (-1));
}