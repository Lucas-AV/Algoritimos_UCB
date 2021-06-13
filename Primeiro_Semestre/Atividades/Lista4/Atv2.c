// Lucas Alves Vilela (Github: LucasV75)
// Gostaria de dar um foco especial nessa atividade em específico pois eu fiquei muito tempo fazendo ela
// Busquei por uma forma de fazer esse código rodar sem precisar de vários IFs diferentes (Foi muito mais díficil do que eu pensava chegar nessa conclusão)
// Este método começa a partir da 124 e utiliza as variáveis que estão entre as linhas 59 e 102
// As datas utilizadas como referência aqui para calcular os signos estão disponíveis em: https://pt.wikipedia.org/wiki/Zod%C3%ADaco
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	system("cls");

	// Vars
	char *title = "Sistema de signos";
	char linha[100] = "================================";
	char spaces = 256;

	// Vars Code
	char *meses[12];	
	meses[0] = "Janeiro";
	meses[1] = "Fevereiro";
	meses[2] = "Março";
	meses[3] = "Abril";
	meses[4] = "Maio";
	meses[5] = "Junho";
	meses[6] = "Julho";
	meses[7] = "Agosto";
	meses[8] = "Setembro";
	meses[9] = "Outubro";
	meses[10] = "Novembro";
	meses[11] = "Dezembro";

	int mesesDias[12];	// Dias por meses
	mesesDias[0] = 31;
	mesesDias[1] = 28;
	mesesDias[2] = 31;
	mesesDias[3] = 30;
	mesesDias[4] = 31;
	mesesDias[5] = 30;
	mesesDias[6] = 31;
	mesesDias[7] = 31;
	mesesDias[8] = 30;
	mesesDias[9] = 31;
	mesesDias[10] = 30;
	mesesDias[11] = 31;

	char *Signos[13];			// Nomes dos signos + datas
	Signos[0] = "Capricórnio"; 	// 19 de meses[0] a 15 de meses[1]
	Signos[1] = "Aquário"; 		// 16 de meses[1] a 11 de meses[2]
	Signos[2] = "Peixes"; 		// 12 de meses[2] a 18 de meses[3]
	Signos[3] = "Áries"; 		// 19 de meses[3] a 13 de meses[4]	
	Signos[4] = "Touro"; 		// 14 de meses[4] a 19 de meses[5]	
	Signos[5] = "Gêmeos"; 		// 20 de meses[5] a 20 de meses[6]	
	Signos[6] = "Câncer"; 		// 21 de meses[6] a 9 de meses[7]
	Signos[7] = "Leão"; 		// 10 de meses[7] a 15 de meses[8]
	Signos[8] = "Virgem"; 		// 16 de meses[8] a 30 de meses[9]
	Signos[9] = "Libra"; 		// 31 de meses[9] a 22 de meses[10]
	Signos[10] = "Escorpião"; 	// 23 de meses[10] a 29 de meses[10]
	Signos[11] = "Serpentário"; // 30 de meses[10] a 17 de meses[11]
	Signos[12] = "Sagitário"; 	// 18 de meses[11] a 18 de meses[0]

	int SignosDatas[26] = { // Informações referentes a dia e mês de cada signo respectivamente
		19, 0,  // Capricórnio
		16, 1,  // Aquário
		12, 2,  // Peixes
		19, 3,  // Áries
		14, 4,  // Touro
		20, 5,  // Gêmeos
		21, 6,  // Câncer
		10, 7,  // Leão
		16, 8,  // Virgem
		31, 9,  // Libra
		23, 10, // Escorpião
		30, 10, // Serpentário
		18, 11, // Sagitário
	};
	int dia, mes;

	// Code
	do{
		system("cls");
		char *signo[2];
		strcenter(linha,title,32);
		printf("Insira o dia em que você nasceu: (0 para sair)\n> ");
		scanf("%i",&dia);
		fflush(stdin);
		system("cls");

		strcenter(linha,title,32);
		printf("Insira o mês em que você nasceu: (0 novamente para sair)\n> ");
		scanf("%i",&mes);
		fflush(stdin);
		system("cls");

        strcenter(linha,title,32);
        int c = 1, s = 0;	// São apenas contadores
        bool identificado;	// Bool para parar o loop quando encontrar o signo
        for(int i = 0; i < 26; i++){
            if(c % 2 == 0){
                if((dia > mesesDias[SignosDatas[(i)%26]] || dia < 1 || mes > 12 || mes < 1) && (dia != 0 && mes != 0)){
                    strcenter(linha,"ERROR: DATA INVÁLIDA!",32);
                    break;
                }
                else if(dia == 0 && mes == 0){
                    strcenter(linha,"Saindo do sistema. . .",32);
                    break;
                }
				// Identifica se o dia e o é menor ou igual do que o do signo correspondente
                else if(dia >= SignosDatas[(i-1)%26] && (mes-1) == SignosDatas[i%26]){
                    printf("> Seu signo é: %s\n",Signos[s]);
                    printf("> Data: %i/%i\n",dia,mes);
                    identificado = true;
                }
				// Identifica se o dia fornecido é menor do que o signo que seria escolhido anteriormente
                else if(dia < SignosDatas[(i-1)%26] && (mes-1) == SignosDatas[i%26]){
                    // Caso essa substração dê menos 1 o script coloca o valor de s para ser 12 pois o C não identifica números para index menores do que 0
					if((s-1) == (-1)){
                        s = 12;
                    } else {
                        s = (s-1);
                    }
                    printf("> Seu signo é: %s\n",Signos[s%13]);
                    printf("> Data: %i/%i\n",dia,mes);
                    identificado = true;
                }
                // Verifica se o signo foi fornecido
                if(identificado == true){
                    identificado = false;	// Retorna o valor para padrão
                    break;					// Acaba com o loop for e retorna para o while
                }
                c %= 2;	// Contador para divisão (A cada 2 ele retorna para 0)
                s++;	// Contador para signo
            }
            c++;
        }
		printf("%s\n",linha);
		system("PAUSE");
	}while (dia != 0 || mes != 0);
}