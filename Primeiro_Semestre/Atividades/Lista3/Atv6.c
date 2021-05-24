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
	char *title = "Calculadora de média de notas";
	char linha[30] = "=============================";
	char spaces = 256;
	// Vars Code
	float Notas[100];
	float Media = 0;
	char Alunos[100][100];
	int Contador = 0;
	float NotaAtual;
	// Code
	
	do{
		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira o nome do aluno %i\n> ",Contador+1);
		gets(Alunos[Contador]);
		fflush(stdin);
		system("cls");

		printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
		printf("Insira a nota do aluno %s\n> ",Alunos[Contador]);
		scanf("%f",&Notas[Contador]);
		fflush(stdin);
		system("cls");

		NotaAtual = Notas[Contador];
		if(NotaAtual < 0){
			printf("%s\n%c%s\n%s\n",linha,spaces,title,linha);
			for(int i = 0; i < Contador; i++){
				if(Notas[i] >= 0){
					printf("Aluno: %s (%i)\n",Alunos[i],i+1);
					printf("Nota: %.2f\n\n",Notas[i]);
					Media += Notas[i];
				}
			}
			printf("Total de alunos: %i\n",Contador);
			printf("Media Total: %.2f\n",Media/Contador);
			printf("%s\n",linha);
			system("PAUSE");
			system("cls");
			break;
		} else {
			Contador++;
		}
	}while(NotaAtual >= 0);
}