#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
//#include <cmath>

using namespace std;

int numero_aleatorio(int max, int min)
{
    uniform_int_distribution<int> randomDist(min, max);
    random_device rd;
    mt19937 randomNumbers(rd());
    return randomDist(randomNumbers);
}

int busca_numero(char *vetor_de_busca, int pos_contra_barra, int qtde_pos, int pos_inicio)
{

    int milhar = 0;
    int centena = 0;
    int dezena = 0;
    int unidade = 0;

    if (qtde_pos == 2) //idade ou curso
    {
        dezena = vetor_de_busca[pos_contra_barra + pos_inicio + 0];
        unidade = vetor_de_busca[pos_contra_barra + pos_inicio + 1];

        return (dezena - 48) * 10 + (unidade - 48);
    }

    if (qtde_pos == 4) //nota
    {
        milhar = vetor_de_busca[pos_contra_barra + pos_inicio + 0]; //pos_inicio = 15
        centena = vetor_de_busca[pos_contra_barra + pos_inicio + 1];
        dezena = vetor_de_busca[pos_contra_barra + pos_inicio + 2];
        unidade = vetor_de_busca[pos_contra_barra + pos_inicio + 3];

        if (unidade == 10 || dezena == 10 || centena == 10) //tratamento para nota > 1000
        {
            cout << " Opa! estamos no if que trata nota<1000 " << endl;
            if (centena == 10)
            {
                unidade = milhar;
                cout << " nota com 1 dígito " << endl;
                return unidade - 48;
            }
            else if (dezena == 10)
            {
                unidade = centena;
                dezena = milhar;
                cout << " nota com 2 dígitos " << endl;
                return (dezena - 48) * 10 + (unidade - 48);
            }
            else
            {

                unidade = dezena;
                dezena = centena;
                centena = milhar;
                cout << " nota com 3 dígitos " << endl;
                return (centena - 48) * 100 + (dezena - 48) * 10 + (unidade - 48);
            }
        }
        else
        {
            return (milhar - 48) * 1000 + (centena - 48) * 100 + (dezena - 48) * 10 + (unidade - 48);
        }
    }

    return -2;
}

void criaLista()
{
    ofstream arquivo; //inserção no arquivo

    //arquivo.open("vestibular.txt",ios::app);
    arquivo.open("vestibular.txt");

    //arquivo << "nº inscrição|\tIdade|\tCurso Pretendido|\tPontuação";
    //arquivo << "\n";

    for (int i = 1; i <= 3; i++)
    {
        int registro = 1000 + i;
        int idade = numero_aleatorio(30, 17);
        int pontuacao = numero_aleatorio(5000, 0);
        int curso = numero_aleatorio(16, 11);

        arquivo << "\n";
        arquivo << "\t";
        arquivo << registro;
        arquivo << "\t";
        arquivo << idade;
        arquivo << "\t\t";
        arquivo << curso;
        arquivo << "\t\t";
        arquivo << pontuacao;
        //arquivo << "F";
    }

    arquivo << "\n";
    arquivo << "-1";

    arquivo.close();
}

void ordena(int *vet, int *vet_guarda_posicao)
{

    int maior[2];
    //int auxmaior;
    int posicao[2];
    //int auxpos;
    bool troca;
    int aux[2];
    //int aux2 = 0;


    for (int i = 0; i < 6; i+=2)
    {
        troca = false;
        maior[0] = vet[i];
        posicao[0] = i;
        

        

        for (int j = i + 2; j < 6; j+=2)
        {

            if (vet[j] > maior[0])
            {

                maior[0] = vet[j];
                maior[1] = vet[j+1];
                posicao[0] = j;
                posicao[1] = j+1;
                troca = true;

            }
            
            
            
            
        }

        if (troca)
        {

            aux[0] = vet[i];
            aux[1] = vet[i+1];

            vet[i] = maior[0];
            vet[i+1] = maior[1];

            vet[posicao[0]] = aux[0];
            vet[posicao[1]] = aux[1];

        }
        
        
        
    
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < 6; i++)
    {

        cout << vet[i] << endl;
    }
}
int main()
{

    char vetor_de_busca[500] = {};
    int posicao = 0;
    int caractere_por_linha = 0;
    int contra_barra = 0;

    char vetor_de_linha_e_pontuacao[2] = {};

    int vetor_nota_registro_idade_curso[12] = {};

    int vetor_pos_contra_barra[10] = {};

    int vetor_manobra[6] = {};

    int pos_contra_barra = 0;

    int vet_guarda_posicao[4] = {};

    

    criaLista();

    ifstream arquivoEntrada; //lê o arquivo
    string linha[4] = {};
    arquivoEntrada.open("vestibular.txt");

    if (arquivoEntrada.is_open())
    {
        //while (getline(arquivoEntrada, linha)){cout << linha << endl;}

        int cont = 0;
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
                vetor_pos_contra_barra[cont] = posicao;
                cont += 1;
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

    for (int i = 0; i < 4; i++)
    {
        cout << vetor_de_busca[i + 68];
        linha[i] = vetor_de_busca[i + 68];
    }
    cout << endl;

    int nota = 0;
    int registro = 0;
    int idade = 0;
    int curso = 0;
    int indice = 0;

    for (int i = 0; i < 3; i++)
    {
        nota = busca_numero(vetor_de_busca, vetor_pos_contra_barra[i], 4, 15);
        registro = busca_numero(vetor_de_busca, vetor_pos_contra_barra[i], 4, 2);
        idade = busca_numero(vetor_de_busca, vetor_pos_contra_barra[i], 2, 7);
        curso = busca_numero(vetor_de_busca, vetor_pos_contra_barra[i], 2, 11);

        indice = i * 4;
        //cout <<"resultado de indice"<< indice << endl;

        vetor_nota_registro_idade_curso[indice] = nota;
        vetor_nota_registro_idade_curso[indice + 1] = registro;
        vetor_nota_registro_idade_curso[indice + 2] = idade;
        vetor_nota_registro_idade_curso[indice + 3] = curso;

        vetor_manobra[i*2] = nota;
        vetor_manobra[i*2+1] = registro;

        cout << "nota: " << vetor_nota_registro_idade_curso[indice];
        cout << "\tregistro: " << vetor_nota_registro_idade_curso[indice + 1];
        cout << "\tidade: " << vetor_nota_registro_idade_curso[indice + 2];
        cout << "\tcurso " << vetor_nota_registro_idade_curso[indice + 3] << endl;


    }

    cout << endl;

    for (int i = 0; i < 12; i++)
    {

        cout << vetor_nota_registro_idade_curso[i] << " - ";
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < 6; i++)
    {

        cout << vetor_manobra[i] << endl;
    }

    //ordenar
    ordena(vetor_manobra, vet_guarda_posicao);

    /*
    int nota = busca_numero(vetor_de_busca, vetor_pos_contra_barra[0], 4, 15);
    int nota2 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[1], 4, 15);
    int nota3 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[2], 4, 15);

    int registro = busca_numero(vetor_de_busca, vetor_pos_contra_barra[0], 4, 2);
    int registro2 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[1], 4, 2);
    int registro3 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[2], 4, 2);
    
    int idade = busca_numero(vetor_de_busca, vetor_pos_contra_barra[0], 2, 7);
    int idade2 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[1], 2, 7);
    int idade3 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[2], 2, 7);

    int curso = busca_numero(vetor_de_busca, vetor_pos_contra_barra[0], 2, 11);
    int curso2 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[1], 2, 11);
    int curso3 = busca_numero(vetor_de_busca, vetor_pos_contra_barra[2], 2, 11);
    
    */

    cout << endl;

    /*

    cout << " nota 1 " << nota;
    cout << "\t idade 1 " << idade;
    cout << "\t curso " << curso;
    cout << "\t registro 1 " << registro << endl;
    
    
    cout << " nota 2 " << nota2;
    cout << "\t idade 2 " << idade2;
    cout << "\t curso " << curso2;
    cout << "\t registro 2 " << registro2 << endl;

    cout << " nota 3 " << nota3;
    cout << "\t idade 3 " << idade3;
    cout << "\t curso " << curso3;
    cout << "\t registro 3 " << registro3 << endl;
    */

    cout << " vetor_pos_contra_barra[0] " << vetor_pos_contra_barra[0] << endl;
    cout << " vetor_pos_contra_barra[1] " << vetor_pos_contra_barra[1] << endl;
    cout << " vetor_pos_contra_barra[2] " << vetor_pos_contra_barra[2] << endl;

    return 0;
}