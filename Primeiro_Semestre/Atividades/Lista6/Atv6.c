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
	system("cls");

	// Vars
	char *title = "Calcular tamanho dos algarismos";
	char *linha = "=====================================================";
	
	// Vars Code
    int num;
	
	// Code
	do{
        char conv[100];
        system("cls");
        strcenter(linha,title,32); // 255 no lugar de 32 sem o setlocale(LC_ALL, "Portuguese");
        printf("Insira um valor númerico inteiro! (0 para sair)\n");
        printf("> ");
        scanf("%d",&num);
        itoa(num,conv,10);
        fflush(stdin);
		if(num == 0){
			break;
		}
        printf("%s\n",linha);
        printf("%s tem %i algarismos\n",conv,strlen(conv));
	    printf("%s\n",linha);
        system("PAUSE");
    }while (num != 0);
}