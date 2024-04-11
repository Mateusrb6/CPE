#include <iostream>
using namespace std;

int main(){
    float preco[5] = {2.98, 4.50, 9.98, 4.49, 6.87};
    int contador[5] = {0}, produto[5] = {1, 2, 3, 4, 5};
    float varejo[5] = {0};
    int soma[5] = {0};


    for (int i = 0; i < 5; i++)
    {
       cin >> produto[i] >> contador[i];
       soma[produto[i] - 1] += contador[i];
    }
    
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        switch (produto[i])
        {
        case 1:
        varejo[0] = soma[0] * preco[0];
            break;
        case 2:
        varejo[1] = soma[1] * preco[1];
            break;
        case 3:
        varejo[2] = soma[2] * preco[2];
            break;
        case 4:
        varejo[3] = soma[3] * preco[3];
            break;
        case 5:
        varejo[4] = soma[4] * preco[4];
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << varejo[i] << endl;
    }
    return 0;
}
