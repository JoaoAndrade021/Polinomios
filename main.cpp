#include <iostream>
#include <limits>
using namespace std;

struct Monomios {
    float xCoeficiente;
    int xExpoente;
};

struct Polinomio {
    Monomios lista[10]; //Quantidade maxima de monomios permitidos na parte principal do codigo
    int cont = 0;
};

void CriarPolinomio(Polinomio& polinomio, int xMonomios) {  //Função que cria o polinomio.
    for (int i = 0; i < xMonomios; i++) {
        Monomios monomio{};
        cout << endl;
        do {
            cout << "Qual é o coeficiente do monômio " << i + 1 << "? ";
            cin >> monomio.xCoeficiente;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        } while (cin.fail());

        do {
            cout << "Qual é o expoente do monômio " << i + 1 << "? ";
            cin >> monomio.xExpoente;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        } while (cin.fail());

        cout << endl;
        cout << "O Monômio " << i + 1 << " criado é: " << monomio.xCoeficiente << "x^" << monomio.xExpoente << endl;
        cout << endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        polinomio.lista[i] = monomio;
        polinomio.cont++;
    }
}

void MostrarPolinomioCriado(Polinomio& polinomio) {  // Função que mostra o polinomio.
    for (int i = 0; i < polinomio.cont; i++) {
        cout << polinomio.lista[i].xCoeficiente << "x^" << polinomio.lista[i].xExpoente;
        if (i < polinomio.cont - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

void CalculoValorNumerico(Polinomio& polinomio) {
    int xNumerico;

    cout << "Por qual valor você gostaria que fosse o 'x'? : ";
    cin >> xNumerico;
    cout << endl;

    // Calcular o valor numérico substituindo 'x' pelo valor digitado pelo usuário
    float resultado = 0.0;
    for (int i = 0; i < polinomio.cont; i++) {
        float termo = polinomio.lista[i].xCoeficiente;
        int expoente = polinomio.lista[i].xExpoente;

        // Substituir 'x' pelo valor fornecido pelo usuário
        for (int j = 0; j < expoente; j++) {
            termo *= xNumerico;
        }

        resultado += termo;
    }

    cout << "O valor do polinômio para x = " << xNumerico << " é: " << resultado << endl;
}

void SomarPolinomios(Polinomio& polinomio1, Polinomio& polinomio2, Polinomio& resultado) {  //Função que soma os polinomios.
    int i = 0, j = 0;

    while (i < polinomio1.cont && j < polinomio2.cont) {
        if (polinomio1.lista[i].xExpoente == polinomio2.lista[j].xExpoente) {
            resultado.lista[resultado.cont].xCoeficiente = polinomio1.lista[i].xCoeficiente + polinomio2.lista[j].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = polinomio1.lista[i].xExpoente;
            i++;
            j++;
        }
        else if (polinomio1.lista[i].xExpoente < polinomio2.lista[j].xExpoente) {
            resultado.lista[resultado.cont].xCoeficiente = polinomio1.lista[i].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = polinomio1.lista[i].xExpoente;
            i++;
        }
        else {
            resultado.lista[resultado.cont].xCoeficiente = polinomio2.lista[j].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = polinomio2.lista[j].xExpoente;
            j++;
        }
        resultado.cont++;
    }

    while (i < polinomio1.cont) {
        resultado.lista[resultado.cont].xCoeficiente = polinomio1.lista[i].xCoeficiente;
        resultado.lista[resultado.cont].xExpoente = polinomio1.lista[i].xExpoente;
        i++;
        resultado.cont++;
    }

    while (j < polinomio2.cont) {
        resultado.lista[resultado.cont].xCoeficiente = polinomio2.lista[j].xCoeficiente;
        resultado.lista[resultado.cont].xExpoente = polinomio2.lista[j].xExpoente;
        j++;
        resultado.cont++;
    }
}

void SubtrairPolinomios(Polinomio& minuendo, Polinomio& subtraendo, Polinomio& resultado) {  //Função que soma os polinomios.
    int i = 0, j = 0;

    while (i < minuendo.cont && j < subtraendo.cont) {
        if (minuendo.lista[i].xExpoente == subtraendo.lista[j].xExpoente) {
            resultado.lista[resultado.cont].xCoeficiente = minuendo.lista[i].xCoeficiente - subtraendo.lista[j].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = minuendo.lista[i].xExpoente;
            i++;
            j++;
        } else if (minuendo.lista[i].xExpoente < subtraendo.lista[j].xExpoente) {
            resultado.lista[resultado.cont].xCoeficiente = minuendo.lista[i].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = minuendo.lista[i].xExpoente;
            i++;
        } else {
            resultado.lista[resultado.cont].xCoeficiente = -subtraendo.lista[j].xCoeficiente;
            resultado.lista[resultado.cont].xExpoente = subtraendo.lista[j].xExpoente;
            j++;
        }
        resultado.cont++;
    }

    while (i < minuendo.cont) {
        resultado.lista[resultado.cont].xCoeficiente = minuendo.lista[i].xCoeficiente;
        resultado.lista[resultado.cont].xExpoente = minuendo.lista[i].xExpoente;
        i++;
        resultado.cont++;
    }

    while (j < subtraendo.cont) {
        resultado.lista[resultado.cont].xCoeficiente = -subtraendo.lista[j].xCoeficiente;
        resultado.lista[resultado.cont].xExpoente = subtraendo.lista[j].xExpoente;
        j++;
        resultado.cont++;
    }
}

void MultiplicaPolinomioPorValorNumerico(Polinomio& polinomio ){  //Função que realiza a opção 4.
    int xValor;

    do {
        cout<<"Qual seria o valor que voce gostaria de multiplicar?: ";
        cin>>xValor;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        if (xValor < 1){
            cout << endl;
            cout << "Opcao Invalida, escolha de novo." << endl;
            cout << endl;
        }
    }while ( xValor < 1);

    for (int i = 0; i < polinomio.cont; i++) {  //Laço que multiplica cada monomio criado pelo valor.
        polinomio.lista[i].xCoeficiente *= xValor;
    }
}

void MultiplicaPolinomioPorMonomio(Polinomio& polinomio){  //Função que realiza a opção 5.
    Monomios mono;

    do {
        cout << "Qual é o coeficiente do monômio? : ";
        cin >> mono.xCoeficiente;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao Invalida, entao o coeficiente sera 0." << endl << endl;
        }
    } while (cin.fail());

    do {
        cout << "Qual é o expoente do monômio? : ";
        cin >> mono.xExpoente;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<endl;
            cout<<"Opcao Invalida, entao o coeficiente sera 0."<<endl;
            cout<<endl;
        }
    } while (cin.fail());


    cout << "O Monomio criado é: "<< mono.xCoeficiente << "x^" << mono.xExpoente << endl;

    for ( int i=0 ; i < polinomio.cont ; i++){
        polinomio.lista[i].xCoeficiente = polinomio.lista[i].xCoeficiente * mono.xCoeficiente;
        polinomio.lista[i].xExpoente = polinomio.lista[i].xExpoente + mono.xExpoente;
    }

}

void MultiplicaPolinomios( Polinomio &polinomio1,  Polinomio &segundo_polinomio, Polinomio &res_final) {  //Função que multiplica polinomio por polinomio.
    for (int i = 0; i < polinomio1.cont; i++) {
        for (int j = 0; j < segundo_polinomio.cont; j++) {
            Monomios monomio{};
            monomio.xCoeficiente = polinomio1.lista[i].xCoeficiente * segundo_polinomio.lista[j].xCoeficiente;
            monomio.xExpoente = polinomio1.lista[i].xExpoente + segundo_polinomio.lista[j].xExpoente;
            res_final.lista[res_final.cont++] = monomio;
        }
    }
}

int main()
{
    int xMonomios, xEscolha;
    Polinomio polinomio;

    cout << "Trabalho feito por: João Vitor Martini e Gabriel Beltrao Laus" << endl;

    cout << "\n"
            "   _____      _            _           _                       _                    _ _                       _           \n"
            "  / ____|    | |          | |         | |                     | |                  | (_)                     (_)          \n"
            " | |     __ _| | ___ _   _| | __ _  __| | ___  _ __ __ _    __| | ___   _ __   ___ | |_ _ __   ___  _ __ ___  _  ___  ___ \n"
            " | |    / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |  / _` |/ _ \\ | '_ \\ / _ \\| | | '_ \\ / _ \\| '_ ` _ \\| |/ _ \\/ __|\n"
            " | |___| (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| | | (_| |  __/ | |_) | (_) | | | | | | (_) | | | | | | | (_) \\__ \\\n"
            "  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \\__,_|  \\__,_|\\___| | .__/ \\___/|_|_|_| |_|\\___/|_| |_| |_|_|\\___/|___/\n"
            "                                                                       | |                                                \n"
            "                                                                       |_|                                                " << endl;

    cout << "Seja bem-vindo à calculadora de polinômios" << endl;
    cout << "Digite enter para continuar";
    cin.get();

    cout << "\n" << endl;

    do{
        cout<<"Quantos Monomios voce gostaria de criar? (de 1 - 10 ) : "; // Decisão de quantos monomios tera no polinomio principal.
        cin>>xMonomios;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while (xMonomios < 1 || xMonomios > 10);

    CriarPolinomio(polinomio, xMonomios); //Função para criação de polinomio.

    cout<<endl;
    cout<<endl;
    cout << "Esse é o Polinomio criado: ";
    MostrarPolinomioCriado(polinomio);
    cin.get();
    cout<<endl;
    cout<<endl;

    cout<<"O que voce gostaria de fazer com o Polinomio criado?"<<endl; //Opções para calcular o polinomio dado.
    cout<<endl;
    cout<<"1) Calcular o valor numérico do polinômio"<<endl;
    cout<<"2) Somar Polinomios"<<endl;
    cout<<"3) Substrair Polinomio"<<endl;
    cout<<"4) Multiplicar o Polinômio por um valor constante"<<endl;
    cout<<"5) Multiplicar o Polinômio por um Monômio"<<endl;
    cout<<"6) Multiplicar dois Polinômios"<<endl;
    cout<<endl;

    do { //Do_While para caso aconteça um erro na digitação das opção.
        cout<<"Resposta: ";
        cin>>xEscolha;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        if (xEscolha != 1 && xEscolha != 2 && xEscolha != 3 && xEscolha != 4 && xEscolha != 5 && xEscolha != 6){
            cout << endl;
            cout << "Opcao Invalida, escolha de novo." << endl;
            cout << endl;
        }
    } while (xEscolha != 1 && xEscolha != 2 && xEscolha != 3 && xEscolha != 4 && xEscolha != 5 && xEscolha != 6);
    cout<<endl;

    switch (xEscolha) {
        case 1:
            CalculoValorNumerico(polinomio);
            break;
        case 2: {
            Polinomio polinomio_soma; //Novo polinomio criado para poder continuar a adição.

            int xMonomios2; //Cria uma variável para indicar quantos monomios terá.

            do {
                cout << "Quantos elementos tera o Polinomio? : ";
                cin >> xMonomios2;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            } while (xMonomios2 < 2 || xMonomios2 > 5);

            CriarPolinomio(polinomio_soma, xMonomios2);

            Polinomio resultado; //Polinomio de resultado.

            SomarPolinomios(polinomio, polinomio_soma, resultado); //Chama a função para somar os monomios.

            cout << "Resultado = ";
            MostrarPolinomioCriado(resultado);
            break;
        }
        case 3: {
            Polinomio polinomio_subtracao; //Novo polinomio criado para poder continuar a subtração.

            int xMonomios2;

            do {
                cout << "Quantos elementos terá o Polinomio para subtrair? : ";
                cin >> xMonomios2;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            } while (xMonomios2 < 2 || xMonomios2 > 5);

            CriarPolinomio(polinomio_subtracao, xMonomios2);

            Polinomio resultado; //Polinomio de resultado.

            SubtrairPolinomios(polinomio, polinomio_subtracao, resultado); //Chama a função para subtrair os monomios.
            cout << "Resultado = ";
            MostrarPolinomioCriado(resultado);
            break;
        }
        case 4:
            MultiplicaPolinomioPorValorNumerico(polinomio); //Função da opção 4, em que se multiplica o polinomio por um valor numérico.
            cout<<endl;
            cout<<"Resultado = ";
            MostrarPolinomioCriado(polinomio);
            break;
        case 5:
            MultiplicaPolinomioPorMonomio(polinomio); //Função da opção 5, em que se multiplica o polinomio por um monomio.
            cout<<endl;
            cout<<"Resultado = ";
            MostrarPolinomioCriado(polinomio);
            break;
        case 6:
            Polinomio segundo_polinomio; //Novo polinomio criado para poder continuar a multiplicação.

            int q;

            do{
                cout << "Quantos elementos tera o Polinomio? : "; //Decisão de quantos monomios tera o polinomio.
                cin >> q;
            }while ( q < 2 || q > 5 );

            CriarPolinomio(segundo_polinomio, q); //Criando o segundo polinomio.

            Polinomio res_final; //Mais um polinomio criado, dessa vez para criar um polinomio representando o resultado da multiplicação.

            MultiplicaPolinomios(polinomio, segundo_polinomio, res_final); //Função de multiplicação, criada para multiplicar os dois polinômios.
            cout << "Resultado = ";
            MostrarPolinomioCriado(res_final);
            break;
    }

    return 0;
}