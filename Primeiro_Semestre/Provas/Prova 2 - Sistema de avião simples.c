// Lucas Alves Vilela (Github: LucasV75)
#include <stdbool.h> // Adiciona o tipo de váriavel bool ao C
#include <stdlib.h> // Padrão do C
#include <locale.h> // Me permite definir o idioma do terminal 
#include <stdio.h> // Responsável pelos inputs e outputs
#include <conio.h> // Responsável pelo getch(); >>> Identificação das teclas digitadas em forma de char ou int! (Similar a um input)
#include <ctype.h> // Tipos de variáveis (Apesar de não usar as vezes eu sempre importo por precaução)
#include <Windows.h> // Adiciona algumas funções específicas como Sleep(ms) por exemplo!
// Lista de cores
#define BLK "\e[1;30m"
#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define YEL "\e[1;33m"
#define BLU "\e[1;34m"
#define MAG "\e[1;35m"
#define CYN "\e[1;36m"
#define WHT "\e[1;37m"
#define RST "\e[0m"

// As duas funções a seguir estão escritas em inglês pois utilizei elas em outros projetos pessoais que pretendo postar no github futuramente!
// Além disso elas são só prints! (Ia ficar meio ruim de ler 800 linhas de código com metade delas repetidas kkkkk)
void strcenter(char *line, char *string, char digit, bool color){
    int lenString = strlen(string);
    if(color == true){
        lenString -= 10;    // Diminui do valor do len o tamanho da string das cores + o reset (10 a 12)
    }
    int Mid = strlen(line)-lenString; // Calcula quantos espaços serão necessários para centralizar a string
    printf("%s\n",line);
    if(strlen(line) % 2 != 0){
        Mid += 1; // Contador
    }
    for(int i = 0; i < Mid/2; i++){
        printf("%c",digit); // Lado esquerdo
    }
    if(strlen(line) % 2 != 0){
        Mid -= 1;
    }
    printf("%s",string); // String

    for(int i = 0; i < Mid/2; i++){
        printf("%c",digit); // Lado direito
    }
    printf("\n%s\n",line); // Print final
}

void strmenus(char *line, char *title, char *menu[100], int lenght){
    char Alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    strcenter(line,title,32,false);
    if(lenght < 10 && lenght > 0){
        for(int i = 0; i < lenght; i++){
            printf("%i. %s\n",i+1,menu[i]);
        }
    }
    else if(lenght >= 10){
        for(int i = 0; i < lenght; i++){
            printf("%c. %s\n",toupper(Alpha[i]),menu[i]);
        }
    } 
    else{
        printf("ERROR: INVALID LENGHT!");
    }
    printf("%s\n",line);
}

int main(){
    // Configurations
    system("chcp 65001");                       // Permite a configuração de idioma no terminal do VS-CODE (dá um print do comando indicado: "Página de código ativa: 65001")
    setlocale(LC_ALL, "Portuguese-brazillian"); // Configuração para colocar o terminal em português
    srand(time(NULL));                          // Ativa a geração de valores aleatórios
    system("cls");                              // Limpa de tela para iniciar o código com o terminal limpo
    
    // Vars Decorators
    char *title = "SALUMAR LINHAS AEREAS";
    char *line1 = "=======================================";
    char *line2 = "===============================================================";

    // Vars Code
    char RDC[3] = {'R','D','C'}; // Reservado, Disponível, Comprado (RED, GRN, BLU)
    char Alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    // Avião
    char Destino[200][200];     // Destinos de viagem
    int numAssentos[200];       // Quantidade de assentos por destinos de viagem
    int countDestinos = 1;      // Quantidade de destinos fornecidos
    float Passagem[200];        // Preço de passagem por destino
    int numReservas[200];       // Número de reservas por avião
    char Mapa[200][200];        // 200*[200]
    float totPassagem[200];     // Preço total das passagens por cliente (Mesma para questão da passagem!)
    int menorDe5[200];          // Responsável por armazenar a quantidade de crianças com menos de 5 anos por avião
    int IDReservas[100][200];   // ID: 0, IDAvião: 1, QntAssentos: 2, Menores: 3, Assentos: 4+ (O ideal é que tenha alocação dinâmica)
    int countReservas = 1;      // Serve como um tipo de contador para definir o ID das reservas!

    // Primeiro avião de exemplo!
    strcpy(Destino[countDestinos],"Ilha do Caribe!");
    numAssentos[countDestinos] = 90;
    Passagem[countDestinos] = 1200;
    numReservas[countDestinos] = 0;
    menorDe5[countDestinos] = 0;
    totPassagem[countDestinos] = 0;
    for(int i = 0; i < numAssentos[countDestinos]; i++){
        Mapa[countDestinos][i] = 'D';
    }
    countDestinos++;

    // Navegação
    int Key; // Vai ser usado pro primeiro getch();
    int ID;  // ID do avião usado para navegar entre eles;
    char *Menu[5];
    Menu[0] = "Cadastrar um novo voo";
    Menu[1] = "Realizar uma reserva";
    Menu[2] = "Confirmar uma compra";
    Menu[3] = "Cancelar uma reserva";
    Menu[4] = "Sair do sistema";
    do{
        fflush(stdin);  // Serve para evitar overflow de informação
        system("cls");
        strmenus(line2,"SAMULAR LINHAS AEREAS MENU PRINCIPAL",Menu,5);
        printf("> ");
        Key = getch();
        printf("%c\n",Key);
        // Cadastrar um novo voo
        if((char)Key == '1'){
            while (true){
                
                // Destino
                do{
                    system("cls");
                    strcenter(line2,title,32,false);  // O digit pode ser qualquer outro número até 256! (Em PT-BR 32 é um espaço vazio)
                    printf("Digite o destino do avião\n> ");
                    gets(Destino[countDestinos]);  // fgets sem \n no final (Deve ser usado corretamente para não causar overflow de dados!)
                } while (strlen(Destino[countDestinos]) <= 0);
                
                // Número de assentos
                do{
                    printf("Digite o número de assentos do avião\n> ");
                    scanf("%i",&numAssentos[countDestinos]);
                    fflush(stdin);  // Vai aparecer mais algumas vezes no código. (Ele limpa memória e evita alguns erros bem desagradáveis relacionados ao scanf e o tipo de dado recebido)
                    if(numAssentos[countDestinos] < 90 || numAssentos[countDestinos] > 200){
                        system("cls");
                    }
                } while (numAssentos[countDestinos] < 90 || numAssentos[countDestinos] > 200);
                    
                // Preço da passagem
                printf("Digite o preço da passagem do avião\n> ");
                scanf("%f",&Passagem[countDestinos]);
                fflush(stdin);
                printf("%s\n",line2);
                printf("Presione qualquer tecla para continuar ou esc para sair... ");
                // Cria o mapa do avião
                for(int i = 0; i < numAssentos[countDestinos]; i++){
                    Mapa[countDestinos][i] = 'D';
                }
                numReservas[countDestinos] = 0; // Quantidade de reservas
                menorDe5[countDestinos] = 0;    // Menores de 5 anos
                totPassagem[countDestinos] = 0; // Total de passagem já executado
                countDestinos++;// Funciona como um tipo de "ID" para o avião (Posteriormente será utilizado para acessar esse avião afinal pode existir mais de um voo para o mesmo lugar!)
                
                // Verificação de tecla para fechar essa parte ou continuar cadastradando mais voos
                Key = getch();
                if(Key == 27){
                    break;
                } else {
                    system("cls");
                }
            }
        }
        // Realizar uma reserva
        else if((char)Key == '2'){
            do{
                system("cls");
                strcenter(line2,"Lista de Voos",32,false);
                // Lista de aviões
                for(int i = 1; i < countDestinos; i++){
                    printf("Destino:  %s\n",Destino[i]);
                    printf("Assentos: %i assentos (%i disponíveis)\n",numAssentos[i],numAssentos[i]-numReservas[i]);
                    printf("Passagem: R$ %.2f por passagem\n",Passagem[i]);
                    printf("Reservas: %i reservas feitas\n",numReservas[i]);
                    printf("Crianças: %i crianças\n",menorDe5[i]);
                    printf("Comradpo: R$ %.2f\n",totPassagem[i]);
                    printf("Avião ID: %i\n",i);
                    printf("%s\n",line2);
                }
                // Seleção de avião
                printf("Digite o ID do avião (0 para voltar)\n> ");
                scanf("%i",&ID);
                if(ID < 0 || ID >= countDestinos){
                    strcenter(line2,RED"ERROR"RST": ID INVÁLIDO",32,true);
                    Sleep(600);
                } 

                else if(ID == 0){
                    break;
                }

                else{
                    IDReservas[countReservas][1] = ID;  // Avião
                    IDReservas[countReservas][2] = 0;   // Inicia o contador de lugares
                    IDReservas[countReservas][3] = 0;   // Inicia o contador de crianças menores de 5 anos
                    int selectAssentos;                 // Seleção de assentos
                    do{
                        // Dados do avião selecionado
                        system("cls");
                        char SelectDestino[200];                                // Destino selecionado (Apenas para título!)
                        sprintf(SelectDestino,"Viagem para: %s",Destino[ID]);   // Método para salvar strings formatadas (Dizem que não é tão seguro quanto parece pois pode causar overflow de informação se não tiver memória alocada o suficiente!)
                        strcenter(line2,SelectDestino,32,false);
                        
                        int cFileira = 0;   // Contador de fileiras!
                        // Impressão do mapa do avião
                        for(int i = 0; i < numAssentos[ID]; i++){
                            if(i == 0){
                                printf("%c: [",toupper(Alfabeto[cFileira]));
                                cFileira++;
                            }
                            if(Mapa[ID][i] == 'D'){
                                if(i < 10){
                                    printf(GRN"00%i"RST", ",i);
                                }
                                else if(i >= 10 && i < 100){
                                    printf(GRN"0%i"RST", ",i);
                                } else {
                                    printf(GRN"%i"RST", ",i); 
                                }
                            } 
                            else if(Mapa[ID][i] == 'R'){
                                if(i < 10){
                                    printf(RED"00%i"RST", ",i);
                                }
                                else if(i >= 10 && i < 100){
                                    printf(RED"0%i"RST", ",i);
                                } else {
                                    printf(RED"%i"RST", ",i); 
                                }
                            }
                            else if(Mapa[ID][i] == 'C'){
                                if(i < 10){
                                    printf(BLU"00%i"RST", ",i);
                                }
                                else if(i >= 10 && i < 100){
                                    printf(BLU"0%i"RST", ",i);
                                } else {
                                    printf(BLU"%i"RST", ",i); 
                                }
                            }
                            if((i+1) % 10 == 0 && i != 0){
                                if(i < numAssentos[ID]-1){
                                    printf("\b\b],\n");
                                    printf("%c: [",toupper(Alfabeto[cFileira]));
                                    cFileira++;
                                }
                            }
                            if(i == numAssentos[ID]-1){
                                printf("\b\b]\n");
                            }
                        }
                        
                        printf("%s\n",line2);
                        printf("Escolha um lugar para reservar (Digite -1 para sair)\n> ");
                        scanf("%i",&selectAssentos);
                        fflush(stdin);
                        // Se o assento existir
                        if(selectAssentos >= 0 && selectAssentos <= numAssentos[ID]-1){             // Este -1 ai é referente a quantidade de assentos (200 por exemplo: 0 a 199)
                            if(Mapa[ID][selectAssentos] != 'R' && Mapa[ID][selectAssentos] != 'C'){ // Verifica se o asssento está disponível ('D')
                                strcenter(line2,GRN"Assento reservado com sucesso!"RST,32,true);
                                Mapa[ID][selectAssentos] = 'R';
                                // Validação de menor de idade!
                                bool menorbool;
                                char menorchar;
                                printf("Este assento é para um menor de idade (Menor de 5 anos)? (S/N)\n> ");
                                scanf("%c",&menorchar);
                                printf("%s\n",line2);
                                if(menorchar == 'S' || menorchar == 's'){
                                    menorbool = true;
                                } else {
                                    menorbool = false;
                                }
                                numReservas[ID] += 1;
                                if(menorbool == true){  // Se for menor o preço da passagem será aplicado pela metade quando a reserva for confirmada
                                    printf("> Atual: R$ +%.2f\n",Passagem[ID]/2);
                                    printf("%s\n",line2);
                                    menorDe5[ID]++;                 // Aumenta o contador de menores de 5 anos
                                    IDReservas[countReservas][3]++; // Aumenta o contador de reservas 

                                } else {
                                    printf("> Atual: R$ +%.2f\n",Passagem[ID]);
                                    printf("%s\n",line2);
                                    //totPassagem[ID] += Passagem[ID];
                                }
                                IDReservas[countReservas][0] = countReservas;                                   // ID da reserva                   
                                IDReservas[countReservas][4 + IDReservas[countReservas][2]] = selectAssentos;   // Salva o assento
                                IDReservas[countReservas][2]++;                                                 // Adiciona um valor para quantidade de lugares
                            }
                            else if(Mapa[ID][selectAssentos] == 'R'){
                                strcenter(line2,RED"ERROR: "RST"O ASSENTO JÁ ESTÁ RESERVADO!",32,true);
                            }
                            else if(Mapa[ID][selectAssentos] == 'C'){
                                strcenter(line2,RED"ERROR: "RST"O ASSENTO JÁ ESTÁ COMPRADO!",32,true);
                            }
                        }
                        else if(selectAssentos == (-1)){
                            strcenter(line2,"VOLTANDO PARA TELA PRINCIPAL",32,false);
                        }
                        else {
                            strcenter(line2,RED"ERROR: "RST"O ASSENTO NÃO EXISTE!",32,true);
                        }
                        Sleep(600);
                        if(selectAssentos == (-1) && IDReservas[countReservas][2] > 0){
                            countReservas++;
                            break;
                        }
                    } while (selectAssentos != (-1)); // Tá assim só para que eu não necessite passar o argumento de geração de lugares fora do loop! 
                }
            } while (ID != 0);
        }
        // Confirmar reserva
        else if((char)Key == '3'){
            int selectID;   // ID selecionado
            do{
                system("cls");
                strcenter(line2,"Confirmação de reservas",32,false);
                for(int i = 1; i < countReservas; i++){
                    // Lista de reservas
                    if(IDReservas[i][0] != 0){
                        printf("ID de reserva: %i\n",IDReservas[i][0]);
                        printf("ID do avião: %i (%s)\n",IDReservas[i][1],Destino[IDReservas[i][1]]);
                        printf("Lugares reservados: %i\n",IDReservas[i][2]);
                        printf("Menores de 5 anos: %i\n",IDReservas[i][3]);
                        printf("Assentos:");
                        for(int j = 0; j < IDReservas[i][2]; j++){
                            printf(" %i",IDReservas[i][4+j]);
                        }
                        printf("\nCusto: R$ %.2f\n",((float)Passagem[IDReservas[i][1]]*(IDReservas[i][2]-IDReservas[i][3]) + (Passagem[IDReservas[i][1]]/2)*IDReservas[i][3]));
                        printf("%s\n",line2);
                    }
                }
                printf("Digite o ID da sua reserva (0 para voltar)\n> ");
                scanf("%i",&selectID);
                fflush(stdin);
                if(selectID > 0 && selectID < countReservas){
                    bool confirmado = false;    // Verifica se ela já foi confirmada!
                    for(int j = 0; j < IDReservas[selectID][2]; j++){
                       if(Mapa[IDReservas[selectID][1]][IDReservas[selectID][4+j]] == 'C'){
                           confirmado = true;
                       }
                    }
                    if(confirmado == false){    // Se não sido confirmada ainda o sistema confirma ela
                        strcenter(line2,BLU"RESERVA CONFIRMADA"RST,32,true);
                        for(int j = 0; j < IDReservas[selectID][2]; j++){
                            Mapa[IDReservas[selectID][1]][IDReservas[selectID][4+j]] = 'C';
                        }
                        totPassagem[IDReservas[selectID][1]] += (float)Passagem[IDReservas[selectID][1]]*(IDReservas[selectID][2]-IDReservas[selectID][3]) + (Passagem[IDReservas[selectID][1]]/2)*IDReservas[selectID][3]; 
                        Sleep(600);
                    }
                    // Retorna erro se já tiver sido reservada!
                    else{
                        strcenter(line2,RED"ERROR"RST": A RESERVA JÁ FOI CONFIRMADA",32,true);
                        Sleep(600);
                    }
                } 
                else if(selectID == 0){
                    break;
                }
                // Retorna erro se o ID não existir
                else {
                    strcenter(line2,RED"ERROR"RST": ID DE RESERVA NÃO ENCONTRADO!",32,true);
                    Sleep(600);
                }
            } while (selectID != 0);
        
        }
        // Cancelamento de reservas (Dispensa comentários por serem exatamente iguais a linha 317 a 371)
        else if((char)Key == '4'){
            int selectID = 0;
            do{
                system("cls");
                strcenter(line2,"Cancelamento de reservas",32,false);
                for(int i = 1; i < countReservas; i++){
                    printf("ID de reserva: %i\n",IDReservas[i][0]);
                    printf("ID do avião: %i (%s)\n",IDReservas[i][1],Destino[IDReservas[i][1]]);
                    printf("Lugares reservados: %i\n",IDReservas[i][2]);
                    printf("Menores de 5 anos: %i\n",IDReservas[i][3]);
                    printf("Assentos:");
                    for(int j = 0; j < IDReservas[i][2]; j++){
                        printf(" %i",IDReservas[i][4+j]);
                    }
                    printf("\nCusto: R$ %.2f\n",((float)Passagem[IDReservas[i][1]]*(IDReservas[i][2]-IDReservas[i][3]) + (Passagem[IDReservas[i][1]]/2)*IDReservas[i][3]));
                    printf("%s\n",line2);
                }
                printf("Digite o ID da sua reserva (0 para voltar)\n> ");
                scanf("%i",&selectID);
                fflush(stdin);
                if(selectID > 0 && selectID < countReservas){
                    bool confirmado = false;
                    for(int j = 0; j < IDReservas[selectID][2]; j++){
                       if(Mapa[IDReservas[selectID][1]][IDReservas[selectID][4+j]] == 'C'){
                           confirmado = true;
                       }
                    }
                    if(confirmado == false){
                        strcenter(line2,RED"RESERVA CANCELADA"RST,32,true);
                        for(int j = 0; j < IDReservas[selectID][2]; j++){
                            Mapa[IDReservas[selectID][1]][IDReservas[selectID][4+j]] = 'D';
                        }
                        Sleep(600);
                    }
                    else if(selectID == 0){
                        break;
                    }
                    else{
                        strcenter(line2,RED"ERROR"RST": A RESERVA JÁ FOI CONFIRMADA",32,true);
                        Sleep(600);
                    }
                }
                else if(selectID == 0){
                    break;
                }
                else {
                    strcenter(line2,RED"ERROR"RST": ID DE RESERVA NÃO ENCONTRADO!",32,true);
                    Sleep(600);
                }
            } while (selectID != 0);
        }
        // Está aqui apenas para especificação! (Finaliza o programa)
        else if((char)Key == '5' || Key == 27){
            break;
        }
    } while (Key != 27 || (char)Key != '5');
}
