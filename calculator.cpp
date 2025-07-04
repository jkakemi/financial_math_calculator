#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long ll;

void capitalFunction(){

}

void montanteFunction(){

}

void jurosFunction(){

}

void taxaFunction(){

} 

void tempoFunction(){
    
}

void menu(){
    cout << "-----------------\n";
    cout << "1. Capital (VP)\n"; 
    cout << "2. Montante (VF)\n";
    cout << "3. Juros (J)\n";
    cout << "4. Taxa (i)\n";
    cout << "5. Tempo (n)\n";
    cout << "0. Sair\n";
    cout << "-----------------\n";
} 

int main() {
    
    int op;
    bool flag = true;
    while(flag){
        menu();
        cin >> op;
        if(op == 1){
            capitalFunction();
        }
        else if(op == 5){
            cout << "Finalizando calculadora...\n";
            flag = false;
        }
    }

    return 0;
}