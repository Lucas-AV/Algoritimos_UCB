// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Formar datas";
	char linha[30] = "=============================";
	char spaces = 256;
/*
0	Janeiro	tem 31 dias
1	Fevereiro	tem 28 dias (29 dias nos anos bissextos)
2	Março	tem 31 dias
3	Abril	tem 30 dias
4	Maio	tem 31 dias
5	Junho	tem 30 dias
6	Julho	tem 31 dias
7	Agosto	tem 31 dias
8	Setembro	tem 30 dias
9	Outubro	tem 31 dias
10	Novembro	tem 30 dias
11	Dezembro	tem 31 dias
*/
	int dia;
	int mes;
	int ano;
	int  mesesDias[12];
	mesesDias[0] = 31;
	mesesDias[1] = 28;
	mesesDias[2] = 31;
	mesesDias[3] = 30;
	mesesDias[4] = 31;
	mesesDias[5] = 30;
	mesesDias[6] = 31;
	mesesDias[7] = 31;
	mesesDias[8] = 30;
	mesesDias[9] = 31;
	mesesDias[10] = 30;
	mesesDias[11] = 31;
	
	bool data;
	// Code
	do{
		system("cls");
		printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor para o dia:\n> ");
		scanf("%i",&dia);
		fflush(stdin);
		system("cls");
		
		printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor para o mês:\n> ");
		scanf("%i",&mes);
		fflush(stdin);
		system("cls");

		printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o valor para o ano:\n> ");
		scanf("%i",&ano);
		fflush(stdin);
		system("cls");

		if(ano%4 == 0 && ano % 100 != 0){
			mesesDias[1] = 29;
		}
		if(dia >= 1 && dia <= mesesDias[mes-1] && ano >= 1){
			data = true;
		}

		printf("%s\n%9.c%s\n%s\n",linha,spaces,title,linha);
		if(data == true){
			printf("Data formada com sucesso!\n");
		} else {
			printf("A data não pode ser formada!\n");
		}
		printf("Data: %i/%i/%i\n",dia,mes,ano);
		printf("%s\n",linha);
		system("PAUSE");
	} while (data == false);
}