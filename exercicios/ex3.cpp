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

    cout << "o diametro e " << diametro << " e a area e " << area;

    return 0;
}
