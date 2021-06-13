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
	char *title = "20 Fibonaccis!";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	int Fib[20] = {1,};
	int temp = 1;
	// Code
	printf("%s\n%8.c%s\n%s\n",linha,spaces,title,linha);
	for(int i = 0; i < 20; i++){
		if(i > 0){
			Fib[i] = Fib[i-1] + temp;
			printf("Fib%i = %i (%i + %i)\n",i+1,Fib[i],Fib[i-1],(Fib[i] - Fib[i-1]));
			temp = Fib[i-1];
		} else {
			printf("Fib%i = %i\n",i+1,Fib[i]);
		}
	}
	printf("%s\n",linha);
	system("PAUSE");
}