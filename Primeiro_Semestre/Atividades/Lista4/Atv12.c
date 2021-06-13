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
	char *title = "Sistema de Votação Eleitoral";
	char *linha = "==============================";
	char spaces = 256;
	// Vars Code
	char *Candidatos[6];
	Candidatos[0] = "Fulano";
	Candidatos[1] = "Ciclano";
	Candidatos[2] = "Deutrano";
	Candidatos[3] = "Beutrano";
	Candidatos[4] = "Voto nulo";
	Candidatos[5] = "Voto em branco";
	int Votos[6] = {0,0,0,0,0,0};
	int total = 0;
	int VotoAtual;
	// Code
	do{
		system("cls");
		printf("%s\n%s\n%s\n",linha,title,linha);
		printf("Escolha uma das opções:\n");
		for(int i = 0; i < 6; i++){
			printf("%i. %s\n",i+1,Candidatos[i]);
		}
		printf("0. Finalizar\n%s\n> ",linha);
		scanf("%i",&VotoAtual);
		fflush(stdin);
		if(VotoAtual > 0 && VotoAtual <= 6){
			Votos[VotoAtual-1]++; // 0 a 5
		} 
		else if(VotoAtual < 1 && VotoAtual != 0 || VotoAtual > 6 && VotoAtual != 0){
			printf("%s\nOpção %i não encontrada!\n%s\n",linha,VotoAtual,linha);
			system("PAUSE");
		}
	}while (VotoAtual != 0);
	system("cls");
	printf("%s\n%s\n%s\n",linha,title,linha);
	for(int i = 0; i < 6; i++){
		total += Votos[i];	
	}
	for(int i = 0; i < 6; i++){
		printf("Votos: %s\n> %i (%0.f%% dos votos)\n\n",Candidatos[i],Votos[i],((float)Votos[i]/total)*100);
	}
	printf("Total de votos: \n> %i Votos\n",total);
	printf("%s\n",linha);
}