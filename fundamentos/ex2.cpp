#include <iostream>
using namespace std;
int num1, num2, soma, diferenca, quociente;

int main()
{

    cout << "forneça dois números \n";
    cin >> num1 >> num2;

    soma = num1 + num2;
    diferenca = num1 - num2;
    quociente = num1 / num2;

    cout << "a soma é igual a " << soma << endl; 
    cout << "a diferença é igual a " << diferenca << endl;
    cout << "o quociente é igual a " << quociente << endl;

        return 0;
}
