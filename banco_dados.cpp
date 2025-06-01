#include "filme.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<Filme> carregarFilmesDeTxt(const string& caminho) {
    ifstream arq(caminho);
    string linha;
    vector<Filme> filmes;

    while (getline(arq, linha)) {
        stringstream ss(linha);
        string nome, generosStr, avaliacaoStr, anoStr, classEtariaStr, elencoStr, sinopse, estilo;

        getline(ss, nome, ',');
        getline(ss, generosStr, ',');
        getline(ss, avaliacaoStr, ',');
        getline(ss, anoStr, ',');
        getline(ss, classEtariaStr, ',');
        getline(ss, elencoStr, ',');
        getline(ss, sinopse, ',');
        getline(ss, estilo);

        Filme f;
        f.nome = nome;
        f.generos = split(generosStr, '|');
        f.avaliacao = stof(avaliacaoStr);
        f.ano_lancamento = stoi(anoStr);
        f.classificacao_etaria = stoi(classEtariaStr);
        f.elenco = split(elencoStr, '|');
        f.sinopse = sinopse;
        f.estilo = estilo;

        filmes.push_back(f);
    }

    return filmes;
}