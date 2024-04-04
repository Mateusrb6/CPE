#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int numBinario, numDecimal = 0, digito, expoente = 0;

    cout << "digite o numero binario: ";
    cin >> numBinario;

    while (numBinario != 0)
    {
        digito = numBinario % 10;
        numDecimal += digito * pow(2, expoente);
        numBinario /= 10;
        expoente++;
    }

    cout << "o numero binario transformado para decimal é: " <<numDecimal;

    return 0;
}
