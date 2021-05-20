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
	char *title = "Divisão e resto de uma equação!";
	char linha[30] = "=============================";
	int nums[2] = {0, 0}, // Dividendo e divisor 
	result[2] = {0, 0}; // Quociente e resto
	
	// Code
	for (int i = 0; i < 2; i++){
		do{
			printf("%s\n%s\n%s\n",linha,title,linha);
			printf("Número %i:\n> ",i);
			scanf("%i",&nums[i]);
			fflush(stdin);
			if(nums[i] <= 0){
				printf("%s\nPor favor insira um válido e diferente de 0!\n%s\n",linha,linha);
				system("PAUSE");
			}
			system("cls");
		} while(nums[i] <= 0);
	}
	result[0] = nums[0]/nums[1];
	result[1] = nums[0]%nums[1];
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("%i/%i é igual a: ",nums[0],nums[1]);
	printf("%i e tem como resto %i\n%s\n",result[0],result[1],linha);
	system("PAUSE");
}