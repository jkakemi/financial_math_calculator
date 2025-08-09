#pragma once
#include <string>

enum TimeUnit {
    DIAS = 1,
    MESES = 2,
    BIMESTRES = 3,
    TRIMESTRES = 4,
    QUADRIMESTRES = 5,
    SEMESTRES = 6,     
    ANOS = 7         
};

double obterEntradaNumerica(const std::string& prompt);
int obterUnidadeTempo(const std::string& tipo);
double converterTempo(double tempo, TimeUnit unidadeOrigem, TimeUnit unidadeDestino);
void limparTela();