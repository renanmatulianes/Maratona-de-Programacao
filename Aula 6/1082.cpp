#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<char>& comp) {
    visited[u] = true;
    comp.push_back(u + 'a');
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, comp);
        }
    }
}

void solve(int case_num) {
    int V, E;
    if (!(cin >> V >> E)) return;
    
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        char u, v;
        cin >> u >> v;
        int u_idx = u - 'a';
        int v_idx = v - 'a';
        adj[u_idx].push_back(v_idx);
        adj[v_idx].push_back(u_idx);
    }
    
    vector<bool> visited(V, false);
    int comp_count = 0;
    
    cout << "Case #" << case_num << ":\n";
    
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            comp_count++;
            vector<char> comp;
            
            dfs(i, adj, visited, comp);
            
            sort(comp.begin(), comp.end());
            
            for (char c : comp) {
                cout << c << ",";
            }
            cout << "\n";
        }
    }

    cout << comp_count << " connected components\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    if (cin >> N) {
        for (int i = 1; i <= N; ++i) {
            solve(i);
        }
    }
    return 0;
}