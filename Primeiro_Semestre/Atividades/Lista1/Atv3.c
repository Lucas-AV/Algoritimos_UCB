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
	char *title = "Média aritmética de 3 números";
	char linha[30] = "=============================";
	float nums[3];
	float total = 0;
	// Code
	for(int i = 0; i < 3; i++){
		do{
			printf("%s\n%s\n%s\n",linha,title,linha);
			printf("Valor do número %i\n> ",i+1);
			scanf("%f",&nums[i]);
			fflush(stdin);
			if (nums[i] <= 0){
				printf("%s\nPor favor insira um válido e diferente de 0!\n%s\n",linha,linha);
				system("PAUSE");
			}
			system("cls");
		} while(nums[i] <= 0);
		total += nums[i];
	}
	total = total / 3;
	system("cls");
	printf("%s\n%s\n%s\n",linha,title,linha);
	for (int i = 0; i < 3; i++){
		printf("Número %i: %.2f\n",i+1,nums[i]);
	}
	printf("%s\nA média aritmética é de: %.2f\n%s\n",linha,total,linha);
	system("PAUSE");
}