#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>

int main() {
    std::ifstream alturaFile("altura.txt");
    std::ifstream pesoFile("peso.txt");

    if (!alturaFile.is_open() || !pesoFile.is_open()) {
        std::cerr << "Erro ao abrir os arquivos." << std::endl;
        return 1;
    }

    std::map<std::string, double> alturas;
    std::map<std::string, double> pesos;
    
    std::string codigo;
    double medida;

    // Leitura do arquivo de alturas
    while (alturaFile >> codigo >> medida) {
        alturas[codigo] = medida;
    }

    // Leitura do arquivo de pesos
    while (pesoFile >> codigo >> medida) {
        pesos[codigo] = medida;
    }

    alturaFile.close();
    pesoFile.close();

    std::string maiorAlturaCodigo;
    double maiorAltura = std::numeric_limits<double>::lowest();
    std::string maiorPesoCodigo;
    double maiorPeso = std::numeric_limits<double>::lowest();

    // Encontrar a pessoa com a maior altura
    for (const auto& entry : alturas) {
        if (entry.second > maiorAltura) {
            maiorAltura = entry.second;
            maiorAlturaCodigo = entry.first;
        }
    }

    // Encontrar a pessoa com o maior peso
    for (const auto& entry : pesos) {
        if (entry.second > maiorPeso) {
            maiorPeso = entry.second;
            maiorPesoCodigo = entry.first;
        }
    }

    std::cout << "Pessoa com maior altura: " << maiorAlturaCodigo << " com " << maiorAltura << " metros." << std::endl;
    std::cout << "Pessoa com maior peso: " << maiorPesoCodigo << " com " << maiorPeso << " kg." << std::endl;

    return 0;
}
