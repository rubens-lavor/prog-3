#include <iostream>
#include <cstdlib>

using namespace std;

void tabuleiro(char casas[9])
{
    //limpar tela

    cout << "\t" << casas[0] << " | " << casas[1] << " | " << casas[2] << endl;
    cout << "\t----------" << endl;
    cout << "\t" << casas[3] << " | " << casas[4] << " | " << casas[5] << endl;
    cout << "\t----------" << endl;
    cout << "\t" << casas[6] << " | " << casas[7] << " | " << casas[8] << endl;

    cout << endl;
}

bool casa_diponivel(char casas[9], int jogada)
{

    if (casas[jogada - 1] != ' ')
    {
        return false;
    }

    return true;
}

void marca_jogada(char casas[9], char caracter)
{
    int jogada = 0;

    cout << "Digite a casa para marcar[1-9]: ";
    setbuf(stdin, NULL);
    cin >> jogada;

    while (jogada < 1 || jogada > 9 || !casa_diponivel(casas, jogada))
    {
        cout << "Jogada inválida" << endl;
        cout << "Digite a casa para marcar[1-9]: ";
        setbuf(stdin, NULL);
        cin >> jogada;
    }

    casas[jogada - 1] = caracter;
    cout << endl;
}

bool verifica_venceu(char casas[9], char c)
{

    /*linha*/
    if (casas[0] == c && casas[1] == c && casas[2] == c)
    {
        return true;
    }
    if (casas[3] == c && casas[4] == c && casas[5] == c)
    {
        return true;
    }
    if (casas[6] == c && casas[7] == c && casas[8] == c)
    {
        return true;
    }

    /*coluna*/
    if (casas[0] == c && casas[3] == c && casas[6] == c)
    {
        return true;
    }
    if (casas[1] == c && casas[4] == c && casas[7] == c)
    {
        return true;
    }
    if (casas[2] == c && casas[5] == c && casas[8] == c)
    {
        return true;
    }

    /*diagonal*/
    if (casas[0] == c && casas[4] == c && casas[8] == c)
    {
        return true;
    }
    if (casas[2] == c && casas[4] == c && casas[6] == c)
    {
        return true;
    }

    return false;
}

int main()
{
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    tabuleiro(casas);
    int Opcao = 1;
    int vez = 0;
    int cont_jogadas = 0;
    //int jogada = 0;

    do
    {
        cont_jogadas = 1;

        if (Opcao == 1)
        {
            for (int i = 0; i < 9; i++)
            {
                casas[i] = ' ';
            }

            do
            {

                tabuleiro(casas);

                if (vez % 2 == 0)
                {
                    cout << "Jogador 1\n";
                    marca_jogada(casas, 'X');

                    if (verifica_venceu(casas, 'X'))
                    {
                        cout << "Jogador 1 venceu!!\n";
                        cont_jogadas = 20;
                    }
                }
                else
                {
                    cout << "Jogador 2\n";
                    marca_jogada(casas, 'O');

                    if (verifica_venceu(casas, 'O'))
                    {
                        cout << "Jogador 2 venceu!!\n";
                        cont_jogadas = 20;
                    }
                }

                vez++;
                cont_jogadas++;

            } while (cont_jogadas <= 9);

            if (cont_jogadas <= 10)
            {
                cout << "EMPATE!!" << endl;
            }

            tabuleiro(casas);
        }

        cout << "1 - Jogar novamente" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";

        setbuf(stdin, NULL);
        cin >> Opcao;

    } while (Opcao != 0);

    return 0;
}