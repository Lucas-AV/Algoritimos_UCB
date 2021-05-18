#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

// Identifica se o sistema operacional é Linux ou Windows
#ifdef _WIN32 // Por padrão verifica se o sistema operacional é Windows
#include <Windows.h> // Inclui a função "sleep" e mais algumas outras
#else // Caso o sistema não seja Windows automaticamente o include vira unistd.h (library para linux)
#include <unistd.h>
#endif // Finaliza o if
void verifySpaces(char Arg[100], int lenght){
    for (int i = 0; i < lenght; i++){
        if (isspace(Arg[i])){
            printf("ERROR: Espaços detectados!");
            system("PAUSE");
            break;
        }
    }
}

void viewMainMenu(char *decorador, char *nome){
    system("cls");    
    char *menu[6]; // Já que não existe map no C base estou utilizando um jeito similar a um map<int,string> | Chave, Valor
    menu[0] = "Cardapio";
    menu[1] = "Login";
    menu[2] = "Descontos";
    menu[3] = "Contato";
    menu[4] = "Sobre";
    menu[5] = "Sair";
    printf("%s\n       %s\n%s\n",decorador,nome,decorador);
    for (int i = 0; i < 6; i++){
       printf("%i. %s\n",i+1,menu[i]);
    }
    printf("%s\n",decorador);
    printf("> ");
}

void viewUserMenu(char *decorador, char *nome){
    char *UserMenu[4];
    printf("%s\n- Bem Vindo %s! -\n%s\n",decorador,nome,decorador);
    UserMenu[0] = "Fazer um pedido";
    UserMenu[1] = "Ver Pedido";
    UserMenu[2] = "Locais";
    UserMenu[3] = "Sair";
    for (int i = 0; i < 4; i++){
       printf("%i. %s\n",i+1,UserMenu[i]);
    }
    printf("%s\n> ",decorador);
}

void viewAdminMenu(char *decorador){
    char *AdmMenu[5];
    printf("%s\n  Logado como Administrador\n%s\n",decorador,decorador);
    AdmMenu[0] = "Consultar Lojas";
    AdmMenu[1] = "Receita do mês";
    AdmMenu[2] = "Pedidos do dia";
    AdmMenu[3] = "Sair";
    for (int i = 0; i < 4; i++){
       printf("%i. %s\n",i+1,AdmMenu[i]);
    }
    printf("%s\n> ",decorador);
}

void viewPizzas(char *decorador, char *Lista[12]){
    system("cls");
    printf("%s\n           Cardapio\n%s\n",decorador,decorador);
    printf("        Pizzas Salgadas\n");
    
    for (int i = 0; i < 13; i++){
        if (i % 8 == 0 && i > 0){
            printf("%s\n         Pizzas Doces\n",decorador);
        }
        printf("%i. %s\n",i+1,Lista[i]);
    }
    printf("%s\n",decorador);
}

void viewDescontos(char *decorador, char *Dias[7], char *Promos[7]){
    system("cls");
    printf("%s\n          Descontos\n%s\n",decorador,decorador);
    for(int i = 0; i < 7; i++){
        printf("- %s %s\n", Dias[i], Promos[i]);
    };
    printf("%s\n",decorador);
}

void viewContatos(char *decorador){
    system("cls");
    printf("%s\n          Contatos\n%s\n",decorador,decorador);
    printf("Email: CodePizza@gmail.com\n");
    printf("Telefone: 61 3879-8634\n");
    printf("Instagram: @CodePizza\n");
    printf("%s\n",decorador);
}

void viewSobre(char *decorador){
    system("cls");
    printf("%s\n            Sobre\n%s\n",decorador,decorador);
}

void viewTamanhosPizza(char *decorador, float preco[3], char *nomes[3], char *sabor){
    system("cls");
    printf("%s\n%s\n%s\n",decorador,sabor,decorador);
    for(int i = 0; i < 3; i++){
        printf("%i. %s: R$ %.2f\n",i+1,nomes[i],preco[i]);
    }
    printf("%s\n",decorador);
}

void Animation(){
    // Animação de carregamento! (200 ms)
    for (int i = 1; i < 17; i++){
        if (i % 4 == 0){
            printf("\b\b\b\b");
        } else {
            printf(" ");
        }
        Sleep(200);
    }
}

void LoginAnimation(char *decorador){
    Animation();
    printf("%s\n",decorador);
    printf("     Logado com sucesso!\n");
    printf("%s\n",decorador);
    Sleep(250);
    system("PAUSE");
    system("cls");
}

int main(){
    system("chcp 65001");
    setlocale(LC_ALL, "Portuguese");
    
    // Declarações
    int option = 100; // Navegação
    char linha[30] = "============================="; // decorador!
    char *nome = "Pizzaria Online"; // nome da loja

    // Admin
    char AdmUser[100] = "adm@gmail.com";
    char admSenha[100] = "adm123";
    
    // Struct criado para armazenar a localização das lojas (Pode ser substituido por chars com ponteiros porém desse modo é muito melhor de fazer)
    struct Locais{
        char *Cidades[3], *Enderecos[3];
        int Salas[3], Empregados[3];
        float Gastos[3], Renda[3], Lucros[3];
    };
    struct Locais lojas;
    lojas.Renda[0] = 21000;
    lojas.Gastos[0] = 10500;
    lojas.Lucros[0] = lojas.Renda[0] - lojas.Gastos[0];
    lojas.Cidades[0] = "Águas Claras Norte";
    lojas.Enderecos[0] = "Rua 10 Lote 3";
    lojas.Salas[0] = 5;
    lojas.Empregados[0] = 16;

    lojas.Renda[1] = 32000;
    lojas.Gastos[1] = 12000;
    lojas.Lucros[1] = lojas.Renda[1] - lojas.Gastos[1];
    lojas.Cidades[1] = "Taguatinga Norte";
    lojas.Enderecos[1] = "CND 14 Lote 10";
    lojas.Salas[1] = 4;
    lojas.Empregados[1] = 12;

    lojas.Renda[2] = 21000;
    lojas.Gastos[2] = 10000;
    lojas.Lucros[2] = lojas.Renda[2] - lojas.Gastos[2];
    lojas.Cidades[2] = "Vicente Pires";
    lojas.Enderecos[2] = "Rua 5 Lote 28";
    lojas.Salas[2] = 5;
    lojas.Empregados[2] = 14;

    // Descontos
    char *dias[7] = {
        "Domingo",
        "Segunda-feira",
        "Terça-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sábado-feira",
    };
    char *promos[7] = {
        "Desconto de 15%% em pedidos com 3 ou mais pizzas",
        "Pizzas Pequenas com 10%% de desconto",
        "Pizzas Médias com 10%% de desconto",
        "Pizzas Grandes com 10%% de desconto",
        "Pizzas Salgadas com 10%% de desconto",
        "Pizzas Doces com 10%% de desconto",
        "Desconto de 20%% em pedidos com 5 ou mais pizzas",
    };

    // Pizzas
    char *pizzas[13], *infoPizzas[13];
    char *tamanhos[3] = {"Pizza P","Pizza M","Pizza G"};
    float precos[3] = {10.00, 15.00, 20.00};

    // sal
    pizzas[0] = "Pizza de Calabresa com bacon";
    infoPizzas[0] = "> Calabresa\n> Bacon\n> Muçarela\n> Orégano";
    
    pizzas[1] = "Pizza de Portuguesa especial";
    infoPizzas[1] = "> Muçarela\n> Presunto\n> Palmito\n> Ervilha\n> Lombo canadense\n> Provolone\n> Ovo\n> Bacon";
    
    pizzas[2] = "Pizza de Frango com catupiry";
    infoPizzas[2] = "> Peito de frango\n> Orégano\n> Queijo catupiry";
    
    pizzas[3] = "Pizza de Marguerita";
    infoPizzas[3] = "> Muçarela\n> Manjericão\n> Orégano\n> Tomate\n> Azeitona";
    
    pizzas[4] = "Pizza de Muçarela";
    infoPizzas[4] = "> Muçarela\n> Orégano";
    
    pizzas[5] = "Pizza de Pepperoni";
    infoPizzas[5] = "> Salame italiano\n> Pimentão\n> Muçarela\n> Pimenta Calabresa\n> Molho especial";

    pizzas[6] = "Pizza de 4 Queijos";
    infoPizzas[6] = "> Parmesão ralado\n> Muçarela ralada\n> Provolone\n> Gorgonzola";

    pizzas[7] = "Pizza Romana";
    infoPizzas[7] = "> Muçarela\n> Azeitona\n> Anchovas\n> Azeite\n> Tomate Seco";

    // Doce Napolitana
    pizzas[8] = "Pizza de Banana com chocolate";
    infoPizzas[8] = "> Leite condensado\n> Muçarela\n> Chocolate\n> Banana";
    
    pizzas[9] = "Pizza de Banana com canela";
    infoPizzas[9] = "> Açucar com canela\n> Muçarela\n> Banana";
    
    pizzas[10] = "Pizza de Romeu e Julieta";
    infoPizzas[10] = "> Muçarela\n> Goiabada\n> Canela";
    
    pizzas[11] = "Pizza de Frutas vermelhas";
    infoPizzas[11] = "> Framboesa fatiada\n> Morgango fatiado\n> Cereja fatiada\n> Chocolate";

    pizzas[12] = "Pizza de California";
    infoPizzas[12] = "> Pêssego em calda fatiado\n> Abacaxi em calda fatiado\n> Figo em calda fatiado\n> Muçarela\n> Lombinho";
    
    // Struct para salvar informações referentes ao usuario
    struct User{
        char *Pizzas[100], *Tamanhos[100];
        char usuario[100], senha[100];
        int *quantidade[100];
        int Contador; // Utilizado para interagir com Pizzas,Tamanhos e quantidade;
        bool logado;
        float total;
    };

    // Usei para armazenar referentes a cada usuario (Um jeito de salvar os pedidos)
    struct Login{
        struct User sessoes[100];
        int numSessoes;
    };
    struct Login logins;
    logins.numSessoes = 0;
    do{
        system("cls");
        struct User user_atual;
        user_atual.Contador = 0; // Contador de pizzas pedidas até o momento
        user_atual.total = 0; // Total do pedido
        user_atual.logado = false; // Bool de controle
        viewMainMenu(linha,nome); // Função de menu
        scanf("%i",&option); // Scanf de informação
        fflush(stdin); // Limpa a mémoria temporária (Evita alguns bugs relacionados ao scanf)

        if (option == 1){ // Comando condicional que se relaciona com o valor option
            // Loop para mostar informações das Pizzas
            option = 100; // Define o valor de option para 100 por padrão para evitar bugs relacionados ao scanf
            do{
                viewPizzas(linha,pizzas); // Função para evitar ficar escrevendo
                printf("Escolha uma pizza! (Para voltar digite: 0)");
                printf("\n> ");
                scanf("%i",&option);
                fflush(stdin); // Evita alguns erros bem desagradáveis relacionados ao stdin e qualquer input feito pelo usuário.
                
                if (option <= 13 && option > 0){
                    system("cls");
                    printf("%s\n%s\n%s\n",linha,pizzas[(option-1)],linha); // pizzas[(option-1)] = Consulta o valor de index (option-1) na lista pizzas
                    printf("%s\n%s\n",infoPizzas[(option-1)],linha);
                    system("PAUSE");
                }                
                
            }while(option != 0);
        }

        else if (option == 2){
            do{
                system("cls");
                printf("%s\n       Login || Registro\n%s\n",linha,linha);

                printf("> Email: ");
                scanf("%s",&user_atual.usuario); // user_atual.usuario = variavel usuario de user_atual
                fflush(stdin);
                
                printf("> Senha: ");
                scanf("%s",&user_atual.senha);
                fflush(stdin);
                
                // Cria váriaveis para comparar usuario e senha com o usuario e senha do administrador
                int cpmUser = strcmp(user_atual.usuario, AdmUser); // strcmp compara as strings e retorna 0 se forem iguais (-1,1) se forem diferentes
                int cmpSenha = strcmp(user_atual.senha, admSenha);
                
                // Menu de login para usuario
                if(cpmUser == 0 && cmpSenha == 0){
                    LoginAnimation(linha);
                    int option = 0;
                    do{
                        viewAdminMenu(linha);
                        scanf("%i",&option);
                        fflush(stdin);
                        system("cls");
                        switch (option) {
                            case 1:
                                printf("%s\n    Informação das lojas\n%s\n",linha,linha);
                                for (int i = 0; i < 3; i++){
                                    printf("> %s\n",lojas.Cidades[i]);
                                    printf("Endereco: %s\n",lojas.Enderecos[i]);
                                    printf("Salas da loja: %i\n",lojas.Salas[i]);
                                    printf("Empregados: %i\n",lojas.Empregados[i]);
                                    printf("%s\n",linha);
                                }
                                system("PAUSE");
                                break;

                            case 2:
                                printf("%s\n       Receita do mês\n%s\n",linha,linha);
                                for (int i = 0; i < 3; i++){
                                    float LucroPorcentagem = (lojas.Lucros[i]/lojas.Renda[i])*100, GastoPorcentagem = 100.00-LucroPorcentagem;
                                    printf("> %s\n",lojas.Cidades[i]);
                                    printf("Renda Mensal: R$ %.2f\n",lojas.Renda[i]);
                                    printf("Gasto: R$ %.2f (%.0f%%)\n",lojas.Gastos[i],GastoPorcentagem);
                                    printf("Lucro: R$ %.2f (%.0f%%)\n",lojas.Lucros[i],LucroPorcentagem); // Duas %% permitem que eu utilize o caractere % normalmente
                                    printf("%s\n",linha);
                                }
                                system("PAUSE");
                                break;

                            case 3:
                                printf("%s\n       Pedidos do dia\n%s\n",linha,linha);
                                if(logins.numSessoes > 0){
                                    for(int i = 0; i < logins.numSessoes; i++){
                                        if(logins.sessoes[i].total > 0){
                                            printf("Cliente: %s\n",logins.sessoes[i].usuario);
                                            for (int C = 0; C < logins.sessoes[i].Contador; C++){
                                                printf("> %s (%i %s)\n",logins.sessoes[i].Pizzas[C],logins.sessoes[i].quantidade[C],logins.sessoes[i].Tamanhos[C]);
                                            }
                                            printf("Total: R$ %.2f\n%s\n",logins.sessoes[i].total,linha);
                                        } else {
                                            printf("Cliente: %s\n",logins.sessoes[i].usuario);
                                            printf("Sem pedidos!\n%s\n",linha);
                                        }
                                    }
                                } else {
                                    printf("Nenhum pedido ainda!\n%s\n",linha);
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
                    Animation();
                    printf("%s\nSenha incorreta para entrar como %s!\n%s\n",linha,AdmUser,linha);
                    system("PAUSE");
                }

                else{
                    LoginAnimation(linha);
                    do{
                        int option = 0;
                        system("cls");
                        viewUserMenu(linha,user_atual.usuario);
                        scanf("%i",&option);
                        fflush(stdin);
                        system("cls");
                        if (option != 4){
                            
                            if (option == 1){
                                int option = 100;
                                do{
                                    viewPizzas(linha,pizzas);
                                    printf("- Digite 0 ou alguma letra para finalizar o pedido!\n> ");
                                    scanf("%i",&option);
                                    fflush(stdin);
                                    // Verifica se o valor de input de option (Utilizado para navegação entre menus está entre os valores 1 e 13)
                                    if(option <= 13 && option > 0){
                                        system("cls");
                                        printf("%s\n%s\n%s\n",linha,pizzas[(option-1)],linha);
                                        printf("%s\n%s\n",infoPizzas[(option-1)],linha);
                                        system("PAUSE");
                                        
                                        int select = 0;
                                        do{
                                            viewTamanhosPizza(linha,precos,tamanhos,pizzas[(option-1)]);
                                            printf("> ");
                                            scanf("%i",&select);
                                            fflush(stdin);
                                            if(select > 3){
                                                system("cls");
                                            }
                                        } while(select > 3 || select == 0);

                                        int quantidade = 0;
                                        do{
                                            viewTamanhosPizza(linha,precos,tamanhos,pizzas[(option-1)]);
                                            printf("Quantas pizzas %s (%s) serão pedidas?\n> ",pizzas[(option-1)],tamanhos[select-1]);
                                            scanf("%i",&quantidade);
                                            fflush(stdin);
                                            printf("%s\n",linha);
                                            if (quantidade <= 0){
                                                system("cls");
                                            }
                                        } while (quantidade <= 0);

                                        user_atual.total += precos[select-1]*quantidade;
                                        user_atual.Pizzas[user_atual.Contador] = pizzas[(option-1)];
                                        user_atual.Tamanhos[user_atual.Contador] = tamanhos[select-1];
                                        user_atual.quantidade[user_atual.Contador] = quantidade;
                                        user_atual.Contador += 1;

                                        system("PAUSE");
                                    } 
                                    
                                }while(option != 0);
                            }
                            
                            else if(option == 2){
                                
                                printf("%s\nRevisão do pedido\n%s\n",linha,linha);
                                for(int i = 0; i < user_atual.Contador; i++){
                                    printf("> %s (%i %s)\n", user_atual.Pizzas[i],user_atual.quantidade[i],user_atual.Tamanhos[i]);
                                }
                                printf("> Total: R$ %.2f\n%s\n",user_atual.total,linha);
                                system("PAUSE");
                            }
                            
                            else if(option == 3){
                                
                                printf("%s\n- Localização das pizzarias -\n%s\n",linha,linha);
                                for(int i = 0; i < 3; i++){
                                    printf("> %s: %s\n",lojas.Cidades[i],lojas.Enderecos[i]);
                                }
                                printf("%s\n",linha);
                                system("PAUSE");
                            } 

                        } 
                        else {
                            printf("%s\n",linha);
                            break;
                        }
                    }while(option != 4);
                    user_atual.logado = true;
                    logins.sessoes[logins.numSessoes] = user_atual;
                    logins.numSessoes += 1;
                }

            } while(user_atual.logado != true);
        }
        
        else if (option == 3){
            //viewDescontos(linha);
            system("PAUSE");
        }

        else if (option == 4){
            viewContatos(linha);
            system("PAUSE");
        }

        else if (option == 5){
            viewSobre(linha);
            system("PAUSE");
        }

        else if (option == 6){
            printf("%s\n",linha);
            system("PAUSE");
            printf("%s\n",linha);
            break;
        }

    } while(option != 6);
    system("cls"); // usei no visual studio code
}
