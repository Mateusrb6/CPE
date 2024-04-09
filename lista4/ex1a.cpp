#include <iostream>
using namespace std;

int main(){
    int num, resultado = 1;
    
    cout << "insira um numero positivo: ";
    cin >> num;

    // fatorial = num ( num - 1 ) 
    // 10! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1

    for (int i = num; i > 1; i--)
    {
        resultado *= i;
    }
    
    /*
    1) resultado iniciado como um, então o 
    primeiro ciclo será 1 * num.
    2) em seguida, o i do ultimo parametro do for 
    irá diminuir uma unidade a cada ciclo enquanto
    i for maior que 1.
    */
    
    cout << resultado;
    return 0;
}
