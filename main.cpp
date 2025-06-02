#include "filme.h"
#include <iostream>
#include <optional>
#include <vector>
#include <sstream>

using namespace std;

// Declaração das funções externas
extern vector<Filme> carregarFilmesDeTxt(const string& caminho);
extern vector<Filme> filtrarFilmes(
    const vector<Filme>& filmes,
    const optional<vector<string>> generosDesejados = nullopt,
    const optional<int> classificacaoMaxima = nullopt,
    const optional<float> avaliacaoMinima = nullopt,
    const optional<string> estiloDesejado = nullopt,
    const optional<float> anoMinimo = nullopt
);

vector<string> dividirPorVirgulas(const string& entrada) {
    vector<string> resultado;
    stringstream ss(entrada);
    string item;

    while (getline(ss, item, ',')) {
        size_t start = item.find_first_not_of(" \t");
        size_t end = item.find_last_not_of(" \t");
        if (start != string::npos && end != string::npos)
            resultado.push_back(item.substr(start, end - start + 1));
    }

    return resultado;
}

int main() {
    vector<Filme> filmes = carregarFilmesDeTxt("filmes.txt"); // carrega os filmes do arquivo
    string input;
    optional<int> classificacao;
    optional<float> avaliacao;
    optional<string> estilo;
    optional<float> ano;
    optional<vector<string>> generos;

    cout << "=====================================\n";
    cout << "        BEM-VINDO AO CINESC         \n";
    cout << "=====================================\n\n";

    cout << "Vamos encontrar o filme ideal para voce!\n";
    cout << "Insira os filtros desejados abaixo.\n";
    cout << "Deixe em branco para ignorar um filtro.\n\n";

    cout << "Generos disponiveis:\n";
    cout << "----------------------------\n";
    cout << "  Acao\n  Drama\n  Comedia\n  Terror\n  Romance\n";
    cout << "  Ficcao\n  Animacao\n  Suspense\n  Documentario\n";
    cout << "  Musical\n  Aventura\n  Fantasia\n  Crime\n  Curta\n";
    cout << "----------------------------\n";
    cout << "Digite os generos de preferencia (ex: Acao, Drama): ";
   
    getline(cin, input);
    if (!input.empty()) generos = dividirPorVirgulas(input);

    cout << "\nClassificacoes etarias possiveis:\n";
    cout << "----------------------------\n";
    cout << "  0  - Livre\n";
    cout << " 10  - A partir de 10 anos\n";
    cout << " 12  - A partir de 12 anos\n";
    cout << " 14  - A partir de 14 anos\n";
    cout << " 16  - A partir de 16 anos\n";
    cout << " 18  - A partir de 18 anos\n";
    cout << "----------------------------\n";
    cout << "Classificacao etaria maxima: ";
    
    getline(cin, input);
    if (!input.empty()) classificacao = stoi(input);

    cout << "\nAvaliacao minima (entre 4.0 e 5.0): ";
    getline(cin, input);
    if (!input.empty()) avaliacao = stof(input);

    cout << "\nEstilos disponiveis:\n";
    cout << "----------------------------\n";
    cout << "  Longa-metragem\n  Curta-metragem\n  Serie\n";
    cout << "----------------------------\n";
    cout << "Estilo: ";

    getline(cin, input);
    if (!input.empty()) estilo = input;

    cout << "\nAno minimo de lancamento (entre 1972 e 2023): ";
    getline(cin, input);
    if (!input.empty()) ano = stof(input);

    vector<Filme> filmesFiltrados = filtrarFilmes(filmes, generos, classificacao, avaliacao, estilo, ano);

    for (const auto& f : filmesFiltrados) {
        cout << "\n=====================================\n";
        cout << "TITULO: " << f.nome << "\n";
        cout << "-------------------------------------\n";

        cout << "GENEROS: ";
        for (size_t i = 0; i < f.generos.size(); ++i) {
            cout << f.generos[i];
            if (i < f.generos.size() - 1) cout << " | ";
        }
        cout << "\n";

        cout << "AVALIACAO: " << f.avaliacao << " / 5.0\n";
        cout << "ANO: " << f.ano_lancamento << "\n";
        cout << "CLASSIFICACAO ETARIA: " << f.classificacao_etaria << "+\n";

        cout << "ELENCO: ";
        for (size_t i = 0; i < f.elenco.size(); ++i) {
            cout << f.elenco[i];
            if (i < f.elenco.size() - 1) cout << ", ";
        }
        cout << "\n";

        cout << "SINOPSE: " << f.sinopse << "\n";
        cout << "ESTILO: " << f.estilo << "\n";
        cout << "=====================================\n";
    }

    return 0;
}
