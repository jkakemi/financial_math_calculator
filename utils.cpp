#include "utils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

double obterEntradaNumerica(const string& prompt) {
    double valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "Entrada invalida! Por favor, insira um numero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int obterUnidadeTempo(const string& tipo) {
    int unidade;
    while (true) {
        cout << "Qual a unidade de tempo da " << tipo << "?\n";
        cout << "(1-Dias | 2-Meses | 3-Bimestres | 4-Trimestres | 5-Quadrimestres | 6-Semestres | 7-Anos): ";
        cin >> unidade;
        if (cin.good() && (unidade >= 1 && unidade <= 7)) {
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return unidade;
        }
        cout << "Unidade invalida... Tente novamente!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Converte o tempo de uma unidade para outra
// Usa o ano comercial (360 dias) e mês comercial (30 dias)
double converterTempo(double tempo, TimeUnit unidadeOrigem, TimeUnit unidadeDestino) {
    if (unidadeOrigem == unidadeDestino) {
        return tempo;
    }

    double tempoEmDias;
    switch (unidadeOrigem) {
        case DIAS: tempoEmDias = tempo; break;
        case MESES: tempoEmDias = tempo * 30.0; break;
        case BIMESTRES: tempoEmDias = tempo * 60.0; break;
        case TRIMESTRES: tempoEmDias = tempo * 90.0; break;
        case QUADRIMESTRES: tempoEmDias = tempo * 120.0; break;
        case SEMESTRES: tempoEmDias = tempo * 180.0; break;
        case ANOS: tempoEmDias = tempo * 360.0; break;
    }

    double tempoFinal;
    switch (unidadeDestino) {
        case DIAS: tempoFinal = tempoEmDias; break;
        case MESES: tempoFinal = tempoEmDias / 30.0; break;
        case BIMESTRES: tempoFinal = tempoEmDias / 60.0; break;
        case TRIMESTRES: tempoFinal = tempoEmDias / 90.0; break;
        case QUADRIMESTRES: tempoFinal = tempoEmDias / 120.0; break;
        case SEMESTRES: tempoFinal = tempoEmDias / 180.0; break;
        case ANOS: tempoFinal = tempoEmDias / 360.0; break;
    }

    return tempoFinal;
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}