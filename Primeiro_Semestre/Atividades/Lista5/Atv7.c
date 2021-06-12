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
	char *title = "Números em ordem crescente";
	char *linha = "====================================================";
	
	// Vars Code
	int nums[3];
	int ord[3];
	// Code
	for(int i = 0; i < 3; i++){
		system("cls");
		strcenter(linha,title,32);
		printf("Insira um valor para o número %i\n> ",i+1);
		scanf("%i",&nums[i]);
		fflush(stdin);
	}
	for(int i = 0; i < 3; i++){
		// 0 > 1 && 0 > 2 || 1 > 2 && 1 > 0 || 2 > 0 && 2 > 1
		if(nums[i] > nums[(i+1)%3] && nums[i] > nums[(i+2)%3]){
			ord[0] = nums[i];
		}
		else if(nums[i] > nums[(i+1)%3] && nums[i] < nums[(i+2)%3] || nums[i] < nums[(i+1)%3] && nums[i] > nums[(i+2)%3]){
			ord[1] = nums[i];
		}
		else if(nums[i] < nums[(i+1)%3] && nums[i] < nums[(i+2)%3]){
			ord[2] = nums[i];
		} else {
			ord[i] = nums[i];
		}
	}
	strcenter(linha,"Em ordem crescente",32);
	printf("%i >> %i >> %i\n%s\n",ord[0],ord[1],ord[2],linha);
}