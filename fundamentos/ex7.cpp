#include <iostream>
using namespace std;
int num, contador = 0;

int numprimo(int x)
{
    contador = 0;
    for (int i = 1; i <= num; i++)
    {
        if ((num % i == 0))
        {
            contador++;
        }
    }
        if (contador == 2)
        {
            return 1; // é primo
        }
        else
        {
            return 0; // não é primo
        }
    
}

int main()
{

    cout << "digite um numero: ";
    cin >> num;

    cout << "é número primo? ";

    if (numprimo(num) == 1 && num != 1)
    {
        cout << "Sim.";
    }
    else
    {
        cout << "Não.";
    }

    return 0;
}