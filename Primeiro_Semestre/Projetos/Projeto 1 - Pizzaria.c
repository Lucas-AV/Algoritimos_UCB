// github: LucasV75
#include <stdio.h>   // Inputs e outputs em C
#include <stdlib.h>  // Padrão do C
#include <locale.h>  // Configura o idioma do terminal
#include <ctype.h>   // Serve para verificar os tipos de variáveis
#include <stdbool.h> // Adiciona o tipo de variável bool ao C
#include <Windows.h> // Inclui a função "sleep" e mais algumas outras
// Cores
#define GRN "\e[1;32m"
#define RED "\e[1;31m"
#define RST "\e[0m"

// Utilidades!
void strcenter(char *line, char *string, char digit, bool color){
    int lenString = strlen(string);
    if(color == true){
        lenString -= 10;
    }
    int Mid = strlen(line)-lenString; // len(line) - len(string) == Lenght difference between line and string
    printf("%s\n",line);
    if(strlen(line) % 2 != 0){
        Mid += 1; // Acts like a counter
    }
    for(int i = 0; i < Mid/2; i++){
        printf("%c",digit); // Print a digit in left-side
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // Print the main string

    for(int i = 0; i < Mid/2; i++){
        printf("%c",digit); // Print a digit in right-side
    }
    printf("\n%s\n",line); // Print the final line with \n
}

void Animation(){
    for (int i = 0; i < 16; i++){
        if (i % 5 == 0){
            printf("\b\b\b\b\b");
        } else {
            printf(" ");
        }
        Sleep(100);
    }
}

// Structs!
struct Locais{
    char *Cidades[3], *Enderecos[3];
    int Salas[3], Empregados[3];
    float Gastos[3], Renda[3], Lucros[3];
    int QntLojas;
};

// Struct para salvar informações referentes ao usuario
struct User{
    char *Pizzas[100], *Tamanhos[100];
    char usuario[100], senha[100];
    char endereco[2][100];
    int *quantidade[100];
    int Contador; // Utilizado para interagir com Pizzas,Tamanhos e quantidade;
    bool logado; // Utilizado para validação de login (Atualmente só funciona com Admin)
    float total;
};

// Usei para armazenar informações referentes a cada usuario (Um jeito de salvar os pedidos)
struct Login{
    struct User sessoes[100];
    int numSessoes;
};

// Struct Pizzas! (2.0) (Também veio da versão 2 e está sendo reutilizado agora!)
struct Pizzas{
    int QntSalgadas, QntDoces, QntGeral; // Contador de pizzas
    char *salgadas[100][100];
    char *doces[100][100];
    char *geral[100][100];
    char *tamanhos[3];
    float precos[3];
};

// Struct Menus (Vindo da versão 2 agora reutilizado na versão 5)
struct Menu{
    char *Items[100];
    char title[100];
    int Tamanho;
};

void viewPizzas(struct Pizzas pizzas, char *line, int digit){
    system("cls");
    strcenter(line,"Sabores de pizzas disponíveis no momento!",digit,false);
    for(int i = 0; i < pizzas.QntSalgadas; i++){
        char format[100];
        sprintf(format,"%c. %s",i+65,pizzas.salgadas[i][0]);
        int lenght = strlen(format);

        printf("%s",format);
        for(int l = 0; l <= 34 - lenght; l++){
            printf("%1c",digit);
        }
        if(i < pizzas.QntDoces){
            printf("%c. %s",(i+pizzas.QntSalgadas-1)+66,pizzas.doces[i][0]);
        }
        printf("\n");
    }
    printf("%s\n",line);
}

void viewDescontos(char *decorador, char *Dias[7], char *Promos[7]){
    system("cls");
    strcenter(decorador,"Descontos",32,false);
    for(int i = 0; i < 7; i++){
        printf("- %s %s\n", Dias[i], Promos[i]);
    };
    printf("%s\n",decorador);
}

void viewContatos(char *decorador){
    system("cls");
    strcenter(decorador,"Contatos",32,false);
    printf("Email: CodePizza@gmail.com\n");
    printf("Discord: CodePizza#1140\n");
    printf("Telefone: 61 3879-8634\n");
    printf("Instagram: @CodePizza\n");
    printf("UberEats: CodePizza\n");
    printf("Ifood: CodePizza\n");
    printf("%s\n",decorador);
    system("PAUSE");
}

void viewSobre(char *decorador){
    system("cls");
    strcenter(decorador,"Sobre",32,false);
    printf("Frase fornecida pelo cliente para colocar no site\n");
    system("PAUSE");
}

void viewTamanhosPizza(char *decorador, float preco[3], char *nomes[3], char *sabor){
    system("cls");
    strcenter(decorador,sabor,32,false);
    for(int i = 0; i < 3; i++){
        printf("%i. %s: R$ %.2f\n",i+1,nomes[i],preco[i]);
    }
    printf("%s\n",decorador);
}

void viewLojas(struct Locais Lojas, char *line, int digit){
    system("cls");
    strcenter(line,"Informações sobre cada loja!",digit,false);
    for(int i = 0; i < Lojas.QntLojas; i++){ // 2x == Cidade + Endereço
        printf("%s\n",Lojas.Cidades[i]);
        printf("%s\n",Lojas.Enderecos[i]);
        printf("Receita: R$ %.2f\n",Lojas.Renda[i]);
        printf("Lucro: R$ %.2f\n",Lojas.Lucros[i]);
        printf("Gasto: R$ %.2f\n",Lojas.Gastos[i]);
        printf("Empregados: %i\n",Lojas.Empregados[i]);
        if(Lojas.Lucros[i] > Lojas.Gastos[i]){
            printf(GRN"Lucro!"RST" (R$ %.2f)",Lojas.Lucros[i] - Lojas.Gastos[i]);
        }
        else if(Lojas.Lucros[i] == Lojas.Gastos[i]){
            printf("Neutro!");
        }
        else{
           printf(RED"Prejuízo!"RST" (R$ %.2f)",Lojas.Lucros[i] - Lojas.Gastos[i]);    
        }
        printf("\n%s\n",line);
    }
    system("PAUSE");
}

void viewMenu(struct Menu menu, char *line, int digit){
    system("cls");
    strcenter(line,menu.title,digit,false);
    for(int i = 0; i < menu.Tamanho; i++){
        printf("%i. %s\n",i+1,menu.Items[i]);
    }
    printf("%s\n",line);
    printf("> ");
}

int main(){
    // Configurações!
    system("chcp 65001");
    setlocale(LC_ALL, "Portuguese-brazillian");
    srand(time(NULL));

    // Declarações
    int option = 100; // Navegação
    // decoradores!
    char *lineM = "===========================================";
    char *line = "===============================================";
    char *line2 = "====================================================================";
    char *nome = "Pizzaria: Code Pizza"; // nome da loja

    // Admin
    char AdmUser[100] = "adm@gmail.com";
    char admSenha[100] = "adm123";
        
    struct Locais lojas;
    lojas.QntLojas = 3;

    lojas.Lucros[0] = rand() % 5000 + 10000;
    lojas.Gastos[0] = rand() % 5000 + 7500;
    lojas.Renda[0] = lojas.Renda[0] + lojas.Gastos[0];
    lojas.Cidades[0] = "Águas Claras Norte";
    lojas.Enderecos[0] = "Rua 10 Lote 3";
    lojas.Salas[0] = rand() % 3 + 2;
    lojas.Empregados[0] = rand() % 10 + 2;

    lojas.Lucros[1] = rand() % 5000 + 10000;
    lojas.Gastos[1] = rand() % 5000 + 7500;
    lojas.Renda[1] = lojas.Renda[1] + lojas.Gastos[1];
    lojas.Cidades[1] = "Taguatinga Norte";
    lojas.Enderecos[1] = "CND 14 Lote 10";
    lojas.Salas[1] = rand() % 3 + 2;
    lojas.Empregados[1] = rand() % 10 + 2;

    lojas.Lucros[2] = rand() % 5000 + 10000;
    lojas.Gastos[2] = rand() % 5000 + 7500;
    lojas.Renda[2] = lojas.Renda[2] + lojas.Gastos[2];
    lojas.Cidades[2] = "Vicente Pires";
    lojas.Enderecos[2] = "Rua 5 Lote 28";
    lojas.Salas[2] = rand() % 3 + 2;
    lojas.Empregados[2] = rand() % 10 + 2;

    // Pizzas
    struct Pizzas pizzas;
    pizzas.QntSalgadas = 0;
    pizzas.QntDoces = 0;
    pizzas.QntGeral = 0;

    // Salgadas
    pizzas.salgadas[0][0] = "Pizza de Calabresa com bacon";
    pizzas.salgadas[0][1] = "> Calabresa\n> Bacon\n> Muçarela\n> Orégano";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[1][0] = "Pizza de Portuguesa especial";
    pizzas.salgadas[1][1] = "> Muçarela\n> Presunto\n> Palmito\n> Ervilha\n> Lombo canadense\n> Provolone\n> Ovo\n> Bacon";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[2][0] = "Pizza de Frango com catupiry";
    pizzas.salgadas[2][1] = "> Peito de frango\n> Orégano\n> Queijo catupiry";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[3][0] = "Pizza de Marguerita";
    pizzas.salgadas[3][1] = "> Muçarela\n> Manjericão\n> Orégano\n> Tomate\n> Azeitona";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[4][0] = "Pizza de 4 Queijos";
    pizzas.salgadas[4][1] = "> Parmesão ralado\n> Muçarela ralada\n> Provolone\n> Gorgonzola";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[5][0] = "Pizza de Pepperoni";
    pizzas.salgadas[5][1] = "> Salame italiano\n> Pimentão\n> Muçarela\n> Pimenta Calabresa\n> Molho especial";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[6][0] = "Pizza de Mussarela";
    pizzas.salgadas[6][1] = "> Muçarela\n> Orégano";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    pizzas.salgadas[7][0] = "Pizza Romana";
    pizzas.salgadas[7][1] = "> Muçarela\n> Azeitona\n> Anchovas\n> Azeite\n> Tomate Seco";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.salgadas[pizzas.QntGeral][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.salgadas[pizzas.QntGeral][1];
    pizzas.QntSalgadas += 1;
    pizzas.QntGeral += 1;

    // Doces
    pizzas.doces[0][0] = "Pizza de Morango com chocolate";
    pizzas.doces[0][1] = "> Pêssego em calda fatiado\n> Abacaxi em calda fatiado\n> Figo em calda fatiado\n> Muçarela\n> Lombinho";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[1][0] = "Pizza de Banana com chocolate";
    pizzas.doces[1][1] = "> Leite condensado\n> Muçarela\n> Chocolate\n> Banana";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[2][0] = "Pizza de Banana com canela";
    pizzas.doces[2][1] = "> Açucar com canela\n> Muçarela\n> Banana";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[3][0] = "Pizza de Frutas vermelhas";
    pizzas.doces[3][1] = "> Framboesa fatiada\n> Morgango fatiado\n> Cereja fatiada\n> Chocolate";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[4][0] = "Pizza de Romeu e Julieta";
    pizzas.doces[4][1] = "> Muçarela\n> Goiabada\n> Canela";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[5][0] = "Pizza de California";
    pizzas.doces[5][1] = "> Pêssego em calda fatiado\n> Abacaxi em calda fatiado\n> Figo em calda fatiado\n> Muçarela\n> Lombinho";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;
    
    pizzas.doces[6][0] = "Pizza de Sorvete";
    pizzas.doces[6][1] = "> Sorvete de creme\n> Cereja em calda\n> Chocolate branco fatiado\n> Granulados";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    pizzas.doces[7][0] = "Pizza de Chocolate";
    pizzas.doces[7][1] = "> Calda de chocolate\n> Castanhas torradas moídas\n> Cereja em calda\n> Granulado";
    pizzas.geral[pizzas.QntGeral][0] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][0];
    pizzas.geral[pizzas.QntGeral][1] = pizzas.doces[pizzas.QntGeral%pizzas.QntSalgadas][1];
    pizzas.QntDoces += 1;
    pizzas.QntGeral += 1;

    // Preços
    pizzas.precos[0] = 10.00;
    pizzas.precos[1] = 15.00;
    pizzas.precos[2] = 25.00;

    // Tamanhos
    pizzas.tamanhos[0] = "Pizza P";
    pizzas.tamanhos[1] = "Pizza M";
    pizzas.tamanhos[2] = "Pizza G";

    // Init struct logins
    struct Login logins;
    logins.numSessoes = 0;

    // Init struct Menus = {MainMenu, AdmMenu, UserMenu}
    struct Menu MainMenu;
    strcpy(MainMenu.title,nome);
    MainMenu.Items[0] = "Cardapio de pizzas";
    MainMenu.Items[1] = "Logar no sistema";
    MainMenu.Items[2] = "Contato";
    MainMenu.Items[3] = "Sobre";
    MainMenu.Items[4] = "Sair";
    MainMenu.Tamanho = 5;

    struct Menu UserMenu;
    UserMenu.Items[0] = "Fazer um pedido";
    UserMenu.Items[1] = "Ver resumo do pedido";
    UserMenu.Items[2] = "Locais de retirada";
    UserMenu.Items[3] = "Cadastrar endereço";
    UserMenu.Items[4] = "Sair";
    UserMenu.Tamanho = 5;

    struct Menu AdmMenu;
    strcpy(AdmMenu.title,"Logado como Administrador");
    AdmMenu.Items[0] = "Consultar Lojas";
    AdmMenu.Items[1] = "Receita do mês";
    AdmMenu.Items[2] = "Pedidos do dia";
    AdmMenu.Items[3] = "Sair";
    AdmMenu.Tamanho = 4;

    // Code
    do{
        // Init struct User ("Usuario atual >>> Muda toda vez q o loop recomeça!")
        struct User user_atual;
        user_atual.Contador = 0; // Contador de pizzas pedidas até o momento
        user_atual.total = 0; // Total do pedido
        user_atual.logado = false; // Bool de controle

        viewMenu(MainMenu,line,32); // Função de menu
        option = getch(); // Um tipo de input especifico sem enter que retorna um valor em número digitado pelo usuário!
        if(option >= 48 && option <= 57){ // 0 a 9 são respectivamente as teclas de número 48 a 57 do teclado
            option = option%48;
        }

        if (option == 1){ // Comando condicional que se relaciona com o valor option
            // Loop para mostar informações das Pizzas
            int CodePizza; // Define o valor de option para 100 por padrão para evitar bugs relacionados ao scanf
            do{
                viewPizzas(pizzas,line2,32); // Ver Cadapio de Pizzas
                printf("Escolha uma pizza! (Pressione ESC para voltar)");
                printf("\n> ");
                CodePizza = getch();
                // Apenas pra deixar o código mais bonito, essa parte escreve no terminal a letra que foi digitada pelo usuário
                if(CodePizza >= 65 && CodePizza <= 90){ // Caixa alta (A ... Z)
                    printf("%c\n",CodePizza);
                    CodePizza %= 65;
                }
                else if(CodePizza >= 97 && CodePizza <= 122){ // Letra minúscula (a ... z)
                    printf("%c\n",toupper(CodePizza));
                    CodePizza %= 97;
                }

                if (CodePizza <= pizzas.QntGeral - 1 && CodePizza >= 0){
                    system("cls");
                    strcenter(line,pizzas.geral[(CodePizza)][0],32,false); // pizzas[(option-1)] = Consulta o valor de index (option-1) na lista pizzas
                    printf("%s\n%s\n",pizzas.geral[(CodePizza)][1],line);
                    system("PAUSE");
                }
            }while(CodePizza != 27);
        }

        else if (option == 2){
            do{
                system("cls");
                strcenter(line,"Login || Registro",32,false);
                printf("> Usuário: ");
                gets(user_atual.usuario); // user_atual.usuario = variavel usuario de user_atual
                fflush(stdin);
                int cpmUser = strcmp(user_atual.usuario, AdmUser); // strcmp compara as strings e retorna 0 se forem iguais (-1,1) se forem diferentes
                int cmpQuit = strcmp(user_atual.usuario, "quit");
                if(cmpQuit == 0){
                    break;
                }
                printf("> Senha: ");
                scanf("%s",&user_atual.senha);
                fflush(stdin);
                int cmpSenha = strcmp(user_atual.senha, admSenha);
                Animation();
                // ADM
                if(cpmUser == 0 && cmpSenha == 0){
                    strcenter(line,GRN"Logado com Sucesso!"RST,32,true);
                    Sleep(600);
                    int option = 0;
                    do{
                        viewMenu(AdmMenu,line,32);
                        option = getch();
                        if(option >= 48 && option <= 57){
                            option = option%48;
                        }
                        system("cls");
                        switch (option) {
                            case 1:
                                strcenter(line,"Informação das lojas",32,false);
                                for (int i = 0; i < 3; i++){
                                    printf("> %s\n",lojas.Cidades[i]);
                                    printf("Endereco: %s\n",lojas.Enderecos[i]);
                                    printf("Salas da loja: %i\n",lojas.Salas[i]);
                                    printf("Empregados: %i\n",lojas.Empregados[i]);
                                    printf("%s\n",line);
                                }
                                system("PAUSE");
                                break;

                            case 2:
                                viewLojas(lojas,line2,32);
                                break;

                            case 3:
                                strcenter(line,"Pedidos do dia!",32,false);
                                if(logins.numSessoes > 0){
                                    for(int i = 0; i < logins.numSessoes; i++){
                                        if(logins.sessoes[i].total > 0){
                                            printf("Cliente: %s\n",logins.sessoes[i].usuario);
                                            for (int C = 0; C < logins.sessoes[i].Contador; C++){
                                                printf("> %s (%i %s)\n",logins.sessoes[i].Pizzas[C],logins.sessoes[i].quantidade[C],logins.sessoes[i].Tamanhos[C]);
                                            }
                                            printf("Total: R$ %.2f\n",logins.sessoes[i].total);
                                            if(logins.sessoes[i].endereco[1] > 0 && logins.sessoes[i].endereco[0] > 0){
                                                printf("Endereço: %s\n Cidade: %s\n",logins.sessoes[i].endereco[1],logins.sessoes[i].endereco[0]);
                                            }
                                            printf("%s\n",line);
                                        } else {
                                            printf("Cliente: %s\n",logins.sessoes[i].usuario);
                                            printf("Sem pedidos!\n%s\n",line);
                                        }
                                    }
                                } else {
                                    printf("Nenhum pedido ainda!\n%s\n",line);
                                }
                                system("PAUSE");
                                break;

                            case 4:
                                break;
                                
                            default:
                                break;
                        }
                        system("cls");
                    } while(option != 4);
                    user_atual.logado = true;
                }
                
                else if(cpmUser == 0 && cmpSenha != 0){
                    strcenter(line,RED"- Senha Incorreta! -"RST,32,true);
                    Sleep(600);
                }
                // USER
                else{
                    sprintf(UserMenu.title,"- Bem Vindo %s -",user_atual.usuario);
                    free(UserMenu.title);
                    strcenter(line,GRN"Logado com Sucesso!"RST,32,true);
                    Sleep(600);
                    do{
                        int option = 0;
                        viewMenu(UserMenu,line,32);
                        option = getch();
                        if(option >= 48 && option <= 57){
                            option = option%48;
                        }
                        system("cls");
                        if (option != 5 && option != 27){
                            
                            if (option == 1){
                                int CodePizza;
                                do{
                                    viewPizzas(pizzas,line2,32);
                                    printf("> ");
                                    CodePizza = getch(); // 65 a 90 || 97 a 122 (Alfabeto para getch())
                                    if(CodePizza >= 65 && CodePizza <= 90){ // Caixa alta
                                        printf("%c\n",CodePizza);
                                        CodePizza %= 65;
                                    }
                                    else if(CodePizza >= 97 && CodePizza <= 122){ // Letra minúscula
                                        printf("%c\n",toupper(CodePizza));
                                        CodePizza %= 97;
                                    }
                                    else if(CodePizza == 27){ // 27 == Esc
                                        printf("\b\b");
                                        break;
                                    }
                                    else{
                                        CodePizza = 100;
                                    }

                                    system("cls");
                                    if(CodePizza <= pizzas.QntGeral - 1){
                                        char titlePizza[100];
                                        sprintf(titlePizza,"Sabor: %s",pizzas.geral[CodePizza][0]);
                                        free(titlePizza);
                                        strcenter(line2,titlePizza,32,false);
                                        printf("%s\n%s\n",pizzas.geral[CodePizza][1],line2);
                                        system("PAUSE");
                                        system("cls");

                                        int select = 0;
                                        do{
                                            viewTamanhosPizza(line2,pizzas.precos,pizzas.tamanhos,pizzas.geral[(CodePizza)][0]);
                                            printf("> ");
                                            select = getch();
                                            if(select >= 48 && select <= 57){
                                                select = select%48;
                                            }
                                            if(select > 3){
                                                system("cls");
                                            }
                                        } while(select > 3 || select == 0);

                                        int quantidade = 0;
                                        do{
                                            viewTamanhosPizza(line2,pizzas.precos,pizzas.tamanhos,pizzas.geral[(CodePizza)][0]);
                                            printf("Quantas pizzas %s (%s) serão pedidas?\n> ",pizzas.geral[(CodePizza)][0],pizzas.tamanhos[select-1]);
                                            scanf("%i",&quantidade);
                                            fflush(stdin);
                                            printf("%s\n",line2);
                                            if (quantidade <= 0){
                                                system("cls");
                                            }
                                        } while (quantidade <= 0);

                                        user_atual.total += pizzas.precos[select-1]*quantidade;
                                        user_atual.Pizzas[user_atual.Contador] = pizzas.geral[(CodePizza)][0];
                                        user_atual.Tamanhos[user_atual.Contador] = pizzas.tamanhos[select-1];
                                        user_atual.quantidade[user_atual.Contador] = quantidade;
                                        user_atual.Contador += 1;

                                        system("PAUSE");
                                    }
                                }while(CodePizza != 27);
                            }
                            
                            else if(option == 2){
                                strcenter(line,"Revisão do pedido",32,false);
                                for(int i = 0; i < user_atual.Contador; i++){
                                    printf("> %s (%i %s)\n", user_atual.Pizzas[i],user_atual.quantidade[i],user_atual.Tamanhos[i]);
                                }
                                printf("> Total: R$ %.2f\n%s\n",user_atual.total,line);
                                system("PAUSE");
                            }
                            
                            else if(option == 3){
                                strcenter(line,"- Localização das pizzarias -",32,false);
                                for(int i = 0; i < 3; i++){
                                    printf("> %s: %s\n",lojas.Cidades[i],lojas.Enderecos[i]);
                                }
                                printf("%s\n",line);
                                system("PAUSE");
                            }

                            else if(option == 4){
                                strcenter(line,"- Cadastro de endereço -",32,false);
                                if(strlen(user_atual.endereco[0]) == 0){
                                    printf("Digite sua cidade\n> ");
                                    gets(user_atual.endereco[0]);
                                }
                                else{
                                    printf("Sua cidade:  %s\n",user_atual.endereco[0]);
                                }
                                if(strlen(user_atual.endereco[1]) == 0){
                                    printf("Digite seu endereço\n> ");
                                    gets(user_atual.endereco[1]);
                                }
                                else{
                                    printf("Seu endereço: %s\n",user_atual.endereco[1]);
                                }
                                if(strlen(user_atual.endereco[0]) == 0 && strlen(user_atual.endereco[1]) == 0){
                                    char SN;
                                    printf("Deseja mudar seu endereço?\n> ");
                                    SN = getch();
                                    if(SN == 'S' || SN == 's'){
                                        printf("S\n");
                                        printf("Digite sua cidade\n> ");
                                        gets(user_atual.endereco[0]);
                                        printf("Digite seu endereço\n> ");
                                        gets(user_atual.endereco[1]);
                                    }
                                }
                                printf("%s\n",line);
                                system("PAUSE");
                            }
                        } 
                        else {
                            printf("%s\n",line);
                            break;
                        }
                    }while(option != UserMenu.Tamanho && option != 27);
                    user_atual.logado = true;
                    logins.sessoes[logins.numSessoes] = user_atual;
                    logins.numSessoes += 1;
                }

            } while(user_atual.logado != true);
        }
        
        else if (option == 3){
            viewContatos(line);
        }

        else if (option == 4){
            viewSobre(line);
        }

        else if (option == 5){
            printf("\n%s\n",line);
            system("PAUSE");
            printf("%s\n",line);
            break;
        }
    } while(option != 5 && option != 27);
}
