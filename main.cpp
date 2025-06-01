#include "filme.h"
#include <iostream>

extern vector<Filme> carregarFilmesDeTxt(const string& caminho); // chama a função definida no arquivo banco_dados.cpp

int main() {
    vector<Filme> filmes = carregarFilmesDeTxt("filmes.txt"); // carrega os filmes do arquivo

    for (const auto& f : filmes) { 
        // percorre o vetor de filmes (implementar o resto a partir daqui, esse output é apenas um exemplo)
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
