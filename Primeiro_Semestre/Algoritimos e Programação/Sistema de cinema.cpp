// Nomecompleto: Lucas Alves Vilela Matr�cula: UC21105257 Curso: Engenharia de Software
// Inicialmente eu n�o ia fazer algo com tantas linhas mas animei um pouco com a ideia kk
// Estou utilizando cin.clear(); cin.sync(); depois de cada um dos cin para evitar multi navega��o (Ex digitar: 2D 10 e proximo input pegar o 10 que estava na mesma linha)
#include <iostream> // Respons�vel por (cout e cin) | print e input
#include <locale.h> // Me permite definir o idioma do terminal
#include <cstdlib> // Permite a manipula��o de string tamb�m (Convers�o atoi//stoi por exemplo)
#include <string.h> // Manipula��o de string
#include <string> // Manipula��o de string
#include <cstdio> // biblioteca padr�o do C++ com diversas utilidades (Dentre elas o printf e o scanf)
#include <map> // Adiciona os maps (Falo melhor deles abaixo)

// Fun��o principal
int main(){ // inicializa a fun��o
    system("chcp 65001"); // Permite que eu modifique a linguagem do terminal (Usei no Visual Studio Code)
    system("cls"); // Limpa tela
    using namespace std; // Adiciona o campo string para ser utilizado como v�riavel
    setlocale(LC_ALL, "Portuguese"); // Permite a escrita em UTF-8 (`�^~, etc.) em portugu�s

    // Declara��es
    std::string tipoIngresso, // Serve para armazenar o tipo de ingresso escolhido (2D, 3D, XD)
    cinema = "UCB-DF Cinema", // Nome do cinema (Declarei isso para que esse nome possa ser colocado em outros lugares com mais facilidade)
    linha(30, '-'), // Cria o meu divisor de linhas
    condicao = "prova"; // Serve definir o modo de funcionamento do programa (Por enquanto tem apenas o modo prova) e o normal (No caso o padr�o se o modo prova n�o for ativado)
    float total; // total = Pre�o Final (Ingressos*Taxa + Acompanhamentos*Quantidade); (Est� declarado em float pois alguns valores como o pre�o do XD podem dar um n�mero com ponto flutuante)
    
    // Declarei essa parte antes apenas por quest�o de separa��o mesmo
    int ingressos = 0, ingressosMin = 10, // 
    sessoes, sessoesMin = 2,
    option = 100, filme = 100;

    // Faixa Etaria MODO PROVA
    // Estou utilizando iostream (cout e cin) em algumas situa��es eu preciso declarar o valor n�merico dos inteiros antes de utilizar eles
    // Isso serve para evitar que o sistema de valores aleat�rios para os inteiros antes que o script interaja com eles.
    int criancaMin = 3, criancaMax = 13,
    adolescenteMin = 14, adolescenteMax = 17,
    adultoMin = 18, adultoMax = 64,
    idosoMin = 65, idosoMax = 100;

    // Eu coloquei estes + 1 em cada map de navega��o para evitar os seguintes erros:
    // 1. O cliente colocar algum valor que n�o seja n�merico (o + 1 previne que o int retorne 0 e acesse o item de chave 0 no map)
    // 2. Impede o uso de valores menores que 1 (Evita a mesma situa��o que a 1� situa��o)
    
    // maps | map.size(): Equivale ao tamanho atual do map

    // A��es
    map<int, string> options; // int: Chave | string: Conte�do (O primeiro valor declarado dentro dos <> sempre vai ser uma chave e o segundo sempre vai ser o conte�do da chave)
    options.insert(pair<int, string>(options.size() + 1,"Comprar ingressos")); 
    options.insert(pair<int, string>(options.size() + 1,"Filmes em cartaz"));
    options.insert(pair<int, string>(options.size() + 1,"Acompanhamentos"));
    options.insert(pair<int, string>(options.size() + 1,"Sair"));

    // Parte do catalogo do cinema
    map<int, string> catalogo; // Cria um dicion�rio em C++ (Particulamente acho muito �til para esse tipo de script)
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Shang-Chi e a Lenda dos Dez An�is")); // pair<>: Adiciona um novo conjunto ao map ()
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Venom - Tempo de Carnificina")); 
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"007: Sem Tempo para Morrer"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"King's Man: a Origem"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Velozes e Furiosos 9"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"O Esquadr�o Suicida"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Godzilla vs. Kong"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Vi�va Negra"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Os Eternos"));
    catalogo.insert(pair<int, string>(catalogo.size() + 1,"Matrix 4"));

    // Acompanhamentos
    map<int, string> Extras;
    Extras.insert(pair<int, string>(Extras.size() + 1,"Refrigerante 1L"));
    Extras.insert(pair<int, string>(Extras.size() + 1,"Refrigerante 500ml"));
    Extras.insert(pair<int, string>(Extras.size() + 1,"Refrigerante 300ml"));
    Extras.insert(pair<int, string>(Extras.size() + 1,"Pipoca G"));
    Extras.insert(pair<int, string>(Extras.size() + 1,"Pipoca M"));
    Extras.insert(pair<int, string>(Extras.size() + 1,"Pipoca P"));
    
    // Tabela de pre�os dos extras do cinema (Utilizei o termo custo no lugar de pre�o na vari�vel pois n�o gosto da ideia de colocar caracteres espec�ficos em vari�veis)
    map<string, float> custoExtras;
    custoExtras.insert(pair<string, float>(Extras[1],10.5));
    custoExtras.insert(pair<string, float>(Extras[2],7.0));
    custoExtras.insert(pair<string, float>(Extras[3],5.0));
    custoExtras.insert(pair<string, float>(Extras[4],15.0));
    custoExtras.insert(pair<string, float>(Extras[5],12.0));
    custoExtras.insert(pair<string, float>(Extras[6],10.0));

    // Custo dos tipos de ingressos
    map<string, float> custoIngressos;
    custoIngressos.insert(pair<string, float>("2D",10.0));
    custoIngressos.insert(pair<string, float>("3D",12.5));
    custoIngressos.insert(pair<string, float>("XD",15.0));

    // Inicializa o sistema (Essa defini��o inicial de option sendo diferente de 3 est� sendo usada para que eu n�o precise escrever o mesmo bloco de c�digo antes de iniciar o loop)
    // Esse loop while tamb�m tem a fun��o de garantir que o sistema continue rodando enquanto o option n�o for definido para o n�mero relacionado a sa�da.
    // Em caso de atualiza��o � preciso que o valor de option em todas as linhas de inicia��o de loop como esta sejam modificados para evitar que o n�mero 3 continue relacionado a sa�da do sistema
    while (option != 3){
        cout << linha << endl << "Bem vindo ao " << cinema << endl << linha << endl; // cout � tipo um print, as << equivalem a v�rgulas e endl equivale a \n
        cout << "O que deseja acessar? " << endl;
        cout << "1. Modo PROVA (Ativado por padr�o)" << endl;
        cout << "2. Acessar sistema" << endl;
        cout << "3. sair" << endl;
        cout << "> ";
        cin >> option; // input de option ( >> � o mesmo que = nesse caso)

        // Previne um erro de buffer relacionado ao cin
        while (cin.fail()){ // Verifica se o valor enviado para o cin n�o condiz com o tipo de vari�vel que est� recebendo o cin
            cin.clear(); // Limpa o cin na mem�ria
            cin.sync(); // Limpa o buffer reservado para o cin
            system("cls"); // Limpa a tela
        }

        // Modo Prova
        // O modo prova � respons�vel por criar aquela sess�o do c�digo que recebe as idades e o sexo de cada pessoa que entra na sess�o
        // Tamb�m mostra a quantidade de pessoas por faixa et�ria, a quantidade de homens e mulheres na sess�o e a quantidade de maiores de idade
        // Al�m disso define o limite de sess�es aqui para 2 e o minimo de ingressos para 10
        if (option == 1){
            // Mensagem de aviso
            system("cls");
            cout << linha << endl << "Aten��o! Desativar o modo prova remove os limites impostos pela prova!" << endl;
            // Ativa/Desativa o modo prova
            if (condicao != "prova"){
                cout << linha << endl << "Modo Prova Ativado" << endl << linha << endl;
                condicao = "prova";
                sessoesMin = 2;
                ingressosMin = 10;

            } else {
                cout << linha << endl << "Modo Prova Desativado" << endl << linha << endl;
                condicao = "normal";
                sessoesMin = 1;
                ingressosMin = 1;
            }

            cout << "Pressione enter para continuar ";
            cin.ignore(10,'\n');
            cin.get();
            system("cls");
            continue; // Continua o c�digo normalmente
        }

        // Entra no sistema do cinema (Parte principal do c�digo)
        if (option == 2){
            system("cls");
            

            // Outro loop while de inicia��o de sistema (Modificar caso sejam adicionadas novas fun��es)
            while(option != options.size()){ // QualquerCoisa.size() � um metodo para pegar a quantidade de caracteres/objetos/itens de qualquer vari�vel (n�o confundir com size of)
                cout << linha << endl << "Bem vindo ao " << cinema << endl << linha << endl;
                
                // Loop criado para mostrar todos os itens do map definido (No caso options)
                // Utilizei essa fun��o em v�rias outras partes do script
                for (int i = 1; i != (options.size() + 1); ++i){ // contador; limite; ritmo 
                    cout << i << ". " << options[i] << endl;
                }

                cout << "> ";
                
                cin >> option;
                while (cin.fail()){
                    cin.clear();
                    cin.sync();
                    system("cls");
                }
				cin.clear();
                cin.sync();
                // Loop de compra de ingressos
                if(option == 1){
                    // Lista de Extras adicionados ao pedido
                    // S� � utilizado caso o valor de extra seja igual a 'S'
                    // est� declarado aqui para que seja resetado automaticamente.
                    map<string, int> ExtrasPedidos;
                    map<int, string> ListaPedidos;
                    
                    // Primeira Etapa
                    while (filme > catalogo.size() || filme < 1){ // || equivale a or (ou)
                        // Inicia o Loop solicitando o c�digo do filme que ser� assistido (Preferi fazer assim do que digitar o nome do filme)
                        // No caso de digitar eu poderia utilizar o metodo getline(cin, nome_do_filme) para pegar o nome completo do filme incluindo espa�os
                        // Por�m n�o o fiz porque desse jeito aqui � muito mais pr�tico
                        system("cls");
                        cout << linha << endl << "Filmes em cartaz" << endl << linha << endl;

                        // Loop para display de maps
                        for (int i = 1; i != (catalogo.size() + 1); ++i){ // contador; limite; ritmo 
                            cout << i << ". " << catalogo[i] << endl; // map[chave] consulta o conte�do da chave no map
                        }
                        cout << linha << endl;
                        cout << "Digite o c�digo do filme desejado!" << endl;
                        cout << "> ";
                        cin >> filme;
                        // Loop para garantir que n�o ocorra nenhum erro no cin (ex: str >> int)
                        while(cin.fail()){
                            cin.clear();
                            cin.sync();
                        }
                        cin.clear();
                        cin.sync();
                    }
                    
                    // Transi��o
                    system("cls");
                    // Segunda Etapa
                    cout << linha << endl << "Ingressos para o filme: " << catalogo[filme] << endl << linha << endl;
                    while(ingressos < ingressosMin){
                        cout << "Pre�o dos ingressos:" << endl;
                        cout << "- 2D: " << custoIngressos["2D"] << " R$" << endl;
                        cout << "- 3D: " << custoIngressos["3D"] << " R$" << endl;
                        cout << "- XD: " << custoIngressos["XD"] << " R$" << endl;
                        cout << linha << endl;

                        // Muda a frase de acordo com a condi��o de execu��o ("prova" // "normal" ou qualquer coisa que n�o seja prova)
                        if (condicao == "prova"){
                            cout << "Quantos ingressos ser�o comprados? ";
                        } else {
                            cout << "Quantos ingressos deseja comprar? ";
                        }
                        cin >> ingressos;
                        
                        while(cin.fail()){
                            cin.clear();
                            cin.sync();
                            continue; // Continua o processo de loop
                        }
                        cin.clear();
                        cin.sync();

                        cout << linha << endl;
                        
                        // Terceira Etapa
                        if (ingressos >= ingressosMin){
                            cout << "Quantas sess�es de filme ser�o assistidas? ";
                            cin >> sessoes;
                            while(cin.fail()){
                                cin.clear();
                                cin.sync();
                                continue;
                            }
                            cin.clear();
                            cin.sync();
                            while (sessoes != sessoesMin && condicao == "prova" || sessoes < 1){ // && equivale a and (e)
                                system("cls");
                                if (condicao == "prova"){
                                    cout << linha << endl << "O n�mero necess�rio de sess�es � de exatamente " << sessoesMin << endl << linha << endl;
                                } else {
                                    cout << linha << endl << "O n�mero m�nimo de sess�es � de " << sessoesMin << endl << linha << endl;
                                }
                                
                                cout << "Pre�o dos ingressos:" << endl;
                                cout << "- 2D: " << custoIngressos["2D"] << " R$" << endl;
                                cout << "- 3D: " << custoIngressos["3D"] << " R$" << endl;
                                cout << "- XD: " << custoIngressos["XD"] << " R$" << endl;
                                cout << linha << endl;
                                cout << "Quantas sess�es de filme ser�o assistidas? ";
                                cin >> sessoes;
                                while(cin.fail()){
                                    cin.clear();
                                    cin.sync();
                                    continue;
                                }
                                cin.clear();
                                cin.sync();
                            }
                            cout << linha << endl;
                            bool VerifyTipo = false; // Criei essa v�riavel para evitar alguns erros com compara��o de string e tamb�m para evitar a possibilidade do sistema passar direto por essa se��o de c�digo sem validar ela primeiro.
                            while(VerifyTipo == false){
                                if (condicao == "prova"){
                                    cout << "Qual tipo de ingresso ser� comprado? ";
                                } else {
                                    cout << "Qual tipo de ingresso deseja comprar? ";
                                }
                                cin >> tipoIngresso;
                                if (tipoIngresso == "2D"){
                                    VerifyTipo = true;
                                }
                                else if (tipoIngresso == "3D"){
                                    VerifyTipo = true;
                                }
                                else if (tipoIngresso == "XD"){
                                    VerifyTipo = true;
                                } else {
                                    system("cls");
                                    cout << linha << endl << "Selecione um tipo de ingresso v�lido!" << endl << linha << endl;
                                    cout << "Pre�o dos ingressos:" << endl;
                                    cout << "- 2D: " << custoIngressos["2D"] << " R$" << endl; // Aqui diferente de alguns casos acima o valor de chave utilizado � uma str
                                    cout << "- 3D: " << custoIngressos["3D"] << " R$" << endl; // O valor indicado para chave depende de como o map foi declarado
                                    cout << "- XD: " << custoIngressos["XD"] << " R$" << endl;
                                    cout << linha << endl;
                                    VerifyTipo = false; // Reseta o valor de VerifyTipo (N�o � t�o necess�rio mas usei por seguran�a)
                                }
                            }
                            
                            system("cls");
                            total = ingressos * custoIngressos[tipoIngresso] * sessoes; // Calcula o pre�o total multiplicando a quantidade de ingressos pelo custo do tipo de ingresso consultado no map custoIngressos e multiplica pelo n�mero de sess�es depois
                            cout << linha << endl << "Filme: " << catalogo[filme] << endl;
                            cout << linha << endl << "O pre�o de " << ingressos << " ingressos " << tipoIngresso << " para " << sessoes << " sess�es � de: " << total << " R$" << endl << linha << endl;
                            break;
                        } 
                        else {
                            system("cls");
                            cout << linha << endl << "O valor minimo de compra � de " << ingressosMin << " ingressos!" << endl << linha << endl;
                        }
                    }
                    cin.clear();
                    cin.sync();
                    // Esse char extra; vai ser utilizado como se fosse um tipo de bool para come�ar uma outra parte do script
                    char extra;
                    cout << "Deseja adicionar algum acompanhamento? (S/N) ";
                    cin >> extra;
                    cin.clear();
                    cin.sync();
                    extra = toupper(extra); // Coloca o char em caixa alta
                    if (extra == 'S'){
                        int pedido = 0;
                        while (pedido != 7){
                            system("cls");
                            cout << linha << endl << "Lista de acompanhamentos" << endl << linha << endl;
                            for (int i = 1; i != (Extras.size() + 1); ++i){ // contador; limite; ritmo 
                                cout << i << ". " << Extras[i] << " (R$ " << custoExtras[Extras[i]] << ")" << endl;
                            }
                            cout << "7. Finalizar" << endl;
                            cout << linha << endl;
                            cout << "> ";
                            cin >> pedido;
                            
                            // Mais uma medida de seguran�a para evitar problemas com int no cin
                            if(cin.fail()){
                                cin.clear();
                                cin.sync(); 
                            }
                            cin.clear();
                            cin.sync();
                            
                            if (pedido < 7 && pedido > 0){
                                int quantidade = 0;
                                char confirmar; // Novamente esse char vai ter uma funcionalidade similar a um bool ('S' para ativar)
                                while (quantidade < 1){
                                    cout << linha << endl;
                                    cout << "Quantos " << Extras[pedido] << " ser�o adicionados? ";
                                    cin >> quantidade;
                                    cin.clear();
                                    cin.sync();
                                    // Outra medida de seguran�a
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.sync();
                                        system("cls");

                                    } else if (quantidade > 0) {
                                        cout << linha << endl;
                                        cout << "Voc� confirma que gostaria de adicionar " << quantidade << " " << Extras[pedido] << " ao seu pedido? (S/N) ";
                                        cin >> confirmar;
                                        confirmar = toupper(confirmar); // Transforma o char em caixa alta
                                        cin.clear();
                                        cin.sync();
                                        if (confirmar == 'S'){
                                            ExtrasPedidos.insert(pair<string,int>(Extras[pedido],quantidade)); // Utilizado para armazenar o nome do pedido e sua quantidade
                                            ListaPedidos.insert(pair<int,string>(ListaPedidos.size(),Extras[pedido])); // Utilizado para armazenar o index do pedido e seu nome
                                            total += custoExtras[Extras[pedido]]*quantidade; // Adiciona o custo do pedido ao valor total
                                        } else {
                                            // Cancela o pedido caso a confirma��o seja diferente de S
                                            cout << linha << endl << "Adi��o cancelada!" << endl << linha << endl;
                                            cout << "Pressione enter para continuar..." << endl << linha << endl;
                                            cin.ignore(10,'\n');
                                            cin.get();
                                        }
                                        
                                    } else {
                                    	system("cls");
                                    	cout << linha << endl << "Valor inv�lido! Tente Novamente!" << endl;
			                            
									}
                                    
                                }
                            }
                        }
                    }

                    system("cls");
                    
                    // Parte referente ao pedido total.
                    cout << linha << endl << "O total do pedido deu: " << total << " R$ " << endl << linha << endl;
                    cout << "Detalhes do pedido:" << endl;
                    cout << "- Filme: " << catalogo[filme] << " " << tipoIngresso << endl;
                    cout << "- Ingressos por sess�o: " << ingressos << " (" << custoIngressos[tipoIngresso] * ingressos << " R$)" << endl;
                    cout << "- Sess�es: " << sessoes << endl;

                    if (ListaPedidos.size() > 0){
                        // Loop de print do map contendo seus pedidos.
                        cout << "Acompanhamentos: " << endl;
                        for (int i = 0; i != ListaPedidos.size(); ++i){ // contador; limite; ritmo 
                            cout << "- " << ExtrasPedidos[ListaPedidos[i]] << " " << ListaPedidos[i] << " (" << ExtrasPedidos[ListaPedidos[i]]*custoExtras[ListaPedidos[i]] << " R$)" << endl;
                        }
                    }
                    
                    cout << linha << endl;
                    cin.ignore(10,'\n');
                    cin.get();
                    
                    
                    if (condicao == "prova"){
                    	system("cls");
                        // Declara��es para armazenar alguns dados
                        int criancas = 0, adolescentes = 0,
                        adultos = 0, idosos = 0,
                        maiorHomem = 0, homens = 0,
                        maiorMulher = 0, mulheres = 0;

                        for(int s = 1; s != (sessoes + 1); s++){
                            system("cls");
                            cout << linha << endl << "Cadastro das pessoas da sess�o " << s << endl << linha << endl;
                            for(int i = 1; i != (ingressos + 1); i++){
                                int idade = 0;
                                char sexo;
                                bool verifySexo = false;
                                cout << i << " Pessoa" << endl;
                                // Loop para garantir uma idade v�lida e o resto do processo tamb�m
                                while (idade < 3 || idade > 100){
                                    cout << "Idade: ";
                                    cin >> idade;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.sync();
                                        system("cls");
                                        cout << linha << endl << "Insira um valor inteiro para idade! " << endl << linha << endl;
                                        cout << i << " Pessoa" << endl;
                                    } 
                                    else if (idade < criancaMin){
                                        system("cls");
                                        cout << linha << endl << "Insira um valor maior do que 3 para idade! " << endl << linha << endl;
                                        cout << i << " Pessoa" << endl;
                                    } 
                                    else if (idade > idosoMax){
                                        system("cls");
                                        cout << linha << endl << "Insira um valor menor do que 100 para idade! " << endl << linha << endl;
                                        cout << i << " Pessoa" << endl;
                                    }
                                }

                                // Condicional para definir a faixa et�ria
                                if (idade >= criancaMin && idade <= criancaMax){
                                    criancas += 1;
                                }
                                else if (idade >= adolescenteMin && idade <= adolescenteMax){
                                    adolescentes += 1;
                                }
                                else if (idade >= adultoMin && idade <= adultoMax){
                                    adultos += 1;
                                }
                                else if (idade >= idosoMin && idade <= idosoMax){
                                    idosos += 1;
                                }

                                // Condicional para definir o sexo (Com cin vc poderia usar por exemplo 12m >> Idade = 12 e Sexo = M)
                                while (verifySexo == false){
                                    cout << "Sexo: ";
                                    cin >> sexo;
                                    sexo = toupper(sexo);
                                    cin.clear();
                                    cin.sync();
                                    if (sexo == 'M'){
                                        homens++;
                                        verifySexo = true;
                                        break;
                                    } 
                                    else if (sexo == 'F') {
                                        mulheres++;
                                        verifySexo = true;
                                        break;
                                    } else {
                                        system("cls");
                                        cout << linha << endl << "Insira um valor aceito para o Sexo (M/F)!" << endl << linha << endl;
                                        cout << "Idade: " << idade << endl;
                                    }
                                    
                                }
                                if (idade >= 18 && sexo == 'F'){
                                    maiorMulher += 1;
                                }
                                else if (idade >= 18 && sexo == 'M'){
                                    maiorHomem += 1;
                                }
                                system("cls");
                                cout << linha << endl;
                            }
                        }
                        // Display de informa��es
                        cout << "Pessoas que assistiram ao filme: " << catalogo[filme] << endl << linha << endl;
                        cout << homens << " Homens e " << mulheres << " Mulheres no total!" << endl << linha << endl;
                        cout << "Divis�o por faixa et�ria: " << endl;
                        cout << "Pessoas de 3 a 13 anos: " << criancas << endl;
                        cout << "Pessoas de 14 a 17 anos: " << adolescentes << endl;
                        cout << "Pessoas de 18 a 64 anos: " << adultos << endl;
                        cout << "Pessoas de 65 a 100 anos: " << idosos << endl;
                        // Enter para continuar
                        cin.ignore(10, '\n');
                        cin.get();
                        // Limpa de tela
                        system("cls");
                        // Parte final dos maiores de idade
                        cout << linha << endl << "Maiores de idade presentes: " << endl << linha << endl;
                        cout << "Mulheres maiores de idade: " << maiorMulher << endl;
                        cout << "Homens maiores de idade: " << maiorHomem << endl;
                        cout << linha << endl << "No total s�o: " << maiorHomem + maiorMulher << " maiores de idade!" << endl << linha << endl;
                    }

                    // reseta os valores monetarios do script
                    ingressos = 0;
                    total = 0;
                    break;
                }

                else if(option == 2){
                    system("cls");
                    cout << linha << endl << "Filmes em cartaz" << endl << linha << endl;
                    // Loop de print (catologo de filmes)
                    for (int i = 1; i != (catalogo.size() + 1); ++i){ // contador; limite; ritmo 
                        cout << i << ". " << catalogo[i] << endl;
                    }
                    cout << linha << endl;
                    cin.ignore(10, '\n');
                    cin.get();
                    system("cls");
                }

                else if(option == 3){
                    system("cls");
                    cout << linha << endl << "Lista de acompanhamentos" << endl << linha << endl;
                    // Loop de print (Lista de acompanhamentos)
                    for (int i = 1; i != (Extras.size() + 1); ++i){ // contador; limite; ritmo 
                        cout << i << ". " << Extras[i] << " (R$ " << custoExtras[Extras[i]] << ")" << endl;
                    }
                    cout << linha << endl;
                    cin.ignore(10, '\n');
                    cin.get();
                    system("cls");
                }

                else if(option == options.size()){
                    cout << linha << endl;
                    cout << "Saindo do sistema de consumidor" << endl;
                    cout << linha << endl;
                    break;
                }
                
                else{
                    system("cls");
                }
            }
            
            // Deixa o script esperando um enter para continuar o sistema
            cin.ignore(10,'\n'); // Espera um enter para continuar o script
            cin.get(); // Garante que o �ltimo cin recebido seja confirmado
            system("cls");
        }

        // Encerra o script      
        else if(option == 3){
            cout << linha << endl;
            cout << "Saindo do sistema de Menus" << endl;
            cout << linha << endl;
            break; // Quebra o loop em que est� inserido
        }
        
        // Limpa a tela em caso de valor inv�lido
        else{
            system("cls");
        }
    }
    system("cls");
    return 0;
}
// Acredito que otimizando este c�digo consigo reduzir aproximadamente 60 a 80 linhas
