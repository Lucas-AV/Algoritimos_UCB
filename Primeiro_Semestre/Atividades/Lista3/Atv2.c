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
	char *title = "Multiplicação sem sinal";
	char linha[100] = "=============================";
	char spaces = 256;
	// Vars Code
	int nums[2] = {0, 0}, Resultado;

	// Code
	do{
		Resultado = 0;
		for(int i = 0; i < 2; i++){
			printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
			printf("Insira um valor para o número %i (0 para sair)\n> ",i+1);
			scanf("%i",&nums[i]);
			fflush(stdin);
			system("cls");
		}
		for(int i = 0; i < nums[1]; i++){
			Resultado += nums[0];
		}
		if(nums[0] != 0 && nums[1] != 0){
			printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
			printf("Multiplicação: %i*%i = %i\n",nums[0],nums[1],Resultado);
			printf("%s\n",linha);
			system("PAUSE");
		} else {
			printf("%s\nSaindo do sistema...\n%s\n",linha,linha);
			system("PAUSE");
		}
	} while(nums[0] != 0 && nums[1] != 0);
	
	
	system("PAUSE");
}