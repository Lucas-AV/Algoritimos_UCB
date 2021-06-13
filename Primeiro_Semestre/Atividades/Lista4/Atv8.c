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
	char *title = "Felisberto VS Anacleto!";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float Anacleto = 1.50;
	float Felisberto = 1.10;
	float Cresc[2] = {0.02, 0.03};
	int anos = 0;
	
	// Code
	printf("%s\n%4.c%s\n%s\n",linha,spaces,title,linha);
	while (Anacleto > Felisberto){
		anos++;
		Anacleto += Cresc[0];
		Felisberto += Cresc[1];
	}
	printf("Se passaram %i anos...\n",anos);
	printf("Felisberto: %.2fm\nAnacleto: %.2fm\n",Felisberto,Anacleto);
	printf("Maior: Felisberto!\n");
	printf("%s\n",linha);
	system("PAUSE");
}