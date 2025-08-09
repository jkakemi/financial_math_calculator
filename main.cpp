#include "utils.h"
#include "juros_simples.h"
#include "juros_compostos.h"
#include <iostream>

using namespace std;

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
                menuJurosCompostos();
                break;
            case 3:
                cout << "Finalizando calculadora...\n";
                return 0;
            default:
                cout << "Opcao invalida... Tente novamente!\n";
                cout << "\nPressione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
        }
    }
    return 0;
}

// Como executar
// g++ main.cpp utils.cpp juros_simples.cpp juros_compostos.cpp -o output/calculadora
// .\output\calculadora