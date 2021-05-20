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
	char *title = "Calcular o salário de alguém";
	char linha[30] = "=============================";
	char sexo;
	int sex = 0;
	char matricula[100];
	int horasTrabalhadas = 0;
	float ganhoHora = 0, salario = 0;
	
	// Code
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("Informe sua matricula:\n> ");
	scanf("%s",&matricula);
	fflush(stdin);
	system("cls");
	// sexo
	do{
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Infome o sexo:\n> ");
		scanf("%c",&sexo);
		fflush(stdin);
		switch (sexo) {
			case 'M':
				sex++;
				break;

			case 'F':
				sex++;
				break;

			case 'm':
				sexo = 'M';
				sex++;
				break;
				
			case 'f':
				sexo = 'F';
				sex++;
				break;
		}
		if (sex == 0){
			printf("%s\nInsira um valor válido para sexo (M/F)\n%s\n",linha,linha);
			system("PAUSE");
			system("cls");
		} else {
			break;
		}
	} while(sex == 0);
	
	// Horas Trabalhadas
	do{
		system("cls");
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Infome suas horas trabalhadas:\n> ");
		scanf("%i",&horasTrabalhadas);
		fflush(stdin);
		if (horasTrabalhadas <= 0){
			printf("%s\nInsira um valor válido e maior do que 0!\n%s\n",linha,linha);
			system("PAUSE");
			system("cls");
		}
	} while(horasTrabalhadas <= 0);

	do{
		system("cls");
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Infome quanto você ganha por hora:\n> ");
		scanf("%f",&ganhoHora);
		fflush(stdin);
		if (ganhoHora <= 0){
			printf("%s\nInsira um valor válido e maior do que 0!\n%s\n",linha,linha);
			system("PAUSE");
			system("cls");
		}
	} while(ganhoHora <= 0);
	system("cls");
	printf("%s\n%s\n%s\n",linha,title,linha);
	printf("Matrícula: %s\n",matricula);
	printf("Sexo: %c\n",sexo);
	printf("Horas trabalhadas: %i\n",horasTrabalhadas);
	printf("Ganho por hora: %.2f\n",ganhoHora);
	salario = horasTrabalhadas*ganhoHora;
	printf("Salario: %.2f\n",salario);
	printf("%s\n",linha);
	system("PAUSE");
}