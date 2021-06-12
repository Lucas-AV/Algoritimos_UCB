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
    setlocale(LC_ALL, "Portuguese-brazillian");
	
	// Vars
	char *title = "Companhia de teatro (Lucro e Gasto)";
	char *linha = "=====================================================";
	// Vars Code
    float Ingresso = 15.00; 
    int Vendidos = 120; 
    float Despesas = 600.00; 
    float Reducao = 3.00; 
    int Aumento = 26; 
    float Vari[2] = {15.00, 3.00}; 
    float Taxa = 3.00;
	// Code
	strcenter(linha,title,32);
    printf("> %i ingressos sendo vendidos a R$ %.2f\n",Vendidos,Ingresso);
    printf("Total: R$ %.2f\n",Ingresso*Vendidos);
    printf("Lucro: R$ %.2f\n",Ingresso*Vendidos - Despesas);
    printf("Gasto: R$ %.2f\n",Despesas);
    printf("%s\n",linha);
    for(int i = 1; i != Ingresso/Reducao; i++){
        printf("> %i ingressos sendo vendidos a R$ %.2f\n",Vendidos+(i*26),Ingresso-(Reducao*i));
        printf("Total: R$ %.2f\n",(Vendidos+(i*26))*(Ingresso-(Reducao*i)));
        printf("Lucro: R$ %.2f\n",(Vendidos+(i*26))*(Ingresso-(Reducao*i)) - Despesas);
        printf("Gasto: R$ %.2f\n",Despesas);
        printf("%s\n",linha);
    }
    
    system("PAUSE");
}