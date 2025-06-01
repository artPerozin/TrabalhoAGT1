#include "filme.h"
#include <optional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<Filme> filtrarFilmes(

    const vector<Filme>& filmes,
    const optional<vector<string>> generosDesejados = nullopt,
    const optional<int> classificacaoMaxima = nullopt,
    const optional<float> avaliacaoMinima = nullopt,
    const optional<string> estiloDesejado = nullopt,
    const optional<float> anoMinimo = nullopt

){
    vector<Filme> filmesFiltrados;
    // Fazer verificação com ifs e if (categoria.has_value()) [da biblioteca optional]
    // Pegar inspiração no codigo do main ;)
    // Caso passe por todos os filtros, dar pushback de f em filmesFiltrados
    // sortar os 5 filmes com maior avaliação dentre os filmesFiltrados

    for (const Filme& f : filmes) {
        if (generosDesejados.has_value()) {
            bool encontrouGenero = false;
            for (const string& g : f.generos) {
                if (find(generosDesejados->begin(), generosDesejados->end(), g) != generosDesejados->end()) {
                    encontrouGenero = true;
                    break;
                }
            }
            if (!encontrouGenero) {
                continue;
            }
        }

        if (classificacaoMaxima.has_value() && f.classificacao_etaria > classificacaoMaxima.value()) {
            continue;
        }
        if (avaliacaoMinima.has_value() && f.avaliacao < avaliacaoMinima.value()) {
            continue;
        }
        if (estiloDesejado.has_value() && f.estilo != estiloDesejado.value()) {
            continue;
        }
        if (anoMinimo.has_value() && f.ano_lancamento < anoMinimo.value()) {
            continue;
        }
        
        filmesFiltrados.push_back(f);
    }

    sort(filmesFiltrados.begin(), filmesFiltrados.end(), [](const Filme& a, const Filme& b) {
        return a.avaliacao > b.avaliacao;
    });

    if (filmesFiltrados.size() > 5) {
        filmesFiltrados.resize(5);
    }

    return filmesFiltrados;
};
