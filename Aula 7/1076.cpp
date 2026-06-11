#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int N, V, A;
        cin >> N;
        cin >> V >> A;
        
        set<pair<int, int>> arestas_unicas;
        
        for (int i = 0; i < A; i++) {
            int u, v;
            cin >> u >> v;
            
            if (u > v) swap(u, v);
            arestas_unicas.insert({u, v});
        }
        
        cout << arestas_unicas.size() * 2 << endl;
    }
    
    return 0;
}