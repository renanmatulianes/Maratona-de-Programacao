#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> impares;
    vector<int> pares;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2 == 0){
            pares.push_back(num);
        }
        else{
            impares.push_back(num);
        }
    }
    
    sort(impares.rbegin(), impares.rend());
    sort(pares.begin(), pares.end());

    for (int i = 0; i < pares.size(); i++)
    {
        cout << pares[i] << "\n";
    }
    for (int i = 0; i < impares.size(); i++)
    {
        cout << impares[i] << "\n";
    }
    

    return 0;
}