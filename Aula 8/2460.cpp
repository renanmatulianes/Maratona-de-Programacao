#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> fila(n);
    for (int i = 0; i < n; ++i) {
        cin >> fila[i];
    }

    int m;
    cin >> m;

    vector<bool> saiu(100001, false);
    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        saiu[id] = true;
    }

    bool primeiro = true;
    for (int i = 0; i < n; ++i) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                cout << " ";
            }
            cout << fila[i];
            primeiro = false;
        }
    }
    cout << "\n";

    return 0;
}