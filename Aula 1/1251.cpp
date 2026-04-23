#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second; 
    }
    return a.first > b.first;       
}

int main() {
    string linha;
    bool primeiraLinha = true;

    while (getline(cin, linha)) {
        if (!primeiraLinha) cout << endl;
        primeiraLinha = false;

        map<int, int> frequencia;

        for (char c : linha) {
            frequencia[(int)c]++;
        }

        vector<pair<int, int>> lista;
        for (auto const& [ascii, qtd] : frequencia) {
            lista.push_back({ascii, qtd});
        }

        sort(lista.begin(), lista.end(), comparar);

        for (auto const& p : lista) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}