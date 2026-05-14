#include <iostream>
#include <vector>

using namespace std;

struct Pedido{
    int tempo;
    int numPizzas;
};

// Sendo C a quantidade máxima de pizzas que Roberto pode levar,
// W o vetor com a quantidade de pizzas de cada pedido
// T o vetor com o tempo necessario para entregar cada pedido
// Deseja-se maximizar o tempo
// i seria o i-esimo pedido, sendo que os pedidos estao ordenados pela quantidade de pizzas
// Relação de recorrência: T(C, i) = Se W[i] > C: T(C, i-1)
//                                   Se não,      max{T(C - W[i], i-1) + T[i], T(C, i-1)}

int sol(vector<Pedido> &pedidos, int dp[21][31], int c, int i){
    if (i < 0) return 0;

    if (dp[i][c] != -1)
    {
        return dp[i][c];
    }
    
    if (pedidos[i].numPizzas > c)
    {
        int result = sol(pedidos, dp, c, i-1);
        dp[i][c] = result;
        return result;
    }
    else
    {
        int result = max(sol(pedidos, dp, c - pedidos[i].numPizzas, i-1) + pedidos[i].tempo,
                         sol(pedidos, dp, c, i-1));
        dp[i][c] = result;
        return result;
    }
    
}

int main(){

    int numPedidos;

    while (cin >> numPedidos && numPedidos != 0)
    {
        int capacidade;
        cin >> capacidade;

        vector<Pedido> pedidos;

        for (int i = 0; i < numPedidos; i++)
        {
            Pedido pedido;
            cin >> pedido.tempo >> pedido.numPizzas;
            pedidos.push_back(pedido);
        }
        
        int dp[21][31];

        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                dp[i][j] = -1;
            }
        }   

        for (int i = 0; i < numPedidos+1; i++)
        {
            dp[i][0] = 0;
        }
        
        int result = sol(pedidos, dp, capacidade, numPedidos-1);
        cout << result << " min.\n";
    }
    

    return 0;
}