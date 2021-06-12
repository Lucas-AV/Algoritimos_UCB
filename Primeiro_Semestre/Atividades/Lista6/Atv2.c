// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void strcenter(char *line, char *string, char digit){
    int Mid = strlen(line)-strlen(string); // len(line) - len(string) == Lenght difference between line and string
    printf("%s\n",line);
    if(strlen(line) % 2 != 0){
        Mid += 1; // Acts like a counter
    }
    for(int i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in left-side
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // Print the main string

    for(int i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in right-side
    }
    printf("\n%s\n",line); // Print the final line with \n
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
	system("cls");

	// Vars
	char *title = "Números fatoriais com loop while!";
	char *linha = "================================================";
	// Vars Code
	int fatorial,resultado;

	// Code
	do{
		resultado = 1;
		system("cls");
		strcenter(linha,title,32);
		printf("Insira um valor inteiro para obter seu fatorial\n> ");
		scanf("%i",&fatorial);
		printf("%s\n",linha);
		fflush(stdin);
		if(fatorial != 0){
			for(int i = 1; i < fatorial+1; i++){
				printf("%i * ",resultado);
				resultado *= i;
				if(resultado <= 0){
					resultado = 1;
				}
				printf("%i = %i\n",i, resultado);
			}
			char strResultado[100];
			sprintf(strResultado,"Resultado: %i",resultado); // strcpy para string formatada! >>> Extremamente útil para funções como a minha strcenter!
			strcenter(linha,strResultado,32);
			system("PAUSE");
		} else {
			char sair;
			printf("Digitar 0 está programado para sair do programa\n");
			printf("Deseja calcular o valor de 0!? (S/N)\n> ");
			scanf("%c",&sair);
			if(sair == 'S' || sair == 's'){
				printf("%s\n%i fatorial é sempre igual a 1!\n%s\n",linha,fatorial,linha);
				fatorial = 1; // Eviva que o programa seja encerrado
				system("PAUSE");				
			} else {
				strcenter(linha,"Saindo do programa...",32);
				break;
			}
		}
	}while (fatorial != 0);
	
}