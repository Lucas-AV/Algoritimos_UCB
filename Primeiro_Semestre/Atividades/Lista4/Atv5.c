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
	char *title = "Lançamento de Dados";
	char *linha = "=============================";
	char spaces = 256;
	// Vars Code
	int dados = 6;

	// Code
	printf("%s\n%5.c%s\n%s\n",linha,spaces,title,linha);
	printf("> Resultado igual a 7\n");
	for(int d = 1; d < 6+1; d++){
		for(int i = 1; i < 6+1; i++){
			if((i+d)%7 == 0){
				printf("d1(%i) + d2(%i) = %i\n",d,i,i+d);
			}
		}
	}
	printf("%s\n",linha);
}