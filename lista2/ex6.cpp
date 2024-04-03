#include <iostream>
using namespace std;
int lado1, lado2, lado3;

int main()
{
    cout << "escreva a medida dos lados do triangulo: ";
    cin >> lado1 >> lado2 >> lado3;

    if (lado1 == lado2 && lado2 == lado3)
    {
        cout << "o triangulo é equilatero";
    } else if ((lado1 == lado2 && lado1 != lado3) || (lado2 == lado3 && lado2 != lado1) || (lado1 == lado3 && lado1 != lado2))
    {
        cout << "o triangulo é isosceles";
    } else{
        cout << "o triangulo é escaleno";
    }
    
    return 0;
}