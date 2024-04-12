#include <iostream>
#include <cstdlib>
using namespace std;
void reiniciarJogo(int &numAleatorio);

int main()
{
    int numAleatorio = rand(), numEscolhido;
    char resposta;
    bool jogoEmAndamento = true;

    cout << "eu tenho um número entre 1 e 1000" << endl
         << "voce consegue adivinhar meu numero?" << endl
         << "digite seu primeiro palpite." << endl;

    cin >> numEscolhido;

    while (numEscolhido >= 1 && numEscolhido <= 1000 && jogoEmAndamento)
    {
        if (numEscolhido == numAleatorio)
        {
            cout << "Excelente! voce adivinhou o numero! Voce gostaria de jogar novamente? (s ou n)?" << endl;
            cin >> resposta;
            if (resposta == 's')
            {
                reiniciarJogo(numAleatorio);
            }
            else if (resposta == 'n')
            {
                jogoEmAndamento = false;
            }
        }
        else if (numEscolhido > numAleatorio)
        {
            cout << "Muito alto. Tente novamente." << endl;
            cin >> numEscolhido;
        }
        else if (numEscolhido < numAleatorio)
        {
            cout << "Muito baixo. Tente novamente." << endl;
            cin >> numEscolhido;
        }
    }

    return 0;
}

void reiniciarJogo(int &numAleatorio)
{
    numAleatorio = rand() % 1000 + 1;
}

