#include <bits/stdc++.h> 

using namespace std;

// Enumeracao para clareza nas unidades de tempo
enum TimeUnit {
    DIAS = 1,
    MESES = 2,
    ANOS = 3
};

// Funcoes sem parametro e retorno
void menuJurosSimples();
void menuDescontoComercial();

// Funcoes com parametrização e retorno
double obterEntradaNumerica(const string& prompt);
int obterUnidadeTempo(const string& tipo);
double converterTempo(double tempo, TimeUnit unidadeOrigem, TimeUnit unidadeDestino);
void limparTela();

// --- Juros Simples ---

// Calcula o Montante (VF) em juros simples
void calcularMontanteSimples() {
    cout << "\n--- Calcular Montante (VF) - Juros Simples ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Capital (VP), Taxa (i) e Tempo (n)\n";
    cout << "2. Juros (J), Taxa (i) e Tempo (n)\n";
    int escolha = obterEntradaNumerica("Escolha uma opcao: ");

    double vp = 0, j = 0, i = 0, n = 0;
    double vf = 0;

    if (escolha == 1) {
        vp = obterEntradaNumerica("Capital (VP) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        n = obterEntradaNumerica("Tempo (n) - ");

        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);

        vf = vp * (1 + i * n);
    } else if (escolha == 2) {
        j = obterEntradaNumerica("Juros (J) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        n = obterEntradaNumerica("Tempo (n) - ");

        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);

        if (i * n == 0) {
             cout << "Erro: Divisao por zero. Taxa ou tempo nao podem ser zero.\n";
             return;
        }
        vp = j / (i * n);
        vf = vp + j;
    } else {
        cout << "Opcao invalida.\n";
        return;
    }

    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Montante (VF) - " << vf << endl;
    cout << "----------------------------------------\n";
}

// Calcula o Capital (VP) em juros simples
void calcularCapitalSimples() {
    cout << "\n--- Calcular Capital (VP) - Juros Simples ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Montante (VF), Taxa (i) e Tempo (n)\n";
    cout << "2. Montante (VF) e Juros (J)\n";
    cout << "3. Juros (J), Taxa (i) e Tempo (n)\n";
    int escolha = obterEntradaNumerica("Escolha uma opcao: ");

    double vf = 0, j = 0, i = 0, n = 0;
    double vp = 0;

    if (escolha == 1) {
        vf = obterEntradaNumerica("Montante (VF) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        n = obterEntradaNumerica("Tempo (n) - ");

        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);

        vp = vf / (1 + i * n);

    } else if (escolha == 2) {
        vf = obterEntradaNumerica("Montante (VF) - ");
        j = obterEntradaNumerica("Juros (J) - ");
        vp = vf - j;
    } else if (escolha == 3) {
        j = obterEntradaNumerica("Juros (J) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        n = obterEntradaNumerica("Tempo (n) - ");

        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);
        
        if (i * n == 0) {
             cout << "Erro: Divisao por zero. Taxa ou tempo nao podem ser zero.\n";
             return;
        }
        vp = j / (i * n);
    } else {
        cout << "Opcao invalida.\n";
        return;
    }
    
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Capital (VP) - " << vp << endl;
    cout << "----------------------------------------\n";
}
// Calcula os Juros (J) em juros simples
void calcularJurosSimples() {
    cout << "\n--- Calcular Juros (J) - Juros Simples ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Capital (VP), Taxa (i) e Tempo (n)\n";
    cout << "2. Montante (VF) e Capital (VP)\n";
    int escolha = obterEntradaNumerica("Escolha uma opcao: ");

    double juros = 0;

    if (escolha == 1) {
        double vp = obterEntradaNumerica("Capital (VP) - ");
        double i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        double n = obterEntradaNumerica("Tempo (n) - ");

        int unidadeTaxa = obterUnidadeTempo("taxa");
        int unidadeTempo = obterUnidadeTempo("tempo");
        n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);

        juros = vp * i * n;
    } else if (escolha == 2) {
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

// Calcula a Taxa (i) em juros simples
void calcularTaxaSimples() {
    cout << "\n--- Calcular Taxa (i) - Juros Simples ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Capital (VP), Juros (J) e Tempo (n)\n";
    cout << "2. Capital (VP), Montante (VF) e Tempo (n)\n";
    int escolha = obterEntradaNumerica("Escolha uma opcao: ");
    
    double vp = 0, juros = 0, n = 0, vf = 0;
    double i = 0;
    int unidadeTempoFinal;

    if (escolha == 1) {
        vp = obterEntradaNumerica("Capital (VP) - ");
        juros = obterEntradaNumerica("Juros (J) - ");
        n = obterEntradaNumerica("Tempo (n): ");
        unidadeTempoFinal = obterUnidadeTempo("tempo para o calculo da taxa");

        if (vp * n == 0) {
            cout << "Erro: Divisao por zero. Capital ou tempo nao podem ser zero.\n";
            return;
        }
        i = juros / (vp * n);

    } else if (escolha == 2) {
        vp = obterEntradaNumerica("Capital (VP) - ");
        vf = obterEntradaNumerica("Montante (VF) - ");
        n = obterEntradaNumerica("Tempo (n) - ");
        unidadeTempoFinal = obterUnidadeTempo("tempo para o calculo da taxa");

        if (vp * n == 0) {
            cout << "Erro: Divisao por zero. Capital ou tempo nao podem ser zero.\n";
            return;
        }
        i = ((vf / vp) - 1) / n;

    } else {
        cout << "Opcao invalida.\n";
        return;
    }

    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(4);
    cout << "Resultado:\n";
    cout << "Taxa (i) - " << i * 100 << "% a." << (unidadeTempoFinal == DIAS ? "d." : unidadeTempoFinal == MESES ? "m." : "a.") << endl;
    cout << "----------------------------------------\n";
}

// Calcula o Tempo (n) em juros simples
void calcularTempoSimples() {
    cout << "\n--- Calcular Tempo (n) - Juros Simples ---\n";
    cout << "Qual conjunto de dados voce possui?\n";
    cout << "1. Capital (VP), Juros (J) e Taxa (i)\n";
    cout << "2. Capital (VP), Montante (VF) e Taxa (i)\n";
    int escolha = obterEntradaNumerica("Escolha uma opcao: ");
    
    double vp = 0, juros = 0, i = 0, vf = 0;
    double n = 0;
    int unidadeTaxa;

    if (escolha == 1) {
        vp = obterEntradaNumerica("Capital (VP) - ");
        juros = obterEntradaNumerica("Juros (J) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        unidadeTaxa = obterUnidadeTempo("taxa");

        if (vp * i == 0) {
            cout << "Erro: Divisao por zero. Capital ou taxa nao podem ser zero.\n";
            return;
        }
        n = juros / (vp * i);
    } else if (escolha == 2) {
        vp = obterEntradaNumerica("Capital (VP) - ");
        vf = obterEntradaNumerica("Montante (VF) - ");
        i = obterEntradaNumerica("Taxa (i) em decimal (ex: 0.05 para 5%) - ");
        unidadeTaxa = obterUnidadeTempo("taxa");
        
        if (vp * i == 0) {
            cout << "Erro: Divisao por zero. Capital ou taxa nao podem ser zero.\n";
            return;
        }
        n = ((vf / vp) - 1) / i;
    } else {
        cout << "Opcao invalida.\n";
        return;
    }

    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Resultado:\n";
    cout << "Tempo (n) - " << n << " periodo(s) (na mesma unidade da taxa: " << (unidadeTaxa == DIAS ? "dias" : unidadeTaxa == MESES ? "meses" : "anos") << ")." << endl;
    cout << "----------------------------------------\n";
}


// --- Desconto Comercial ---
void calcularTaxaEfetiva() {
    cout << "\n--- Calcular Taxa Efetiva (i) a partir da Comercial (ic) ---\n";
    double ic = obterEntradaNumerica("ic - ");
    double n = obterEntradaNumerica("n - ");

    int unidadeTaxa = obterUnidadeTempo("taxa comercial");
    int unidadeTempo = obterUnidadeTempo("tempo");
    n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);
    
    if (1 - (ic * n) == 0) {
        cout << "Erro: Divisao por zero. A combinacao de taxa e tempo resulta em um denominador zero.\n";
        return;
    }
    double i = ic / (1 - (ic * n));

    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(4);
    cout << "Resultado:\n";
    cout << "Taxa efetiva (i) equivalente - " << i * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

void calcularTaxaComercial() {
    cout << "\n--- Calcular Taxa Comercial (ic) a partir da Efetiva (i) ---\n";
    double i = obterEntradaNumerica("i - ");
    double n = obterEntradaNumerica("n - ");
    
    int unidadeTaxa = obterUnidadeTempo("taxa efetiva");
    int unidadeTempo = obterUnidadeTempo("tempo");
    n = converterTempo(n, (TimeUnit)unidadeTempo, (TimeUnit)unidadeTaxa);

    double ic = i / (1 + (i * n));

    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(4);
    cout << "Resultado:\n";
    cout << "Taxa de desconto comercial (ic) - " << ic * 100 << "%" << endl;
    cout << "----------------------------------------\n";
}

// --- Funções de Menu ---

void menuJurosSimples() {
    int escolha;
    while (true) {
        limparTela();
        cout << "===== Calculadora Financeira - Juros Simples =====\n";
        cout << "1. Calcular Montante (VF)\n";
        cout << "2. Calcular Capital (VP)\n";
        cout << "3. Calcular Juros (J)\n";
        cout << "4. Calcular Taxa (i)\n";
        cout << "5. Calcular Tempo (n)\n";
        cout << "6. Conversao de Taxas de Desconto\n";
        cout << "7. Voltar ao Menu Principal\n";
        cout << "===================================================\n";
        
        escolha = obterEntradaNumerica("Escolha uma opcao: ");

        switch (escolha) {
            case 1: calcularMontanteSimples(); break;
            case 2: calcularCapitalSimples(); break;
            case 3: calcularJurosSimples(); break;
            case 4: calcularTaxaSimples(); break;
            case 5: calcularTempoSimples(); break;
            case 6: menuDescontoComercial(); break;
            case 7: return;
            default: cout << "Opcao invalida. Tente novamente.\n"; break;
        }
        cout << "\nPressione Enter para continuar...";
        cin.get();
    }
}

void menuDescontoComercial() {
    int escolha;
    while (true) {
        limparTela();
        cout << "===== Conversao de Taxas de Desconto (Simples) =====\n";
        cout << "1. Calcular Taxa Efetiva (i) a partir da Comercial (ic)\n";
        cout << "2. Calcular Taxa Comercial (ic) a partir da Efetiva (i)\n";
        cout << "3. Voltar\n";
        cout << "====================================================\n";

        escolha = obterEntradaNumerica("Escolha uma opcao: ");

        switch (escolha) {
            case 1: calcularTaxaEfetiva(); break;
            case 2: calcularTaxaComercial(); break;
            case 3: return;
            default: cout << "Opcao invalida. Tente novamente.\n"; break;
        }
        cout << "\nPressione Enter para continuar...";
        cin.get();
    }
}

// --- Funcao Principal ---

int main() {
    int escolha;
    while (true) {
        limparTela();
        cout << "======== Calculadora Financeira ========\n";
        cout << "Selecione:\n";
        cout << "1. Juros Simples\n";
        cout << "2. Juros Compostos\n";
        cout << "3. Sair\n";
        cout << "========================================\n";
        
        escolha = obterEntradaNumerica("Escolha uma opcao: ");

        switch (escolha) {
            case 1:
                menuJurosSimples();
                break;
            case 2:
                cout << "Nao implementado juros compostos ainda\n";
                break;
            case 3:
                cout << "Finalizando calculadora...\n";
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                cout << "\nPressione Enter para continuar...";
                cin.get();
                break;
        }
    }
    return 0;
}


// --- Funcoes de utilidade e performance geral ---

// Obtem entrada numerica do usuário (mais performance)
double obterEntradaNumerica(const string& prompt) {
    double valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "Entrada invalida. Por favor, insira um numero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Qual sera a unidade de tempo do usuário
int obterUnidadeTempo(const string& tipo) {
    int unidade;
    while (true) {
        cout << "Qual a unidade de tempo da " << tipo << "? (1-Dias, 2-Meses, 3-Anos): ";
        cin >> unidade;
        if (cin.good() && (unidade >= 1 && unidade <= 3)) {
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return unidade;
        }
        cout << "Unidade invalida. Tente novamente.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Converte o tempo de uma unidade para outra
// Usando exemplo do conversor de moedas
// Usa o ano comercial (360 dias) e mês comercial (30 dias)
double converterTempo(double tempo, TimeUnit unidadeOrigem, TimeUnit unidadeDestino) {
    if (unidadeOrigem == unidadeDestino) {
        return tempo;
    }

    double tempoEmDias;
    switch (unidadeOrigem) {
        case DIAS: tempoEmDias = tempo; break;
        case MESES: tempoEmDias = tempo * 30.0; break;
        case ANOS: tempoEmDias = tempo * 360.0; break;
    }

    double tempoFinal;
    switch (unidadeDestino) {
        case DIAS: tempoFinal = tempoEmDias; break;
        case MESES: tempoFinal = tempoEmDias / 30.0; break;
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