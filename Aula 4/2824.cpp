#include <iostream>

using namespace std;

// tamanho da maior subsquencia entre duas strings
// ex: axbxc e
//     zazbzcz
// estado: T(i, j) representa o tamanho da maior subsequencia entre duas string s e t, considerando
// todos os caracteres até s[i] e até t[j].
// relação de recorrencia: T(i, j) = se s[i] == t[j], T(i-1, j-1) + 1
//                                   se não,          max{T(i-1, j), T(i, j-1)}

//   z a z b z c z
// a 0 1 1 1 1 1 1
// x 0 1 1 1 1 1 1
// b 0 1 1 2 2 2 2
// x 0 1 1 2 2 2 2
// c 0 1 1 2 2 3 3

int dp[5000][5000];

int sol(string &s, string &t, int i, int j){
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1) return dp[i][j];
    
    if (s[i] == t[j])
    {
        int result = sol(s, t, i-1, j-1) + 1;
        dp[i][j] = result;
        return result;
    }
    else
    {
        int result = max(sol(s, t, i-1, j), sol(s, t, i, j-1));
        dp[i][j] = result;
        return result;
    }
    
}

int main(){

    string s, t;
    cin >> s;
    cin >> t;

    for (int i = 0; i < 5000; i++)
    {
        for (int j = 0; j < 5000; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    
    cout << sol(s, t, s.size() - 1, t.size() - 1) << "\n";

    return 0;
}