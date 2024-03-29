#include <iostream>
using namespace std;
char palavra[6]; 
int contadorVogal = 0;
char vogalApareceu[6];

int main()
{
    cout << "digite uma palavra com 5 caracteres: ";
    cin >> palavra;

    // vogal //

    for (int i = 0; i < 6; i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' || palavra[i] == 'A'|| palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U'){
            contadorVogal++;
            vogalApareceu[contadorVogal - 1] = palavra[i];
        }
    }
    
    vogalApareceu[contadorVogal] = '\0';

    cout << "o numero de vogais é: " << contadorVogal << endl;
    cout << "as vogais que apareceram foram: " << vogalApareceu << endl;

    // criptografia //

   




  
    return 0;
}
