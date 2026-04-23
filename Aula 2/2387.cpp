#include <iostream>

using namespace std;

struct Consulta
{
    int inicio;
    int termino;
};

bool compararConsultas(Consulta a, Consulta b){
    return a.termino < b.termino;
}


int main(){

    int num_consultas;

    cin >> num_consultas;

    Consulta consultas[num_consultas];

    for (int i = 0; i < num_consultas; i++)
    {
        cin >> consultas[i].inicio >> consultas[i].termino;
    }
    
    sort(consultas, consultas + num_consultas, compararConsultas);

    int terminoUltima = -1;
    int numMaxConsultas = 0;
    
    for (int i = 0; i < num_consultas; i++)
    {
        if (consultas[i].inicio >= terminoUltima)
        {
            numMaxConsultas++;
            terminoUltima = consultas[i].termino;
        }
        
    }
    
    cout << numMaxConsultas << "\n";

    return 0;
}