#include <iostream>
#include <cstdlib>
#include <ctime>

void generateNumbers(int &num1, int &num2) {
    num1 = rand() % 10 + 1; 
    num2 = rand() % 10 + 1; 
}

void askQuestion(int num1, int num2) {
    std::cout << "Quanto é " << num1 << " vezes " << num2 << "?" << std::endl;
}

int main() {
    
    srand(time(0));
    
    int num1, num2;
    generateNumbers(num1, num2);
    
    while (true) {
        askQuestion(num1, num2); 
        
        int answer;
        std::cin >> answer; 
        
        if (answer == num1 * num2) {
            std::cout << "Muito bom!" << std::endl;
            generateNumbers(num1, num2); 
        } else {
            std::cout << "Não. Por favor, tente novamente." << std::endl;
        }
    }
    
    return 0;
}
