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
	int i;
    if(strlen(line) % 2 != 0){
        Mid += 1; // Acts like a counter
    }
    for(i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in left-side
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // Print the main string

    for(i = 0; i < Mid/2; i++){
        printf("%1c",digit); // Print a digit in right-side
    }
    printf("\n%s\n",line); // Print the final line with \n
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese-brazillian");

	// Vars
	char *title = "Ordenação de 30 caracteres!";
	char *linha = "====================================================";

	// Vars Code
	char list[30];
	int nlist[30];
	// Code
	int i, j;
	
    // Registro de char
	for(i = 0; i < 30; i++){
        system("cls");
        strcenter(linha,title,32);
		printf("Digite o caracter para posição n%i\n> ",i);
        scanf("%c",&list[i]);
        nlist[i] = tolower(list[i]); // Conversão númerica
        fflush(stdin);
	}
    char opt;
    printf("Digite um digito para pesquisar na lista\n> ");
    scanf("%c",&opt);

    // Ordenação
    int temp;
    for(i = 0; i < 30; ++i){
       for (j = i + 1; j < 30; ++j){// Conta posição a partir do valor de i + 1
            if (nlist[i] > nlist[j]){
                temp = nlist[i];    // Registra o ultimo valor como temporário
                nlist[i] = nlist[j];// Troca a posição dele com a posição j
                nlist[j] = temp;    // Transforma j no valor temporário
            }
        }
    }
    // Resultado
    system("cls");
    strcenter(linha,title,32);
    printf("Lista ordenada: ");
    for(i = 0; i < 30; i++){
        printf("%c ",nlist[i]);
    }
    bool encontrado;
    printf("\n%s\n",linha);
    for(i = 0; i < 30; i++){
        if((char)nlist[i] == opt){
            printf("%c encontrado em: %i\n",nlist[i],i);
            encontrado = true;
        }
    }
    if(encontrado == false){
        printf("%c não encontrado!\n",opt);
    }
    printf("%s\n",linha);
}