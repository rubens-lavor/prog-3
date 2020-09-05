#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int numero_aleatorio(int max,int min){
    uniform_int_distribution<int> randomDist(min, max);
    random_device rd;
    mt19937 randomNumbers(rd());
    return randomDist(randomNumbers);
}

void criaLista()
{
    ofstream arquivo; //inserção no arquivo

    //arquivo.open("vestibular.txt",ios::app);
    arquivo.open("vestibular.txt");

    arquivo << "nº inscrição   |  Idade | Pontuação | Curso Pretendido";
    arquivo << "\n";

    for (int i = 1; i <= 10; i++)
    {
        int registro = i;
        int idade = numero_aleatorio(30,17);
        int pontuacao = numero_aleatorio(5000,0);
        int curso = numero_aleatorio(6,1);

        arquivo << "\t ";
        arquivo << registro << " " <<i;
        arquivo << "\t- ";
        arquivo << idade;
        arquivo << " \t ";
        arquivo << pontuacao;
        arquivo << "\t\tcurso ";
        arquivo << curso;
        arquivo << "\n";
    }

    arquivo.close();
}

int main()
{
    criaLista();

    ifstream arquivoEntrada; //lê o arquivo
    string linha;
    arquivoEntrada.open("vestibular.txt");
    if (arquivoEntrada.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            cout << linha << endl;
        }
        arquivoEntrada.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo" << endl;
    }

    return 0;
}