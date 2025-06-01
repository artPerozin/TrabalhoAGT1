#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
using namespace std;

struct Filme {
    string nome;
    vector<string> generos;
    float avaliacao;
    int ano_lancamento;
    int classificacao_etaria;
    vector<string> elenco;
    string sinopse;
    string estilo;
};

#endif
