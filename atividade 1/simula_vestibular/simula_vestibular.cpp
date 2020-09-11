#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>

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
    ofstream arquivo;
    arquivo.open("vestibular.txt");

    arquivo << "Inscrição|\tIdade|\tCurso|\tPontuação";

    for (int i = 1; i <= 826; i++)
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
    }

    arquivo << "\n";
    arquivo << "-1";

    arquivo.close();

    //cout << "lista criada\n";
}

/*caminha na linha até a posição do curso*/
int busca_curso(char *vetor_de_busca, int pos_contra_barra)
{

    int dezena = 0;
    int unidade = 0;

    dezena = vetor_de_busca[pos_contra_barra + 11];
    unidade = vetor_de_busca[pos_contra_barra + 12];

    return (dezena - 48) * 10 + (unidade - 48);
}

/*-----------------------------------------------------------------------*/

/*Essa função retorna um inteiro que pode ser o curso, a nota, o registro ou a idade, 
dependendo dos valores dos parametros passados.
Esse valor é buscado no vetor_de_busca e convertido para inteiro
*/
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
        milhar = vetor_de_busca[pos_contra_barra + pos_inicio + 0]; //nesse caso pos_inicio = 15
        centena = vetor_de_busca[pos_contra_barra + pos_inicio + 1];
        dezena = vetor_de_busca[pos_contra_barra + pos_inicio + 2];
        unidade = vetor_de_busca[pos_contra_barra + pos_inicio + 3];

        if (unidade == 10 || dezena == 10 || centena == 10) //tratamento para nota < 1000
        {
            
            if (centena == 10) //nota com 1 dígito
            {
                unidade = milhar;
                return unidade - 48;
            }
            else if (dezena == 10)//nota com 2 dígitos
            {
                unidade = centena;
                dezena = milhar;
                return (dezena - 48) * 10 + (unidade - 48);
            }
            else //nota com 3 dígitos
            {

                unidade = dezena;
                dezena = centena;
                centena = milhar;
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

//preenche o vetor do curso com 4 inteiro por vez, representando o curso, nota, registro e idade. 
void insere_no_vetor_do_curso(int *vetor_curso, char *vetor_de_busca, int pos_contra_barra, int i)
{
    vetor_curso[i * 4] = busca_numero(vetor_de_busca, pos_contra_barra, 4, 15); //4 digitos, posição 15 a partir da quebra de linha, representa a nota.
    vetor_curso[i * 4 + 1] = busca_numero(vetor_de_busca, pos_contra_barra, 4, 2); //4 digitos, posiçao 2 a partir da quebra de linha - registro.
    vetor_curso[i * 4 + 2] = busca_numero(vetor_de_busca, pos_contra_barra, 2, 7); // idade
    vetor_curso[i * 4 + 3] = busca_numero(vetor_de_busca, pos_contra_barra, 2, 11); // nota
}

void ordena(int *vet, int inscritos)
{
    
    int maior[4];
    int posicao[4];
    bool troca;
    int aux[4];
    
    for (int i = 0; i < inscritos * 4; i += 4) //varre o vetor de 4 em 4 posições, pegando apenas as notas
    {
        troca = false;
        maior[0] = vet[i]; //a nota ta na posição 0,4,8,12....
        posicao[0] = i;

        for (int j = i + 4; j < inscritos * 4; j += 4)
        {

            if (vet[j] > maior[0])
            {
                //guarda as posições posteriores ao maior valor
                //o deslocamento é feito de maneira agrupada
                maior[0] = vet[j];
                maior[1] = vet[j + 1];
                maior[2] = vet[j + 2];
                maior[3] = vet[j + 3];

                posicao[0] = j;
                posicao[1] = j + 1;
                posicao[2] = j + 2;
                posicao[3] = j + 3;

                troca = true;
            }
        }

        if (troca)
        {

            aux[0] = vet[i];
            aux[1] = vet[i + 1];
            aux[2] = vet[i + 2];
            aux[3] = vet[i + 3];

            vet[i] = maior[0];
            vet[i + 1] = maior[1];
            vet[i + 2] = maior[2];
            vet[i + 3] = maior[3];

            vet[posicao[0]] = aux[0];
            vet[posicao[1]] = aux[1];
            vet[posicao[2]] = aux[2];
            vet[posicao[3]] = aux[3];
        }
    }
}

void imprime_resultado(int *vetor_curso, int contador_curso)
{

    ordena(vetor_curso, contador_curso);

    cout << "--------------------------------------------" << endl;
    cout << "Aprovados Curso "<<vetor_curso[3]<< "\n\n";

    cout << "\tInscrição"
         << "\t"
         << "Pontuação"
         << "\t"
         << "Idade"
         << "\t"
         << "Curso"
         << endl;

    for (int i = 0; i < 40; i++)
    {

        cout
            << i + 1
            << "\t"
            << vetor_curso[i * 4 + 1]
            << "\t\t"
            << vetor_curso[i * 4]
            << "\t\t"
            << vetor_curso[i * 4 + 2]
            << "\t"
            << vetor_curso[i * 4 + 3]
            << "\t"
            << endl;
    }

    cout << endl;
}

int main()
{
    /*para verificar se temos pelo menos 3 candidatos por vaga em cada curso*/
    int contador_curso_11 = 0;
    int contador_curso_12 = 0;
    int contador_curso_13 = 0;
    int contador_curso_14 = 0;
    int contador_curso_15 = 0;
    int contador_curso_16 = 0;

    char vetor_de_busca[20000] = {}; //recebe todos os caracteres do arquivo
    int posicao = 0;                 //incrementa a cado novo caractere lido do arquivo

    int vetor_pos_contra_barra[827] = {}; //guarda a posição do todos os \n
    int cont = 0;                         //incrementa cada vez que um \n é lido do arquivo

    //vetor_curso armazena as informaçoes dos inscritos do respectivo curso 
    int vetor_curso_11[230 * 4] = {}; //cada curso consegue ter no máximo 226 inscritos * 4 pois cada aluno gera 4 numeros
    int vetor_curso_12[230 * 4] = {};
    int vetor_curso_13[230 * 4] = {};
    int vetor_curso_14[230 * 4] = {};
    int vetor_curso_15[230 * 4] = {};
    int vetor_curso_16[230 * 4] = {};

    do
    {
        /*
        caso não seja gerado 3 candidatos por vaga, é necessário resetar as variáveis
        para fazer uma nova verificação.
        */

        contador_curso_11 = 0;
        contador_curso_12 = 0;
        contador_curso_13 = 0;
        contador_curso_14 = 0;
        contador_curso_15 = 0;
        contador_curso_16 = 0;

        cont = 0;
        posicao = 0; //contador pro vetor_de_busca

        criaLista();

        ifstream arquivoEntrada; //objeto de leitura
        
        arquivoEntrada.open("vestibular.txt"); //abre o arquivo

        if (arquivoEntrada.is_open())
        {

            while (!arquivoEntrada.eof())
            {
                //vetor_de_busca recebe todos os caracteres do arquivo

                arquivoEntrada.get(vetor_de_busca[posicao]);

                if (vetor_de_busca[posicao] == '\n')
                {
                    vetor_pos_contra_barra[cont] = posicao;
                    cont += 1;
                }

                posicao += 1;
            }
            arquivoEntrada.close();
        }
        else
        {
            cout << "Não foi possível abrir o arquivo" << endl;
        }

        for (int i = 0; i < 826; i++)
        {
            //a função busca_curso está retornando o valor correspondente do curso

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 11)
            {
                insere_no_vetor_do_curso(vetor_curso_11, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_11);
                contador_curso_11++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 12)
            {
                insere_no_vetor_do_curso(vetor_curso_12, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_12);
                contador_curso_12++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 13)
            {
                insere_no_vetor_do_curso(vetor_curso_13, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_13);
                contador_curso_13++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 14)
            {
                insere_no_vetor_do_curso(vetor_curso_14, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_14);
                contador_curso_14++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 15)
            {
                insere_no_vetor_do_curso(vetor_curso_15, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_15);
                contador_curso_15++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 16)
            {
                insere_no_vetor_do_curso(vetor_curso_16, vetor_de_busca, vetor_pos_contra_barra[i], contador_curso_16);
                contador_curso_16++;
            }
        }

    } while (contador_curso_11 < 120 || contador_curso_12 < 120 || contador_curso_13 < 120 || contador_curso_14 < 120 || contador_curso_15 < 120 || contador_curso_16 < 120);

    cout << "Curso 11 numero de candidatos: " << contador_curso_11 << endl;
    cout << "Curso 12 numero de candidatos: " << contador_curso_12 << endl;
    cout << "Curso 13 numero de candidatos: " << contador_curso_13 << endl;
    cout << "Curso 14 numero de candidatos: " << contador_curso_14 << endl;
    cout << "Curso 15 numero de candidatos: " << contador_curso_15 << endl;
    cout << "Curso 16 numero de candidatos: " << contador_curso_16 << endl;

    cout << endl;
    cout << "Resultado do vestibular" << endl;

    imprime_resultado(vetor_curso_11, contador_curso_11);
    imprime_resultado(vetor_curso_12, contador_curso_12);
    imprime_resultado(vetor_curso_13, contador_curso_13);
    imprime_resultado(vetor_curso_14, contador_curso_14);
    imprime_resultado(vetor_curso_15, contador_curso_15);
    imprime_resultado(vetor_curso_16, contador_curso_16);


    return 0;

}