#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int lado1[20] = {0}, lado2[20] = {0}, hipotenusa[20] = {0};
    int count = 0;

    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            for (int k = 1; k <= 20; k++)
            {
                if ((pow(i, 2) + pow(j, 2)) == pow(k, 2))
                {
                    lado1[count] = i;
                    lado2[count] = j;
                    hipotenusa[count] = k;
                    count++;
                }
            }
        }
    }

    cout << "Os triplos pitagoricos sao: " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "lado 1 = " << lado1[i] << ", ";
        cout << "lado 2 = " << lado2[i] << ", ";
        cout << "hipotenusa = " << hipotenusa[i] << endl;
    }

    return 0;
}
