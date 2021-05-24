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
	char *title = "Maior de 3 números";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float nums[3] = {0,0,0};
	float maior;
	// Code
	for(int i = 0; i < 3; i++){
		printf("%s\n%6.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira um valor para o número %i:\n> ",i+1);
		scanf("%f",&nums[i]);
		system("cls");
	}

	if(nums[0] > nums[1] && nums[0] > nums[2]){
		maior = nums[0];
	}
	else if(nums[1] > nums[0] && nums[1] > nums[2]){
		maior = nums[1];
	}
	else if(nums[2] > nums[0] && nums[2] > nums[1]){
		maior = nums[2];
	} else {
		maior = nums[0];
	}
	
	printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
	printf("O maior número de todos é: %.2f\n%s\n",maior,linha);
	system("PAUSE");
	
}