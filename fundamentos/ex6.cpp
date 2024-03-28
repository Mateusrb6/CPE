#include <iostream>
using namespace std;
int num1, num2;

int main()
{

    cout << "digite dois numeros: \n";
    cin >> num1 >> num2;

    if (num1 % num2 == 0)
    {
        cout << "o numero 1 é multiplo do numero 2";
    }

    else
    {
        cout << "o numero 1 não é multiplo do numero 2";
    }
    return 0;
}