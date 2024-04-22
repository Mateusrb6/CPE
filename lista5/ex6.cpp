#include <iostream>
using namespace std;

void hanoi(int n, int origem, int destino, int temporario) {
    if (n == 1) {
        std::cout << origem << " → " << destino << endl;
        return;
    }
    
    hanoi(n - 1, origem, temporario, destino);
    
    cout << origem << " → " << destino <<endl;
    
    hanoi(n - 1, temporario, destino, origem);
}

int main() {
    int numDiscos;
    
    cout << "Digite o número de discos: ";
    cin >> numDiscos;
    
    cout << "Instruções para mover os discos:" << std::endl;
    hanoi(numDiscos, 1, 3, 2); 
    
    return 0;
}
