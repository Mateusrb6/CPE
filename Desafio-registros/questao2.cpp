#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int TAMANHO_MAXIMO = 1500; // Capacidade máxima de ramais
int quantidadeRegistros = 0;

struct Ramal {
    int numero;
    int categoria;
    string setor;
    int localizacao;
    string sala;
    string responsavel;
    string responsavelAteste;
};

int main() {
    Ramal vetorRamais[TAMANHO_MAXIMO];

    while (quantidadeRegistros < TAMANHO_MAXIMO) {
        Ramal ramal;
        int numeroRamal;
        
        cout << "\n=================================================\n";
        cout << "CADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE\n";
        cout << "=================================================\n";

        do {
            cout << "Informe o número do Ramal entre 1000 e 2999: ";
            cin >> numeroRamal;

            bool ramalExistente = false;
            for (int i = 0; i < quantidadeRegistros; i++) {
                if (vetorRamais[i].numero == numeroRamal) {
                    ramalExistente = true;
                    break;
                }
            }

            if (numeroRamal < 1000 || numeroRamal > 2999 || ramalExistente) {
                cout << "Número do Ramal inválido ou já cadastrado\n";
            }
        } while (numeroRamal < 1000 || numeroRamal > 2999);

        ramal.numero = numeroRamal;

        cout << "Informe o código da Categoria entre 0 e 6: ";
        cin >> ramal.categoria;
        cin.ignore();

        cout << "Informe a descrição do Setor: ";
        getline(cin, ramal.setor);
        transform(ramal.setor.begin(), ramal.setor.end(), ramal.setor.begin(), ::toupper);

        cout << "Informe o código da Localização (500 ou 505): ";
        cin >> ramal.localizacao;
        cin.ignore();

        cout << "Informe o número do andar + o número da sala: ";
        getline(cin, ramal.sala);

        cout << "Informe o nome do Responsável pelo Ramal: ";
        getline(cin, ramal.responsavel);
        transform(ramal.responsavel.begin(), ramal.responsavel.end(), ramal.responsavel.begin(), ::toupper);

        cout << "Informe o nome do Responsável pelo Ateste: ";
        getline(cin, ramal.responsavelAteste);
        transform(ramal.responsavelAteste.begin(), ramal.responsavelAteste.end(), ramal.responsavelAteste.begin(), ::toupper);

        vetorRamais[quantidadeRegistros++] = ramal;

        char continuar;
        cout << "Deseja cadastrar outro ramal? (s/n): ";
        cin >> continuar;
        if (tolower(continuar) != 's') {
            break;
        }
    }

    cout << "\n==============================================================\n";
    cout << "IMPRESSÃO DO CADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE\n";
    cout << "==============================================================\n";
    
    for (int i = 0; i < quantidadeRegistros; i++) {
        Ramal ramal = vetorRamais[i];
        cout << "_____________________________________\n";
        cout << " INFORMAÇÕES GERAIS DO RAMAL \n";
        cout << "_____________________________________\n";
        cout << "Ramal                  : " << ramal.numero << "\n";
        cout << "Categoria              : " << ramal.categoria << "\n";
        cout << "Setor                  : " << ramal.setor << "\n";
        cout << "Edifício               : " << ramal.localizacao << "\n";
        cout << "Sala                   : " << ramal.sala << "\n";
        cout << "Responsável pelo ramal : " << ramal.responsavel << "\n";
        cout << "Responsável pelo ateste: " << ramal.responsavelAteste << "\n";
        cout << "\nPressione qualquer tecla para continuar. . .";
        cin.ignore();
        cin.get();
        cout << "\n============================================\n";
    }

    int opcao;

    do {
        cout << "\n=================================================\n";
        cout << "PESQUISA DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE\n";
        cout << "=================================================\n";
        cout << "Escolha o método de pesquisa:\n";
        cout << "1. Número do Ramal\n";
        cout << "2. Setor\n";
        cout << "3. Edifício\n";
        cout << "4. Responsável pelo Ramal\n";
        cout << "5. Responsável pelo Ateste\n";
        cout << "0. Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 0) {
            break;
        }

        unordered_set<string> opcoesDisponiveis;
        vector<string> opcoesUnicas;

        switch (opcao) {
            case 1:
                for (int i = 0; i < quantidadeRegistros; i++) {
                    opcoesDisponiveis.insert(to_string(vetorRamais[i].numero));
                }
                break;
            case 2:
                for (int i = 0; i < quantidadeRegistros; i++) {
                    opcoesDisponiveis.insert(vetorRamais[i].setor);
                }
                break;
            case 3:
                for (int i = 0; i < quantidadeRegistros; i++) {
                    opcoesDisponiveis.insert(to_string(vetorRamais[i].localizacao));
                }
                break;
            case 4:
                for (int i = 0; i < quantidadeRegistros; i++) {
                    opcoesDisponiveis.insert(vetorRamais[i].responsavel);
                }
                break;
            case 5:
                for (int i = 0; i < quantidadeRegistros; i++) {
                    opcoesDisponiveis.insert(vetorRamais[i].responsavelAteste);
                }
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
                continue;
        }

        opcoesUnicas.assign(opcoesDisponiveis.begin(), opcoesDisponiveis.end());
        sort(opcoesUnicas.begin(), opcoesUnicas.end());

        cout << "Opções disponíveis:\n";
        for (int i = 0; i < opcoesUnicas.size(); i++) {
            cout << i + 1 << ". " << opcoesUnicas[i] << "\n";
        }

        int escolha;
        cout << "Selecione uma opção (número) para visualizar os detalhes: ";
        cin >> escolha;
        cin.ignore();

        if (escolha < 1 || escolha > opcoesUnicas.size()) {
            cout << "Opção inválida! Tente novamente.\n";
            continue;
        }

        string valorSelecionado = opcoesUnicas[escolha - 1];

        cout << "\nResultados da pesquisa:\n";
        for (int i = 0; i < quantidadeRegistros; i++) {
            bool exibir = false;
            switch (opcao) {
                case 1:
                    exibir = (to_string(vetorRamais[i].numero) == valorSelecionado);
                    break;
                case 2:
                    exibir = (vetorRamais[i].setor == valorSelecionado);
                    break;
                case 3:
                    exibir = (to_string(vetorRamais[i].localizacao) == valorSelecionado);
                    break;
                case 4:
                    exibir = (vetorRamais[i].responsavel == valorSelecionado);
                    break;
                case 5:
                    exibir = (vetorRamais[i].responsavelAteste == valorSelecionado);
                    break;
            }
            if (exibir) {
                Ramal ramal = vetorRamais[i];
                cout << "_____________________________________\n";
                cout << " INFORMAÇÕES GERAIS DO RAMAL \n";
                cout << "_____________________________________\n";
                cout << "Ramal                  : " << ramal.numero << "\n";
                cout << "Categoria              : " << ramal.categoria << "\n";
                cout << "Setor                  : " << ramal.setor << "\n";
                cout << "Edifício               : " << ramal.localizacao << "\n";
                cout << "Sala                   : " << ramal.sala << "\n";
                cout << "Responsável pelo ramal : " << ramal.responsavel << "\n";
                cout << "Responsável pelo ateste: " << ramal.responsavelAteste << "\n";
                cout << "\nPressione qualquer tecla para continuar. . .";
                cin.ignore();
                cin.get();
                cout << "\n============================================\n";
            }
        }
    } while (opcao != 0);

    return 0;
}
