#include <iostream>
#include "Velha.hpp"
#include "Velha.cpp"



int main()
{

    //Velha VLH;
    //char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    //tabuleiro(casas);
    int Opcao = 1;
    int vez = 0;
    int cont_jogadas = 0;
    //int jogada = 0;

    do
    {
        cont_jogadas = 1;

        if (Opcao == 1)
        {
            /*
            for (int i = 0; i < 9; i++)
            {
                casas[i] = ' ';
            }
            */

           Velha VLH;

            do
            {

                VLH.tabuleiro();

                if (vez % 2 == 0)
                {
                    std::cout << "Jogador 1\n";
                    VLH.marca_jogada('X');

                    if (VLH.verifica_venceu('X'))
                    {
                        std::cout << "Jogador 1 venceu!!\n";
                        cont_jogadas = 20;
                    }
                }
                else
                {
                    std::cout << "Jogador 2\n";
                    VLH.marca_jogada('O');

                    if (VLH.verifica_venceu('O'))
                    {
                        std::cout << "Jogador 2 venceu!!\n";
                        cont_jogadas = 20;
                    }
                }

                vez++;
                cont_jogadas++;

            } while (cont_jogadas <= 9);

            if (cont_jogadas <= 10)
            {
                std::cout << "EMPATE!!" << std::endl;
            }

            VLH.tabuleiro();
        }

        std::cout << "1 - Jogar novamente" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Escolha uma opção: ";

        setbuf(stdin, NULL);
        std::cin >> Opcao;

    } while (Opcao != 0);

    return 0;
}