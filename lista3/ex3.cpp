#include <iostream>
using namespace std;

int main(){

    int num, originalNum, reverseNum = 0, resto;

    cout << "digite um numero: ";
    cin >> num;

    originalNum = num;

    while (num != 0)
    {
        resto = num % 10;
        reverseNum = reverseNum * 10 + resto;
        num = num / 10;
    }
    
    if (originalNum == reverseNum)
    {
        cout << originalNum << " é um palindromo" << endl;
    } else {
        cout << originalNum << " não é um palindromo";
    }
    
    return 0;
}
