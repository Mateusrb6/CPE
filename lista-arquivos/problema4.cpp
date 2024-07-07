#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void cadastrarAluno() {
    std::string nome;
    std::string matricula;

    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Digite a matrícula do aluno: ";
    std::getline(std::cin, matricula);

    std::ofstream arquivo(nome + ".txt");
    if (arquivo.is_open()) {
        arquivo << matricula << std::endl;
        arquivo.close();
        std::cout << "Aluno cadastrado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao criar o arquivo do aluno." << std::endl;
    }
}

void adicionarNota() {
    std::string nome;
    double nota;

    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::ifstream arquivoLeitura(nome + ".txt");
    if (!arquivoLeitura.is_open()) {
        std::cerr << "Aluno não cadastrado." << std::endl;
        return;
    }
    arquivoLeitura.close();

    std::cout << "Digite a nota do aluno: ";
    std::cin >> nota;

    std::ofstream arquivo(nome + ".txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << nota << std::endl;
        arquivo.close();
        std::cout << "Nota adicionada com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo do aluno." << std::endl;
    }
}

void calcularMedia() {
    std::string nome;
    std::string linha;
    double soma = 0;
    int contador = 0;

    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::ifstream arquivo(nome + ".txt");
    if (!arquivo.is_open()) {
        std::cerr << "Aluno não cadastrado." << std::endl;
        return;
    }

    // Ignorar a primeira linha (matrícula)
    std::getline(arquivo, linha);

    // Ler as notas
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        double nota;
        iss >> nota;
        soma += nota;
        contador++;
    }

    arquivo.close();

    if (contador == 0) {
        std::cout << "Nenhuma nota cadastrada para o aluno." << std::endl;
    } else {
        double media = soma / contador;
        std::cout << "Média do aluno " << nome << ": " << media << std::endl;
    }
}

int main() {
    int opcao;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Cadastrar aluno" << std::endl;
        std::cout << "2. Adicionar nota de um aluno" << std::endl;
        std::cout << "3. Calcular média de um aluno" << std::endl;
        std::cout << "4. Fechar o programa" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                adicionarNota();
                break;
            case 3:
                calcularMedia();
                break;
            case 4:
                std::cout << "Programa encerrado." << std::endl;
                break;
            default:
                std::cerr << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    } while (opcao != 4);

    return 0;
}
