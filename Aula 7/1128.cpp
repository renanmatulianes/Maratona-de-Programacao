#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visitado) {
    visitado[u] = true;
    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v, adj, visitado);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    
    // Lê até encontrar N = 0 e M = 0
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<vector<int>> adj(N + 1);
        vector<vector<int>> adj_reverso(N + 1);

        for (int i = 0; i < M; ++i) {
            int V, W, P;
            cin >> V >> W >> P;

            adj[V].push_back(W);
            adj_reverso[W].push_back(V);
            
            if (P == 2) {
                adj[W].push_back(V);
                adj_reverso[V].push_back(W);
            }
        }

        vector<bool> visitado(N + 1, false);
        
        dfs(1, adj, visitado);
        
        bool conectado = true;
        for (int i = 1; i <= N; ++i) {
            if (!visitado[i]) {
                conectado = false;
                break;
            }
        }

        if (conectado) {
            fill(visitado.begin(), visitado.end(), false);
            dfs(1, adj_reverso, visitado);
            
            for (int i = 1; i <= N; ++i) {
                if (!visitado[i]) {
                    conectado = false;
                    break;
                }
            }
        }

        if (conectado) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}