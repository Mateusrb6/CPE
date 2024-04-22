#include <iostream>
#include <vector>


bool perfect(int num) {
    int sum = 1; // 

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

void printFactors(int num) {
    std::vector<int> factors;
    
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            factors.push_back(i);
        }
    }

    std::cout << "Fatores de " << num << ": ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Números perfeitos entre 1 e 1000:" << std::endl;
    
    for (int i = 1; i <= 1000; i++) {
        if (perfect(i)) {
            std::cout << i << " é um número perfeito. ";
            printFactors(i);
        }
    }

    return 0;
}
