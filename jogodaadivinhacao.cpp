#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Declara que vou usar várias vezes "std"

int main () {
//Função principal
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;
    
    cout << "Escolha o seu nivel de dificuldade:" << endl;
    cout << "Facil (F), Medio (M), Dificil (D)" << endl;

    char dificuldade;
    //Variável com valor de LETRA
    cin >> dificuldade; 

    int numero_de_tentativas;

     if (dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    srand(time(NULL)); //Biblioteca: Linha 3
    const int NUMERO_SECRETO = rand() % 100; //Biblioteca: Linha 2
    //Declara um número inteiro
    //Const: A variável não muda
    //Rand: O número atribuido é aleatório
    //%: O resto de 100 serve para deixar o número escolhido de 0 até 99

    bool nao_acertou = true;
    //Vai executar a repetição

    int tentativas = 0;
    //Variável do número de tentativas

    double pontos = 1000.0;
    //Variáve com valor decimal

    for(tentativas = 1; tentativas <= numero_de_tentativas;tentativas++){
        //Laço de repetição
        int chute;
        //declara variavel "chute"
        cout << "Tentativas " << tentativas << endl;
        cout << "Qual seu chute?";
        //SAÍDA
        cin >> chute;
        //ENTRADA

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        //Vírgula depois do "2" para ele deixar de ser inteiro e virar decimal
        pontos = (pontos-pontos_perdidos);

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        //bool -> Variavel só aceita verdadeiro ou falso
        cout << "O valor do seu chute e: " << chute << endl;
        if (acertou){
            //chama variável booleana
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            
            nao_acertou = false;
            //Para a repetição
            break;
            //Quebra o laço de repetição
        }

        else if (maior){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }

        else {
            cout << "Seu chute foi menor que numero secreto!" << endl;
        }
        //Condicionais
    }
    cout << "FIM DE JOGO!" << endl;
    if (nao_acertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
}