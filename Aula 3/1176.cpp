#include <iostream>

using namespace std;

unsigned long long fib(int n, unsigned long long dp[]){
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else return fib(n-1, dp) + fib(n-2, dp);
}

int main(){

    unsigned long long dp[61];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 61; i++) dp[i] = -1;

    int numTestes;
    cin >> numTestes;

    int testes[numTestes];

    for (int i = 0; i < numTestes; i++)
    {
        cin >> testes[i];
    }
    
    for (int i = 0; i < numTestes; i++)
    {
        int n = testes[i];
        unsigned long long fib_n = fib(n, dp);
        cout << "Fib(" << n << ") = " << fib_n << "\n";
        dp[n] = fib_n;
    }

    return 0;
}
