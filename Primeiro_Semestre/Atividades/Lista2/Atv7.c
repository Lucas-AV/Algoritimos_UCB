// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Diferença entre 2 números";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int nums[2];
	// Code
	for(int i = 0; i < 2; i++){
		printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor do número %i\n> ",i+1);
		scanf("%i",&nums[i]);
		fflush(stdin);
		system("cls");
	}
	printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
	if(nums[0] > nums[1]){
		printf("A diferença entre: %i e %i é: %i\n",nums[0],nums[1],nums[0]-nums[1]);
	}
	else if(nums[1] > nums[0]){
		printf("A diferença entre %i e %i é: %i\n",nums[1],nums[0],nums[1]-nums[0]);
	} else {
		printf("Os números %i e %i são iguais!\n",nums[0],nums[1]);
	}
	printf("%s\n",linha);
	system("PAUSE");
}