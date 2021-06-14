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
	char *title = "Informação de funcionários";
	char *linha = "====================================================";

	// Vars Code
	int cod[50];
    int mes[50];
	int c = 0, j;
    int novos[3];
    int reg[3];
	// Code
	int i;
	for(i = 0; i < 50; i++){
        system("cls");
        strcenter(linha,title,32);
        printf("Insira o código do funcionário (0 para sair)\n> ");
        scanf("%i",&cod[c]);
        fflush(stdin);
        if(cod[c] == 0){
            break;
        }
        bool repetido = false;
        do{
            system("cls");
            strcenter(linha,title,32);
            printf("Insira o mês de entrada (Sem repetições)\n> ");
            scanf("%i",&mes[c]);
            fflush(stdin);
            if(mes[c] == 0){
                repetido = false;
                break;
            }
            for(i = 0; i < c; i++){
                if(mes[c] == mes[i]){
                    printf("ERROR: Mês repetido repetida!\n");
                    system("PAUSE");
                    repetido = true;
                    break;
                } else {
                    repetido = false;
                }
            }
            if(repetido == false){
                break;
            }
        } while (repetido == true);
        if(c == 0){
            novos[c] = mes[c];
            reg[c] = cod[c]; 
        }
        else if(c == 1){
            novos[c] = mes[c];
            reg[c] = cod[c]; 
        }
        else if(c == 2){
            novos[c] = mes[c];
            reg[c] = cod[c]; 
        }
        else{
            for(j = 0; j < 3; j++){
                if(novos[j] > mes[c] && (novos[j] != novos[(j+1)%2]) && (novos[j] != novos[(j+2)%2])){
                    novos[j] = mes[c];
                    reg[j] = cod[c];
                }
            }
        }
        c++;
	}

    system("cls");
    strcenter(linha,"FUNCIONÁRIOS MAIS NOVOS",32);
    for(i = 0; i < 3; i++){
        printf("Matrícula: %i\n",reg[i]);
        printf("Mês: %i\n\n",novos[i]);
    }
    printf("%s\n",linha);
}