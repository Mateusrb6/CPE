#include <iostream>
using namespace std;
int num1, num2;
char op;

int main()
{
    cout << "digite dois numeros: ";
    cin >> num1 >> num2;

    cout << "digite o operador (+, -, * ou /): ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        break;
    case '/':
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        break;
    default:
        cout << "operador inválido." << endl;
        break;
    }

    return 0;
}