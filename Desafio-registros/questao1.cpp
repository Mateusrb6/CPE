#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int TAMANHO_MAXIMO = 1500; // Capacidade máxima de ramais
int quantidadeRegistros = 0;

struct Categoria {
    int codigo;
    string nome;
};

struct Setor {
    string descricao;
};

struct Localizacao {
    int codigo;
    string nome;
};

struct Ramal {
    int numero; // range entre 1000 e 2999
    Categoria categoria; // conforme struct Categoria
    Setor setor; // conforme struct Setor
    Localizacao localizacao; // conforme struct Localizacao
    string sala; // número do andar e mais dois dígitos (sequencial)
    string responsavel; // Necessário apenas o primeiro nome (usuário do Ramal)
    string responsavelAteste; // Necessário apenas o primeiro nome (usuário que atesta fatura)
};

void cadastrarRamal(Ramal &ramal, Ramal *vetorRamais, int quantidade);
bool verificarRamal(const Ramal *vetorRamais, int quantidade, int numeroRamal);
void imprimirRamal(const Ramal &ramal);

int main() {
    Ramal vetorRamais[TAMANHO_MAXIMO];

    while (quantidadeRegistros < TAMANHO_MAXIMO) {
        cadastrarRamal(vetorRamais[quantidadeRegistros], vetorRamais, quantidadeRegistros);
        quantidadeRegistros++;
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
        imprimirRamal(vetorRamais[i]);
    }

    return 0;
}

void cadastrarRamal(Ramal &ramal, Ramal *vetorRamais, int quantidade) {
    int numeroRamal;
    
    cout << "\n=================================================\n";
    cout << "CADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE\n";
    cout << "=================================================\n";

    do {
        cout << "Informe o número do Ramal entre 1000 e 2999: ";
        cin >> numeroRamal;

        if (numeroRamal < 1000 || numeroRamal > 2999) {
            cout << "Número do Ramal fora do intervalo 1000 até 2999\n";
        } else if (!verificarRamal(vetorRamais, quantidade, numeroRamal)) {
            cout << "Número do Ramal já está cadastrado\n";
            numeroRamal = -1; // flag para indicar que o número é inválido
        }
    } while (numeroRamal < 1000 || numeroRamal > 2999 || numeroRamal == -1);
    
    ramal.numero = numeroRamal;

    do {
        cout << "Informe o código da Categoria entre 0 e 6: ";
        cin >> ramal.categoria.codigo;
        cin.ignore();

        if (ramal.categoria.codigo < 0 || ramal.categoria.codigo > 6) {
            cout << "Código da Categoria fora do intervalo 0 até 6\n";
        }
    } while (ramal.categoria.codigo < 0 || ramal.categoria.codigo > 6);

    string categorias[] = {
        "não faz ligação",
        "ligação interna",
        "ligação local (fixo)",
        "ligação local (fixo e celular)",
        "ligação local (fixo) e DDD (fixo)",
        "ligação local (fixo e celular) e DDD (fixo e celular)",
        "ligação local (fixo e celular), DDD (fixo e celular) e DDI"
    };

    ramal.categoria.nome = categorias[ramal.categoria.codigo];
    
    do {
        cout << "Informe a descrição do Setor: ";
        getline(cin, ramal.setor.descricao);

        if (ramal.setor.descricao.empty()) {
            cout << "Descrição do Setor deve ser preenchida\n";
        }
    } while (ramal.setor.descricao.empty());

    for (auto &letra: ramal.setor.descricao) {
        letra = toupper(letra);
    }

    do {
        cout << "Informe o código da Localização (500 ou 505): ";
        cin >> ramal.localizacao.codigo;
        cin.ignore();

        if (ramal.localizacao.codigo != 500 && ramal.localizacao.codigo != 505) {
            cout << "Código da Localização diferente de 500 ou 505\n";
        }
    } while (ramal.localizacao.codigo != 500 && ramal.localizacao.codigo != 505);

    ramal.localizacao.nome = (ramal.localizacao.codigo == 500) ? "Sede" : "SEPN 505 Asa Norte";

    do {
        cout << "Informe o número do andar + o número da sala: ";
        getline(cin, ramal.sala);

        if (ramal.sala.empty()) {
            cout << "Número do andar + o número da sala deve ser preenchido\n";
        }
    } while (ramal.sala.empty());

    do {
        cout << "Informe o nome do Responsável pelo Ramal: ";
        getline(cin, ramal.responsavel);

        if (ramal.responsavel.empty()) {
            cout << "O nome do Responsável pelo Ramal deve ser preenchido\n";
        }
    } while (ramal.responsavel.empty());

    for (auto &letra: ramal.responsavel) {
        letra = toupper(letra);
    }

    do {
        cout << "Informe o nome do Responsável pelo Ateste: ";
        getline(cin, ramal.responsavelAteste);

        if (ramal.responsavelAteste.empty()) {
            cout << "O nome do Responsável pelo Ateste deve ser preenchido\n";
        }
    } while (ramal.responsavelAteste.empty());

    for (auto &letra: ramal.responsavelAteste) {
        letra = toupper(letra);
    }
}

bool verificarRamal(const Ramal *vetorRamais, int quantidade, int numeroRamal) {
    for (int i = 0; i < quantidade; i++) {
        if (vetorRamais[i].numero == numeroRamal) {
            return false; // ramal já cadastrado
        }
    }
    return true;
}

void imprimirRamal(const Ramal &ramal) {
    cout << "_____________________________________\n";
    cout << " INFORMAÇÕES GERAIS DO RAMAL \n";
    cout << "_____________________________________\n";
    cout << "Ramal                  : " << ramal.numero << "\n";
    cout << "Categoria              : " << ramal.categoria.codigo << "\n";
    cout << "Setor                  : " << ramal.setor.descricao << "\n";
    cout << "Edifício               : " << ramal.localizacao.codigo << "\n";
    cout << "Sala                   : " << ramal.sala << "\n";
    cout << "Responsável pelo ramal : " << ramal.responsavel << "\n";
    cout << "Responsável pelo ateste: " << ramal.responsavelAteste << "\n";
    cout << "\nPressione qualquer tecla para continuar. . .";
    cin.ignore();
    cin.get();
    cout << "\n============================================\n";
}
