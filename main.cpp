#include "filme.h"
#include <iostream>
#include <optional>
#include <vector>

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

int main() {
    vector<Filme> filmes = carregarFilmesDeTxt("filmes.txt"); // carrega os filmes do arquivo

    // Exemplo de uso da função filtrarFilmes
    optional<vector<string>> generos = vector<string>{"Acao", "Drama"};
    optional<int> classificacao = 16;
    optional<float> avaliacao = 4.5f;
    optional<string> estilo = "Longa-metragem";
    optional<float> ano = 2000;

    vector<Filme> filmesFiltrados = filtrarFilmes(filmes, generos, classificacao, avaliacao, estilo, ano);

    // Imprimir os filmes filtrados (mantendo exatamente sua sintaxe)
    for (const auto& f : filmesFiltrados) {
        cout << "\nTitulo: " << f.nome;
        cout << "\nGeneros: ";
        for (const auto& g : f.generos) cout << g << " ";
        cout << "\nAvaliacao: " << f.avaliacao;
        cout << "\nAno: " << f.ano_lancamento;
        cout << "\nClassificacao: " << f.classificacao_etaria;
        cout << "\nElenco: ";
        for (const auto& e : f.elenco) cout << e << ", ";
        cout << "\nSinopse: " << f.sinopse;
        cout << "\nEstilo: " << f.estilo << endl;
    }

    return 0;
}