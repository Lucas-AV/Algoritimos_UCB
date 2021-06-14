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
	char *title = "Notas de 30 alunos";
	char *linha = "====================================================";

	// Vars Code
	float notas[50];
	
	// Code
	int i, alunos;
    do{
        system("cls");
        strcenter(linha,title,32);
        printf("Insira a quantidade de alunos\n> ");
        scanf("%i",&alunos);
        fflush(stdin);
    } while (alunos >= 50 || alunos < 1);
    
	
	for(i = 0; i < alunos; i++){
        do{
            system("cls");
            strcenter(linha,title,32);
            printf("Nota do aluno %i (Insira um valor maior ou igual 0!)\n> ",i);
            scanf("%f",&notas[i]);
            fflush(stdin);
        }while (notas[i] < 0);
	}
    
    system("cls");
    strcenter(linha,"NOTAS DOS ALUNOS",32);
    for(i = 0; i < alunos; i++){
        printf("Nota do aluno %i: %.2f\n",i,notas[i]);
    }
    printf("%s\n",linha);
}