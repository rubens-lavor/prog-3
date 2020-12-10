#ifndef conta_h
#define conta_h

namespace topico2 {

class Conta {  //classe 
    int saldo; //atributo ou variável-membro ou membro de dados ou propriedade
    public:
        //construtores
        explicit Conta(int valor);
        //delegando construtor
        Conta();
        //qual é a necessidade de ter 2 construtores?
        //qual dos construtores ele chama?
        //função-membro ou método
        void credito(unsigned int valor);
        void debito(unsigned int valor);
        int getsaldo() const ;
};

}//fim namespace

#endif