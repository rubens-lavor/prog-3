#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int numero_aleatorio(int max, int min)
{
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

    arquivo << "nº inscrição|\tIdade|\tCurso Pretendido|\tPontuação";
    arquivo << "\n";

    for (int i = 1; i <= 1; i++)
    {
        int registro = 1000 + i;
        int idade = numero_aleatorio(30, 17);
        int pontuacao = numero_aleatorio(5000, 0);
        int curso = numero_aleatorio(16, 11);

        arquivo << "\t";
        arquivo << registro;
        arquivo << "\t";
        arquivo << idade;
        arquivo << "\t\t";
        arquivo << curso;
        arquivo << "\t\t";
        arquivo << pontuacao;
        arquivo << "F";
        arquivo << "\n";
    }

    arquivo.close();
}

int main()
{
    criaLista();

    char vetor_de_busca[500]{};
    int posicao = 0;
    int caractere_por_linha = 0;
    int contra_barra = 0;

    char vetor_de_linha_e_pontuacao[2] = {};

    ifstream arquivoEntrada; //lê o arquivo
    string linha[4] = {};
    arquivoEntrada.open("vestibular.txt");
    if (arquivoEntrada.is_open())
    {
        //while (getline(arquivoEntrada, linha)){cout << linha << endl;}

        while (!arquivoEntrada.eof())
        {
            /* code */

            arquivoEntrada.get(vetor_de_busca[posicao]);

            if (vetor_de_busca[posicao] != '\n')
            {
                caractere_por_linha += 1;
                //linha=vetor_de_busca[posicao];
            }
            else
            {
                contra_barra += 1;
            }

            posicao += 1;

            //cout << linha << endl;
        }
        //vetor_de_busca[posicao + 1] = '-1';
        //while (getline(arquivoEntrada, linha)){cout << linha << endl;}
        arquivoEntrada.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo" << endl;
    }

    cout << "caracteres " << caractere_por_linha << endl;
    cout << "contra barra " << contra_barra << endl;
    cout << vetor_de_busca << endl;
    /*
    posicao = 0;
    while (vetor_de_busca[posicao] != '-1')
    {
        cout << vetor_de_busca[posicao];
        posicao += 1;
    }
    */

    for (int i = 0; i < 4; i++)
    {
        cout << vetor_de_busca[i + 68];
        linha[i] = vetor_de_busca[i + 68];
    }
    cout << endl;
    int milhar = vetor_de_busca[68] - 48;
    int centena = vetor_de_busca[69] -48;
    int dezena = vetor_de_busca[70] -48;
    int unidade = vetor_de_busca[71] -48;
    //int teste_F = vetor_de_busca[72]; ----> OK!
    int nota = 0;

    /* ok!!!

    if(vetor_de_busca[72]=='F'){
        cout << "Ok é isso aí, fim de linha" << endl;
    }
    
    */
    
    if (unidade == 70 || dezena == 70 ||centena == 70)
    {
        
        unidade = dezena;
        dezena = centena;
        centena = milhar;
        milhar = 0;
    }
    else
    {
        nota = milhar * 1000 + centena * 100 + dezena * 10 + unidade;
    }

    cout << " milhar " << milhar << endl;
    cout << " centena " << centena << endl;
    cout << " dezena " << dezena << endl;
    cout << " unidade " << unidade << endl;
    cout << " nota " << nota << endl;

    //cout << " F " << teste_F << endl;

    return 0;
}