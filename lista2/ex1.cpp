#include <iostream>
using namespace std;
int litros, km, consumo;

int main(){

    cout << "digite a quantidade de litros: ";
    cin >> litros;

    cout << "digite a distancia percorrida pelo carro em km: ";
    cin >> km;

    consumo = km / litros;

    cout << "a media do consumo do carro é " << consumo << "km por litro de gasolina." << endl;

    return 0;
}