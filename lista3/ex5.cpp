#include <iostream>
using namespace std;

int main()
{
    char letra;

    cout << "digite uma letra: ";
    cin >> letra;

    switch (letra)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        cout << "é vogal" << endl;
        break;
    default:
        cout << "não é vogal" << endl;
        break;
    }
    return 0;
}