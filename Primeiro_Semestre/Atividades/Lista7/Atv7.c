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

float aumentar(int objPos, float obj, float aumento){
    printf("CD n%i\n",objPos);
    printf("Preço antes:\t%.2f\n",obj);
    printf("Preço depois:\t%.2f\n\n",obj*(1+(aumento/100)));
}

int main(){
	// Comandos para configurar o idioma do terminal
	system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");

	// Vars
	char *title = "Loja de CDs!";
	char *linha = "====================================================";

	// Vars Code
	float CDs[100];
	float a1 = 10, a2; // Aumentos (a1 = 10% e a2 = x%)
	char *Menu[3];
    Menu[0] = "Aumentar os preços em 10%";
    Menu[1] = "Digitar aumento em %";
    Menu[2] = "Não aumentar nada";
    // Code
	int i, c = 0;	
	for(i = 0; i < 100; i++){
        do{
            system("cls");
            strcenter(linha,title,32);
            printf("Cadastrar o preço do CD n%i (0 ou menos para sair!)\n> ",i);
            scanf("%f",&CDs[i]);
            fflush(stdin);
            if(CDs[i] <= 0){
                break;
            }
            else{
                c++;
            }
        } while (CDs[i] < 0);
        
        if(CDs[i] <= 0){
            break;
        }
	}
    int opt;
    do{
        system("cls");
        strcenter(linha,"OPÇÕES DE AUMENTO",32);
        for(i = 0; i < 3; i++){
            printf("%i. %s\n",i+1,Menu[i]);
        }
        printf("%s\n",linha);
        printf("Digite o código da opção\n> ");
        scanf("%i",&opt);
        fflush(stdin);
        if(opt == 1){
            system("cls");
            strcenter(linha,"Aumento de 10%",32);
            for(i = 0; i < c; i++){
                aumentar(i,CDs[i],a1);
            }
            printf("%s\n",linha);
            break;
        }
        else if(opt == 2){
            printf("Aumentar em quantos %%?\n> ");
            scanf("%f",&a2);

            system("cls");
            char format[100];
            sprintf(format,"Aumento de %0.f%%",a2);
            strcenter(linha,format,32);
            for(i = 0; i < c; i++){
                aumentar(i,CDs[i],a2);
            }
            printf("%s\n",linha);
            break;
        }
        else if(opt == 3){

            system("cls");
            strcenter(linha,"RESUMO DOS PREÇOS (SEM AUMENTO)",32);
            for(i = 0; i < c; i++){
                aumentar(i,CDs[i],0);
            }
            printf("%s\n",linha);
            break;
        }
    } while (opt < 1 || opt > 3);
    
    

}