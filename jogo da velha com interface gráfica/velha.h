#ifndef velha_h
#define velha_h

class Velha {
   private:
    /* data */
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

   public:
    Velha(/* args */);
    ~Velha();

    void tabuleiro();
    bool casa_diponivel(int jogada) const;
    char quemOcupa(int jogada) const;
    void marca_jogada(char caracter, const int jogada);
    bool verifica_venceu(char c);
};

#endif
