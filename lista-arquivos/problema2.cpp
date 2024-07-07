#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string linha;
    char caractere = 'a';
    int contador = 0;

    ifstream arquivo;
    arquivo.open("mochileiro.txt");

    if (!arquivo.is_open())
    {
        return -1;
    }

    while (getline(arquivo, linha))
    {
        stringstream ss(linha); // ss é um objeto que permite dividir uma linha de texto em componentes menores
        string palavra;

        while (ss >> palavra)
        { // palavra recebe cada palavra obtida pelo ss
            for (char letra : palavra)
            {
                if (letra == caractere)
                {
                    contador++;
                }
            }
        }
    }

    cout << contador << endl;
    arquivo.close();
    return 0;
}