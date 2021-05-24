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

	// Vars Decorator
	char *title = "Sistema de multas de carro";
	char linha[30] = "=============================";
	char spaces = 256;

	// Vars Code
	float multasValor[3] = {130, 195, 855}; // (20% = R$ 130, 50% = R$ 195, >50% = R$ 855)
	float velocidade = 0;
	float limite = 80;
	float multa = 0; 
	char placa[8];
	bool multado;

	// Code
	printf("%s\n%2.c%s\n%s\n",linha,spaces,title,linha);
	printf("Insira a velocidade do veículo\n> ");
	scanf("%f",&velocidade);
	fflush(stdin);
	if(velocidade > limite){
		multado = true;
		if(velocidade/limite <= 1.2){
			multa += multasValor[0];
		} 
		else if(velocidade/limite <= 1.5){
			multa += multasValor[1];
		} else {
			multa += multasValor[2];
		}
	}
	float ultrapassou = ((velocidade/limite) - 1)*100;
	printf("%s\nMotorista multado em: R$ %.2f\nUltrapassou o limite de velocidade em (%0.f%%)\n%s\n",linha,multa,ultrapassou,linha);
	system("PAUSE");
}
