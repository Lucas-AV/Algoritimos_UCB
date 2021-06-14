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

void Media(float salarios[100], int range){
    int i;
    float total = 0;
    for(i = 0; i < range; i++){
        total += salarios[i];
    }
    printf("A média salarial é de: R$ %.2f\n",(float)total/range);
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");

	// Vars
	char *title = "Dados de até 100 funcionários";
	char *linha = "====================================================";

	// Vars Code
	float salarios[100];
	int cod[100];
    int c = 0;  // contador de funcionários
    float maior = 0, menor = 0;
    int maiorpos = 0, menorpos = 0;
	// Code
	int i;
    do{
        bool repetido = false;
        do{
            system("cls");
            strcenter(linha,title,32);
            printf("Código do funcionário %i\n> ",c);
            scanf("%i",&cod[c]);
            fflush(stdin);
            if(cod[c] == 0){
                repetido = false;
                break;
            }
            for(i = 0; i < c; i++){
                if(cod[c] == cod[i]){
                    printf("ERROR: Código repetido repetida!\n");
                    system("PAUSE");
                    repetido = true;
                    break;
                } else {
                    repetido = false;
                }
            }
            if(repetido == false){
                break;
            }
        } while (repetido == true);
        if(cod[c] == 0){
            repetido = false;
            break;
        }
        
        printf("Insira o salário do funcionário %i\n> ",c);
        scanf("%f",&salarios[c]);
        fflush(stdin);
        if(c == 0){
            maior = salarios[c];
            maiorpos = c;
            menor = salarios[c];
            menorpos = c;
        }
        else{
            if(salarios[c] > maior){
                maior = salarios[c];
                maiorpos = c;
            }
            else if(salarios[c] < menor){
                menor = salarios[c];
                menorpos = c;
            }
        }
        c++;
    } while (true);
    
    system("cls");
    strcenter(linha,"DADOS COLETADOS",32);
    if(c > 0){
        for(i = 0; i < c; i++){
            printf("Funcionário n%i\n",i);
            printf("Código: %i\n",cod[i]);
            printf("Salário: %.2f\n\n",salarios[i]);
        }
        printf("Funcionário n%i (Maior salário)\n",maiorpos);
        printf("Maior salário: %.2f\n",maior);
        printf("Código: %i\n\n",cod[maiorpos]);

        printf("Funcionário n%i (Menor salário)\n",menorpos);
        printf("Maior salário: %.2f\n",menor);
        printf("Código: %i\n\n",cod[menorpos]);

        Media(salarios,c);
        printf("%s\n",linha);
    }
    else{
        strcenter(linha,"ERROR: DADOS INSUFICIENTES!",32);
    }
}