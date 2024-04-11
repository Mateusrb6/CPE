#include <iostream>
using namespace std;

int main(){
    int num[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= num[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}