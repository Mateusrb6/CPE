#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    float celsius, fahrenheit;
    
    for (celsius = 0; celsius <= 100; celsius++)
    {
        fahrenheit = ((9/5) * (celsius)) + 32; 
        cout << fixed << setprecision(2);
        cout <<"a temperatura de é "<< fahrenheit << " fahrenheit."<< endl;
    }
    
    return 0;
}
