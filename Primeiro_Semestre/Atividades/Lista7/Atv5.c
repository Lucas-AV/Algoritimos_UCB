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
	char *title = "Números repetidos dentro de 80";
	char *linha = "====================================================";

	// Vars Code
	int nums[80];
	int c = 0;  // Contador
	// Code
	int i, j;
    while (true){
        system("cls");
        strcenter(linha,title,32);
        printf("Digite o número para posição %i\n> ",c);
        scanf("%i",&nums[c]);
        fflush(stdin);
        if(nums[c] != (-1)){
            c++;
        }
        else if(nums[c] == (-1) || c == 80){
            break;
        }
    }
    int rep[80],pos[80][80];
    for(i = 0; i < c; i++){
        rep[i] = 0;
        for(j = 0; j < c; j++){
            pos[i][j] = 0;
        }
    }
    int crep = 0, reps[80]; 
    system("cls");
    strcenter(linha,"REPETIÇÕES",32);
    for(i = 0; i < c; i++){
        bool repetido;
        for(j = 0; j < c; j++){
            if(nums[i] == reps[j]){
                repetido = true;
                break;
            }
            else{
                repetido = false;
            }
        }
        for(j = 0; j < c; j++){
            if(nums[i] == nums[j]){
                rep[i]++;
                crep++;
                pos[i][j] = j;
                reps[i] = nums[i];
            }
        }
        if(repetido == false && rep[i] > 1){
            printf("O número %i aparece em: ",nums[i]);
            for(j = 0; j < c; j++){
                if(j > 0 && pos[i][j] != 0){
                    if(rep[i] > 1){
                        if(rep[i] == 2){
                            printf("%i ",pos[i][j-1]);
                        }
                        printf("%i ",pos[i][j]);
                    }
                }
            }
            printf("\n");
        }
        
        
        
    }
    printf("%s\n",linha);
}