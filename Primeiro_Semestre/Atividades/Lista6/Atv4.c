// Lucas Alves Vilela (Github: LucasV75)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

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
	char *title = "Índice de mortalidade infantil";
	char *linha = "=====================================================";
	// Vars Code
	int Kids[4];
	char sexo;
	char morto;
	int nasc, QntNasc;
	int idade;
	int Menos24;
	int mortes = 0;
	int fem = 0,masc = 0;
	// Code
	Menos24 = 0;
	do{
		strcenter(linha,title,32);
		printf("Insira o período para a ser medido!\n> ");
		scanf("%i",&nasc);
		fflush(stdin);
		system("cls");
	}while(nasc < 0);
	
	
	strcenter(linha,title,32);
	printf("Insira a quantidade de crianças que nasceram em %i!\n> ",nasc);
	scanf("%i",&QntNasc);
	fflush(stdin);
	system("cls");

	for(int i  = 0; i < QntNasc; i++){
		strcenter(linha,"Dados de cada criança",32);
		printf("Insira a quantos meses a criança está || estava viva\n> ");
		scanf("%i",&idade);
		fflush(stdin);
		system("cls");
		do{
			strcenter(linha,"Dados de cada criança",32);
			printf("Insira o sexo da criança\n> ");
			scanf("%c",&sexo);
			fflush(stdin);
			system("cls");
			switch (sexo){
				case 'M':
					masc++;
					break;
				case 'm':
					masc++;
					break;
				case 'F':
					fem++;
					break;
				case 'f':
					fem++;
					break;
				case 'v':
					break;
				default:
					strcenter(linha,"Valor inválido tente novamente!",32);
					system("PAUSE");
					break;
			}
			if(sexo != 'v'){
				strcenter(linha,"Dados de cada criança",32);
				printf("A criança morreu?\n> ");
				scanf("%c",&morto);
				fflush(stdin);
				system("cls");
				if(morto == 'S' || morto == 's'){
					mortes++;
					if(idade <= 24){
						Menos24++;
					}
				}
			}
			
			
		}while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f' && sexo != 'v');
		
		
		if(sexo == 'v'){
			break;
		}
	}
	strcenter(linha,"Resumo dos dados coletados",32);
	printf("Total de crianças nascidas: %i",QntNasc);
	printf("Crianças que morreram: %i\n",mortes);
	printf("Menos de 24 meses: %i crianças\n",Menos24);
	printf("Crianças que morreram (Masculino): %i\n",masc);
	printf("Crianças que morreram (Feminino): %i\n",fem);
	printf("%s\n",linha);
}