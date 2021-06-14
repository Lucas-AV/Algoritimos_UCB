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
	char *title = "Notas de 80 alunos";
	char *linha = "====================================================";

	// Vars Code
	int notas[80];
	int rp[11];
	// Code
	int i, j, c = 0;
	for(i = 0; i < 11; i++){
        rp[i] = 0;
    }
	for(i = 0; i < 80; i++){
        do{
            system("cls");
            strcenter(linha,title,32);
            printf("Insira a nota do aluno %i (-1 para sair)\n> ",i);
            scanf("%i",&notas[i]);
            fflush(stdin);
            if(notas[i] == (-1)){
                break;
            }
            else if(notas[i] != (-1) && notas[i] >= 0 && notas[i] <= 10){
                break;
            }
        } while (notas[i] > 10 || notas[i] < 0);
        if((int)notas[i] == (-1)){
            break;
        }
        else{
            c++;
        }
	}
    system("cls");
    strcenter(linha,"RESUMO DAS DATAS",32);
    printf("Número de alunos:%i\n",c);
    for(i = 0; i < 11; i++){
        for(j = 0; j < c; j++){
            if(notas[j] == i){
                rp[i]++;
            }
        }
        printf("Nota\t%i: \t%i alunos\n",i,rp[i]);
    }
    printf("Mais frequente: ");
    int temp[2];
    for(i = 0; i < 11; i++){
        if(i == 0){
            temp[0] = i;
            temp[1] = rp[i];
        }
        else if(temp[1] < rp[i]){
            temp[0] = i;
            temp[1] = rp[i];
        }
    }
    printf("Nota %i\n",temp[0]);
    printf("%s\n",linha);
}