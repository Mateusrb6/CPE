#include <iostream>
#include <cmath>

using namespace std;
int cateto1, cateto2, hipotenusa;
int main()
{
    cout << "digite o valor dos catetos: \n";
    cin >> cateto1 >> cateto2;

    hipotenusa = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
    cout << "o valor da hipotenusa é " << hipotenusa << endl;
    
    return 0;
}
