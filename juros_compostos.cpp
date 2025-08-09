#include "juros_compostos.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void calcularMontanteComposto();
void calcularCapitalComposto();
void calcularJurosComposto();
void calcularTaxaComposta();
void calcularTempoComposto();
void menuConversaoTaxasCompostas();
void calcularTaxaProporcional();
void calcularTaxaNominal();
void calcularTaxasEquivalentes();

void calcularMontanteComposto() {
    cout << "\n--- Calcular Montante (VF) - Juros Compostos ---\n";
    double vp = obterEntradaNumerica("Capital (VP) - ");
    double i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
    double n = obterEntradaNumerica("Tempo (n) - ");
    int unidadeTaxa = obterUnidadeTempo("taxa");
    int unidadeTempo = obterUnidadeTempo("tempo");
    n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);
    double vf = vp * pow((1 + i), n);
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Montante (VF) - " << vf << endl;
    cout << "----------------------------------------\n";
}

void calcularCapitalComposto() {
    cout << "\n--- Calcular Capital (VP) - Juros Compostos ---\n";
    double vf = obterEntradaNumerica("Montante (VF) - ");
    double i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
    double n = obterEntradaNumerica("Tempo (n) - ");
    int unidadeTaxa = obterUnidadeTempo("taxa");
    int unidadeTempo = obterUnidadeTempo("tempo");
    n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);
    if (pow((1 + i), n) == 0) {
        cout << "Nao pode divisao por zero!\n";
        return;
    }
    double vp = vf / pow((1 + i), n);
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Capital (VP) - " << vp << endl;
    cout << "----------------------------------------\n";
}

void calcularJurosComposto() {
    cout << "\n--- Calcular Juros (J) - Juros Compostos ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Capital (VP), Taxa (i) e Tempo (n)\n";
    cout << "2. Montante (VF) e Capital (VP)\n";
    int op = obterEntradaNumerica("Escolha uma opcao: ");

    double juros = 0;

    if (op == 1) {
        double vp = obterEntradaNumerica("Capital (VP) - ");
        double i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        double n = obterEntradaNumerica("Tempo (n) - ");
        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);
        double vf = vp * pow((1 + i), n);
        juros = vf - vp;
    } else if (op == 2) {
        double vf = obterEntradaNumerica("Montante (VF) - ");
        double vp = obterEntradaNumerica("Capital (VP) - ");
        juros = vf - vp;
    } else {
        cout << "Opcao invalida.\n";
        return;
    }
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Juros (J) - " << juros << endl;
    cout << "----------------------------------------\n";
}

void calcularTaxaComposta() {
    cout << "\n--- Calcular Taxa (i) - Juros Compostos ---\n";
    double vp = obterEntradaNumerica("Capital (VP) - ");
    double vf = obterEntradaNumerica("Montante (VF) - ");
    double n = obterEntradaNumerica("Tempo (n) - ");
    if (vp <= 0 || n == 0) {
        cout << "Capital negativo e tempo zero nao pode!\n";
        return;
    }
    double i = pow((vf / vp), (1.0 / n)) - 1;
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Taxa (i) por periodo - " << i * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

void calcularTempoComposto() {
    cout << "\n--- Calcular Tempo (n) - Juros Compostos ---\n";
    double vp = obterEntradaNumerica("Capital (VP) - ");
    double vf = obterEntradaNumerica("Montante (VF) - ");
    double i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
    if (vp <= 0 || vf <= 0 || i <= -1 || log(1 + i) == 0) {
        cout << "Erro: Valores invalidos. VP e VF devem ser positivos, taxa > -100% e nao pode ser 0.\n";
        return;
    }
    double n = log(vf / vp) / log(1 + i);
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Tempo (n) - " << n << " periodo(s) (na mesma unidade da taxa)." << endl;
    cout << "----------------------------------------\n";
}

void calcularTaxaProporcional() {
    cout << "\n--- Calcular Taxa Proporcional (Efetiva a partir da Nominal) ---\n";
    double k = obterEntradaNumerica("i (k nominal) em decimal (ex: 0.12 para 12%) - ");
    //cout << "Unidade da taxa nominal:" << endl;
    int unidadeNominal = obterUnidadeTempo("taxa nominal");
    //cout << "Unidade da taxa proporcional:" << endl;
    int unidadeProporcional = obterUnidadeTempo("taxa proporcional");
    double fator = converterTempo(1.0, (TimeUnit)unidadeNominal, (TimeUnit)unidadeProporcional);
    if (fator == 0) {
        cout << "Nao foi possivel converter as unidades!\n";
        return;
    }
    double i_prop = k / fator;
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "i proporcional (efetiva) - " << i_prop * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

void calcularTaxaNominal() {
    cout << "\n--- Calcular Taxa Nominal (a partir da Efetiva/Proporcional) ---\n";
    double i_prop = obterEntradaNumerica("i proporcional (efetiva) em decimal (ex: 0.01 para 1%) - ");
    //cout << "Unidade da taxa proporcional:" << endl;
    int unidadeProporcional = obterUnidadeTempo("taxa proporcional");
    //cout << "Unidade da taxa nominal desejada:" << endl;
    int unidadeNominal = obterUnidadeTempo("taxa nominal");
    double fator = converterTempo(1.0, (TimeUnit)unidadeNominal, (TimeUnit)unidadeProporcional);
     if (fator == 0) {
        cout << "Nao foi possivel converter as unidades!\n";
        return;
    }
    double k = i_prop * fator;
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "i (k nominal) - " << k * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

void calcularTaxasEquivalentes() {
    cout << "\n--- Calcular Taxas Equivalentes ---\n";
    double i_conhecida = obterEntradaNumerica("Taxa conhecida (i) em decimal (ex: 0.01 para 1%) - ");
    //cout << "Unidade da taxa conhecida:" << endl;
    int unidadeOrigem = obterUnidadeTempo("taxa conhecida");
    //cout << "Unidade da taxa equivalente desejada:" << endl;
    int unidadeDestino = obterUnidadeTempo("taxa equivalente");

    if(unidadeOrigem < unidadeDestino){
        cout << "Tempo menor p/ maior.\n";
    }
    else if(unidadeOrigem > unidadeDestino){
        cout << " Tempo maior p/ menor.\n";
    }

    double expoente = converterTempo(1.0, (TimeUnit)unidadeDestino, (TimeUnit)unidadeOrigem);
    double i_equiv = pow(1 + i_conhecida, expoente) - 1;
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "i efetiva no periodo solicitado/equivalente - " << i_equiv * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

void menuJurosCompostos() {
    int escolha;
    while (true) {
        limparTela();
        cout << "===== Calculadora Financeira - Juros Compostos =====\n";
        cout << "1. Calcular Montante (VF)\n";
        cout << "2. Calcular Capital (VP)\n";
        cout << "3. Calcular Juros (J)\n";
        cout << "4. Calcular Taxa (i)\n";
        cout << "5. Calcular Tempo (n)\n";
        cout << "6. Conversao de Taxas\n";
        cout << "7. Voltar ao Menu Principal\n";
        cout << "====================================================\n";
        escolha = obterEntradaNumerica("Escolha uma opcao: ");

        switch (escolha) {
            case 1: calcularMontanteComposto(); break;
            case 2: calcularCapitalComposto(); break;
            case 3: calcularJurosComposto(); break;
            case 4: calcularTaxaComposta(); break;
            case 5: calcularTempoComposto(); break;
            case 6: menuConversaoTaxasCompostas(); break;
            case 7: return;
            default: cout << "Opcao invalida... Tente novamente!\n"; break;
        }
        cout << "\nPressione Enter para continuar...";
        cin.get();
    }
}

void menuConversaoTaxasCompostas() {
    int escolha;
    while (true) {
        limparTela();
        cout << "========== Conversao de Taxas (Compostas) ==========\n";
        cout << "1. Calcular Taxa Proporcional (de Nominal p/ Efetiva)\n";
        cout << "2. Calcular Taxa Nominal (de Efetiva p/ Nominal)\n";
        cout << "3. Calcular Taxas Equivalentes\n";
        cout << "4. Voltar\n";
        cout << "====================================================\n";
        escolha = obterEntradaNumerica("Escolha uma opcao: ");

        switch (escolha) {
            case 1: calcularTaxaProporcional(); break;
            case 2: calcularTaxaNominal(); break;
            case 3: calcularTaxasEquivalentes(); break;
            case 4: return;
            default: cout << "Opcao invalida... Tente novamente!\n"; break;
        }
        cout << "\nPressione Enter para continuar...";
        cin.get();
    }
}