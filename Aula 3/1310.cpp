#include <iostream>

using namespace std;

// Vetor com n posições onde v[i] é o lucro gerado no dia i
// custo da diária é denotado por cd
// Lucro liquido: v[i] - cd denotado por L, sendo L[i] o lucro liquido do dia i
// Proposta algoritmo: qual o lucro liquido máximo de uma serie consecutiva de dias que termina no dia i?
// Então, dp(i) = max{dp(i-1) + L[i], L[i]}

int solucao(int dia, int lucros_liquidos[], int dp[], bool dpFilled[]){
    if (dpFilled[dia]) return dp[dia];

    int result = max(solucao(dia-1, lucros_liquidos, dp, dpFilled) + lucros_liquidos[dia], lucros_liquidos[dia]);
    dp[dia] = result;
    dpFilled[dia] = true;

    return result;
}

int main(){

    int numDias;

    while (cin >> numDias)
    {
        int custoDiaria;
        cin >> custoDiaria;

        int lucros_liquidos[numDias];

        for (int i = 0; i < numDias; i++)
        {
            cin >> lucros_liquidos[i];
            lucros_liquidos[i] -= custoDiaria;
        }
        
        int dp[numDias];
        bool dpFilled[numDias];
        for (int i = 0; i < numDias; i++) dpFilled[i] = false;
        dp[0] = lucros_liquidos[0];
        dpFilled[0] = true;

        solucao(numDias-1, lucros_liquidos, dp, dpFilled);

        int max = 0;
        for (int i = 0; i < numDias; i++){
            if (dp[i] > max)
                max = dp[i];
        }

        cout << max << "\n";
    }
    

    return 0;
}