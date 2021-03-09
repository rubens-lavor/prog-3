#include "velha.h"

#include <iostream>

Velha::Velha() {
    /* tabuleiro();*/

    for (int i = 0; i < 9; i++) {
        casas[i] = ' ';
    }
}

Velha::~Velha() {
}

void Velha::tabuleiro() {
    //limpar tela

    std::cout << "\t" << casas[0] << " | " << casas[1] << " | " << casas[2] << std::endl;
    std::cout << "\t----------" << std::endl;
    std::cout << "\t" << casas[3] << " | " << casas[4] << " | " << casas[5] << std::endl;
    std::cout << "\t----------" << std::endl;
    std::cout << "\t" << casas[6] << " | " << casas[7] << " | " << casas[8] << std::endl;

    std::cout << std::endl;
}

bool Velha::casa_diponivel(int jogada) const {
    if (casas[jogada - 1] != ' ') {
        return false;
    }

    return true;
}

char Velha::quemOcupa(int jogada) const {
    char resposta = ' ';
    if(jogada>0 && jogada<10){
        resposta = casas[jogada-1];
    }
    return resposta;
}

void Velha::marca_jogada(char caracter, const int jogada) {
//    int jogada = 0;

//    std::cout << "Digite a casa para marcar[1-9]: ";
//    setbuf(stdin, NULL);
//    std::cin >> jogada;

    if (jogada > 0 && jogada < 10 && casa_diponivel(jogada)) {
//       std::cout << "Jogada inválida" << std::endl;
//        std::cout << "Digite a casa para marcar[1-9]: ";
//       setbuf(stdin, NULL);
//        std::cin >> jogada;
        casas[jogada - 1] = caracter;
    }
   
//    std::cout << std::endl;
}

bool Velha::verifica_venceu(char c) {
    /*linha*/
    if (casas[0] == c && casas[1] == c && casas[2] == c) {
        return true;
    }
    if (casas[3] == c && casas[4] == c && casas[5] == c) {
        return true;
    }
    if (casas[6] == c && casas[7] == c && casas[8] == c) {
        return true;
    }

    /*coluna*/
    if (casas[0] == c && casas[3] == c && casas[6] == c) {
        return true;
    }
    if (casas[1] == c && casas[4] == c && casas[7] == c) {
        return true;
    }
    if (casas[2] == c && casas[5] == c && casas[8] == c) {
        return true;
    }

    /*diagonal*/
    if (casas[0] == c && casas[4] == c && casas[8] == c) {
        return true;
    }
    if (casas[2] == c && casas[4] == c && casas[6] == c) {
        return true;
    }

    return false;
}
