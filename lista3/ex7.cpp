#include <iostream>
using namespace std;
int senha = 1234;
int senhaDigitada;

int main()
{
    cout << "digite a senha: ";
    cin >> senhaDigitada;

    if (senhaDigitada == senha)
    {
        cout << "ACESSO PERMITIDO";
    } else{
        cout << "ACESSO NEGADO";
    }
    
    return 0;
}