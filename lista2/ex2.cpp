#include <iostream>
using namespace std;
float alcool, gasolina, divisao;

int main(){

    cout << "digite o valor do alcool em reais: ";
    cin >> alcool;

    cout << "digite o valor da gasolina em reais: ";
    cin >> gasolina;

    divisao = alcool / gasolina;

    if (divisao < 0.7)
    {
        cout << "é recomendado abastecer com alcool." << endl;
    } else {
        cout << "é recomendado abastecer com gasolina" << endl;
    }
    
    return 0;
}