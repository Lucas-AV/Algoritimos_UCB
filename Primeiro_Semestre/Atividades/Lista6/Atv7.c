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
    setlocale(LC_ALL, "Portuguese-brazillian");
	system("cls");

	// Vars
	char *title = "Urna eletronica: Melhor jogador de todos os tempos";
	char *linha = "====================================================";
	char spaces = 256;
	// Vars Code
	char *Candidatos[4];
	Candidatos[0] = "Em branco";
	Candidatos[1] = "Pelé";
	Candidatos[2] = "Maradona";
	int Code[3] = {0,25,33};
	int Votos[4] = {0,0,0,0};
	int total = 0;
	int VotoAtual;
	char SN;
	bool won;

	// Code
	do{
		system("cls");
		strcenter(linha,title,32);
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Escolha uma das opções:\n");
		for(int i = 0; i < 3; i++){
			printf("%i. ",Code[i]);
			printf("%s\n",Candidatos[i]);
		}
		printf("Qualquer outro número será nulo!\n%s\n> ",linha);
		scanf("%i",&VotoAtual);
		fflush(stdin);
		switch (VotoAtual){
			case 0:
				printf("%s\nGostaria de votar em: %s (S\\N)\n%s\n",linha,Candidatos[0],linha);
				printf("> ");
				scanf("%c",&SN);
				if(SN == 'S' || SN == 's'){
					Votos[0]++;
				}
				break;
			case 25:
				printf("%s\nGostaria de votar em: %s (S\\N)\n%s\n",linha,Candidatos[1],linha);
				printf("> ");
				scanf("%c",&SN);
				if(SN == 'S' || SN == 's'){
					Votos[1]++;
				}
				break;
			case 33:
				printf("%s\nGostaria de votar em: %s (S\\N)\n%s\n",linha,Candidatos[2],linha);	
				printf("> ");
				scanf("%c",&SN);
				if(SN == 'S' || SN == 's'){
					Votos[2]++;
				}
				break;
			case (-1):
				printf("%s\nGostaria de encerrar a votação? (S\\N)\n%s\n",linha,linha);	
				printf("> ");
				scanf("%c",&SN);
				if(SN == 'S' || SN == 's'){
					VotoAtual = (-1);	
				}
				break;
			default:
				printf("%s\nGostaria de votar NULO? (S\\N)\n%s\n",linha,linha);
				printf("> ");
				scanf("%c",&SN);
				if(SN == 'S' || SN == 's'){
					Votos[3]++;
				}
				break;
		}
	}while (VotoAtual >= 0);
	system("cls");
	strcenter(linha,title,32);
	for(int i = 0; i < 4; i++){
		total += Votos[i];	
	}
	for(int i = 0; i < 3; i++){
		printf("Votos: %s\n> %i (%0.f%% dos votos)\n\n",Candidatos[i],Votos[i],((float)Votos[i]/total)*100);
	}
	printf("Votos Nulos: %i\n\n",Votos[3]);
	printf("Total de votos: \n> %i Votos\n",total);
	char vencedor[100];
	for(int i = 0; i < 4; i++){
		if(Votos[i] > Votos[(i+1)%4] && Votos[i] > Votos[(i+2)%4] && Votos[i] > Votos[(i+3)%4]){
			if(i < 3){
				sprintf(vencedor,"Vencedor: %s",Candidatos[i]);
				won = true;
			}
		}
	}
	if(won != true){
		strcpy(vencedor,"Sem vencedor definido!");
	}
	strcenter(linha,vencedor,32);
}