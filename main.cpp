#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Monomio {
    float xCoeficiente;
    int xExpoente;
};

vector<Monomio> CriarMonomios(int xMonomios) {
    vector<Monomio> monomios;
    for (int i = 0; i < xMonomios; ++i) {
        Monomio monomio{};
        cout << "Digite o coeficiente do monômio " << i + 1 << ": " << endl;
        cin >> monomio.xCoeficiente;
        cout << "Digite o expoente do monômio " << i + 1 << ": " << endl;
        cin >> monomio.xExpoente;
        monomios.push_back(monomio);
    }
    return monomios;
}

vector<Monomio> SomarMonomios(vector<Monomio>& monomios) {
    vector<Monomio> polinomio;

    polinomio.push_back(monomios[0]);

    for (int i = 1; i < monomios.size(); ++i) {
        bool adicionado = false;
        for (int j = 0; j < polinomio.size(); ++j) {
            if (monomios[i].xExpoente == polinomio[j].xExpoente) {
                polinomio[j].xCoeficiente += monomios[i].xCoeficiente;
                adicionado = true;
                break;
            }
        }
        if (!adicionado) {
            polinomio.push_back(monomios[i]);
        }
    }

    return polinomio;
}

vector<Monomio> SubtrairMonomios(vector<Monomio>& polinomio1, vector<Monomio>& polinomio2) {
    vector<Monomio> resultado = polinomio1;

    for (const Monomio& monomio2 : polinomio2) {
        bool xSubtraiu = false;
        for (Monomio& monomio1 : resultado) {
            if (monomio1.xExpoente == monomio2.xExpoente) {
                monomio1.xCoeficiente -= monomio2.xCoeficiente;
                xSubtraiu = true;
                break;
            }
        }
        if (!xSubtraiu) {
            Monomio novoMonomio{};
            novoMonomio.xCoeficiente = -monomio2.xCoeficiente;
            novoMonomio.xExpoente = monomio2.xExpoente;
            resultado.push_back(novoMonomio);
        }
    }

    resultado.erase(
            remove_if(resultado.begin(), resultado.end(), [](const Monomio& m) {
                return m.xCoeficiente == 0.0;
            }),
            resultado.end()
    );

    return resultado;
}

int main() {
    int xMonomios;
    int xEscolhaOperacao;

    cout << "Trabalho feito por: João Vitor Martini e Gabriel Laus" << endl;

    cout << "\n"
            " _____       _            _           _                       _                    _ _                       _           \n"
            "/  __ \\     | |          | |         | |                     | |                  | (_)                     (_)          \n"
            "| /  \\/ __ _| | ___ _   _| | __ _  __| | ___  _ __ __ _    __| | ___   _ __   ___ | |_ _ __   ___  _ __ ___  _  ___  ___ \n"
            "| |    / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |  / _` |/ _ \\ | '_ \\ / _ \\| | | '_ \\ / _ \\| '_ ` _ \\| |/ _ \\/ __|\n"
            "| \\__/\\ (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| | | (_| |  __/ | |_) | (_) | | | | | | (_) | | | | | | | (_) \\__ \\\n"
            " \\____/\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \\__,_|  \\__,_|\\___| | .__/ \\___/|_|_|_| |_|\\___/|_| |_| |_|_|\\___/|___/\n"
            "                                                                      | |                                                \n"
            "                                                                      |_|                                                " << endl;

    cout << "Seja bem-vindo à calculadora de polinômios" << endl;
    cout << "Digite enter para continuar";
    cin.get();

    cout << "\n" << endl;

    do {
        cout << "Você gostaria de criar quantos monômios? (1 a 5)" << endl;
        cin >> xMonomios;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (xMonomios < 1 || xMonomios > 5);

    vector<Monomio> monomios = CriarMonomios(xMonomios);

    cout << "Escolha uma opção:\n";
    cout << "1 - Somar Polinômios\n";
    cout << "2 - Subtrair Polinômios\n";
    cin >> xEscolhaOperacao;

    vector<Monomio> resultado;

    if (xEscolhaOperacao == 1) {
        resultado = SomarMonomios(monomios);
    } else if (xEscolhaOperacao == 2) {
        resultado = SubtrairMonomios(monomios, monomios);
    } else {
        cout << "Escolha inválida." << endl;
        return 1;
    }

    cout << "Polinômio resultante:" << endl;
    for (int i = 0; i < resultado.size(); ++i) {
        cout << resultado[i].xCoeficiente << "x^" << resultado[i].xExpoente;
        if (i < resultado.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    return 0;
}