#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(time(0)); 

    cout << "Pense em um número entre 1 e 100." << endl;
    cout << "Eu tentarei adivinhá-lo em no máximo sete tentativas." << endl;

    int low = 1;
    int high = 100;
    int guess;

    for (int i = 1; i <= 7; i++) {
        guess = rand() % (high - low + 1) + low;

        cout << "O número em que você está pensando é menor, igual ou maior que " << guess << "? (l/m/h): ";
        cout << "l => less = menor, m => middle = meio e h => higher = maior" << endl;
        char response;
        cin >> response;

       
        if (response == 'l') {
            high = guess - 1;
        } else if (response == 'm') {
            cout << "Adivinhei! O número é " << guess << "." << endl;
            break;
        } else if (response == 'h') {
            low = guess + 1;
        } else {
            cout << "Entrada inválida. Por favor, responda com 'l', 'm' ou 'h'." << endl;
            --i; 
        }
    }

    if (guess != low && guess != high) {
        cout << "Não consegui adivinhar o número. Talvez você tenha trapaceado..." << endl;
    }

    return 0;
}
