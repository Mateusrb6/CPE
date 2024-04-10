#include <iostream>
using namespace std;

int main(){
    int e;
    float fatorial = 1, resultado[10] = {0}, soma = 0;

    for (int i = 1; i < 10; i++)
    {
        fatorial *= i;
        resultado[i] = 1.0 / fatorial; 
    }

    for (int i = 0; i < 10; i++)
    {
       soma += resultado[i];
    }
    
    e = 1 + soma;

    cout << e << endl;
    return 0;
}