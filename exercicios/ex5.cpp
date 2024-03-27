#include <iostream>
using namespace std;
float largura, comprimento, area;

int main()
{

    cout << "digite a largura e o comprimento da sala em centimetros \n";

    cout << "largura: ";
    cin >> largura;

    cout << "comprimento: ";
    cin >> comprimento;

    area = largura * comprimento;

    cout << "a area da sala é " << area << " centimetros.";

    return 0;
}
