#include <iostream>
using namespace std;
int raio, diametro, area;
float pi = 3.14159;

int main()
{
    cout << "digite o raio do circulo \n";
    cin >> raio;

    diametro = raio * 2;
    area = pi * raio * raio;

    cout << "o diametro é " << diametro << " e a area é " << area;

    return 0;
}
