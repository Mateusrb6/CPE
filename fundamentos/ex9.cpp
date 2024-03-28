#include <iostream>
using namespace std;
float distancia, preco, customedio;

int main()
{
    cout << "digite a distancia percorrida em km: ";
    cin >> distancia;

    if (distancia < 50){
        preco = distancia * 1.75;
    }
    else if (distancia > 50 && distancia < 150)
    {
        preco = (distancia - 50) * 1.65 + (50 * 1.75);
    }
    else if (distancia > 150)
    {
       preco = (50 * 1.75) + (100 * 1.65) + (distancia - 150) * 1.50;
    }
    
    customedio = preco / distancia;

    cout << "o valor total a pagar é " << preco << " reais."<< endl;
    cout << "o custo médio por km é " << customedio << " reais pro km" << endl;
    
    return 0;
}