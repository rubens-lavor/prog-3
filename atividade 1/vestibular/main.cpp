#include <iostream>
#include <fstream>

using namespace std;

void criaLista()
{
    ofstream arquivo;

    //arquivo.open("vestibular.txt",ios::app);
    arquivo.open("vestibular.txt");

    for (int i = 1; i <= 10; i++)
    {
        string nome = "oiiii";

        arquivo << i;
        arquivo << " - ";
        arquivo << nome;
        arquivo << "\n";
    }

    arquivo.close();
}

int main()
{
    criaLista();

    ifstream arquivoEntrada;
    string linha;
    arquivoEntrada.open("vestibular.txt");
    if (arquivoEntrada.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            cout << linha << endl;
        }
    }
    else
    {
        cout << "Não foi possível abrir o arquivo" << endl;
    }

    return 0;
}