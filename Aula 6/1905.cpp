#include <iostream>
#include <vector>

using namespace std;

int grid[5][5];
bool visited[5][5];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool dfs(int r, int c) {
    if (r == 4 && c == 4) return true;
    
    visited[r][c] = true;
    
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
    
        if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
            
            if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                if (dfs(nr, nc)) return true;
            }
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    
    if (grid[0][0] == 1 || grid[4][4] == 1) {
        cout << "ROBBERS\n";
        return;
    }
    
    if (dfs(0, 0)) {
        cout << "COPS\n";
    } else {
        cout << "ROBBERS\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}