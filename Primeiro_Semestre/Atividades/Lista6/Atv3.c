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
	char *title = "Coleta de informações: Sexo e Altura!";
	char *linha = "================================================";
	
	// Vars Code
	char sexos[10];
	float alturas[10];
	int homens = 0;
	int mulheres = 0;
	float maior = 0, menor = 0;
	float AltHomens = 0, AltMulheres = 0;

	// Code
	for(int i = 0; i < 10; i++){ // Tipo de Loop 1 (For)
		do{ // Tipo de Loop 2 (do >>> while)
			strcenter(linha,title,32);
			printf("Sexo da pessoa %i\n> ",i+1);
			scanf("%c",&sexos[i]);
			system("cls");
		} while(sexos[i] != 'M' && sexos[i] != 'm' && sexos[i] != 'f' && sexos[i] && 'F');

		strcenter(linha,title,32);
		printf("Altura da pessoa %i\n> ",i+1);
		scanf("%f",&alturas[i]);
		fflush(stdin);
		system("cls");
		if(i == 0){
			maior = alturas[i];
			menor = alturas[i];
		}
		if(maior < alturas[i] && i > 0){
			maior = alturas[i];
		}
		if(menor > alturas[i] && i > 0){
			menor = alturas[i];
		}
		// Calcular quantidade homens//mulheres + altura media
		switch (sexos[i]){ // Tipo de Loop 3 (switch)
			case 'M':
				homens++;
				AltHomens += alturas[i];
				break;
			case 'm':
				homens++;
				AltHomens += alturas[i];
				break;
			case 'F':
				mulheres++;
				AltMulheres += alturas[i];
				break;
			case 'f':
				mulheres++;
				AltMulheres += alturas[i];
				break;
		}
	}
	float difHomens = AltHomens/homens;
	float difMulheres = AltMulheres/mulheres;
	if(homens == 0){
		difHomens = 0.00;
	}
	if(mulheres == 0){
		difMulheres = 0.00;
	}
	system("cls");
	strcenter(linha,"Dados coletados",32);
	printf("Altura média (Mulheres): %.2fm\n",difMulheres);
	printf("Altura média (Homens): %.2fm\n",difHomens);
	printf("Maior altura: %.2fm\n",maior);
	printf("Menor altura: %.2fm\n",menor);
	printf("Mulheres: %i pessoas\n",mulheres);
	printf("Homens: %i pessoas\n",homens);
	printf("%s\n",linha);
}