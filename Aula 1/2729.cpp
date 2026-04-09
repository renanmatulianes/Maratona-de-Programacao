#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
 
int main() {
    
    int num_listas;
 
    cin >> num_listas;

    cin.ignore();

    for (int i = 0; i < num_listas; i++)
    {
        string linha;
        getline(cin, linha);
        stringstream ss(linha);
        string item;

        set<string> itens;

        while (ss >> item)
        {
            itens.insert(item);
        }
        
        bool primeiro = true;
        for (const string& p : itens){
            if (!primeiro) {
                cout << " "; 
            }
            cout << p;
            primeiro = false;
        }
        cout << "\n";
    }
    
 
    return 0;
}