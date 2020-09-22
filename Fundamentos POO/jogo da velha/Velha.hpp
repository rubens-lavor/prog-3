#ifndef velha_h
#define velha_h

#include <iostream>

class Velha
{
private:
    /* data */
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
    Velha(/* args */);
    ~Velha();

    void tabuleiro();
    bool casa_diponivel(int jogada);
    void marca_jogada(char caracter);
    bool verifica_venceu(char c);
};

#endif

