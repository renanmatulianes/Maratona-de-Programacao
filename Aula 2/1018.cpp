#include <iostream>

using namespace std;

int main(){

    int valor;

    cin >> valor;

    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    cout << valor << "\n";

    for (int i = 0; i < 7; i++)
    {
        int qtd_notas;
        qtd_notas = valor / notas[i];
        valor %= notas[i];

        cout << qtd_notas << " nota(s) de R$ " << notas[i] << ",00\n";
    }
    

    return 0;
}