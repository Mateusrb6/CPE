#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> numeros;
    string linha;
    fstream arquivo;

    arquivo.open("vetores.txt", ios::in | ios::app);

    if(!arquivo.is_open()){
        return -1;
    }

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string numStr;
        vector<int> linhaNumeros;

        while (ss >> numStr) {
            for (char c : numStr) {
                linhaNumeros.push_back(c - '0');  // Converter char para int
            }
        }

        numeros.push_back(linhaNumeros);
    }

    if (numeros.empty()) {
        cout << "Nenhum número lido do arquivo" << endl;
        return 0;
    }

    // Somar os elementos correspondentes
    vector<int> soma(numeros[0].size(), 0);

    for (const auto& linhaNumeros : numeros) {
        for (size_t i = 0; i < linhaNumeros.size(); ++i) {
            soma[i] += linhaNumeros[i];
        }
    }

    arquivo.close();
  


     arquivo2.open("soma.txt", ios::out);

    if (!arquivo2.is_open()) {
        return -1;
    }

    for (int s : soma) {
        arquivo2 << s << endl;
    }

    ifstream arquivo2("soma.txt");

    if (!arquivo2.is_open()) {
        return -1;
    }

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string numStr;
        vector<int> linhaNumerosSomados;

        while (ss >> numStr) {
            for (char c : numStr) {
                cout << c << endl;
            }
        }
    }

    

    return 0;
}
