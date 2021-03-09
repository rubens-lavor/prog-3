#include <iostream>
#include <memory>
#include <vector>
#include "conta.h"
#include "conta.cpp"

namespace t2 = topico2;

void mostra_saldo(const topico2::Conta conta){
    std::cout << "Saldo: " << conta.getsaldo() << std::endl;
}

int main(){

    t2::Conta minha_conta{1000}, outra_conta; // minha_conta é um objeto de Conta
    t2::Conta vConta[10];
    std::vector<t2::Conta> outroVetor{};
    outroVetor.emplace_back(500);
    for(const t2::Conta& aConta: outroVetor){
        mostra_saldo(aConta);
    }

    for(const t2::Conta& aConta: vConta){
        mostra_saldo(aConta);
    }

    auto ptr_conta = std::make_unique<t2::Conta>(500);
    ptr_conta->credito(150);
    ptr_conta->debito(300);
    std::cout   << "Dinamico: " << ptr_conta->getsaldo()<<std::endl;
    mostra_saldo(outra_conta);
    //outra_conta = 500;
    std::cout   << "Minha: "<<minha_conta.getsaldo() << " Outra: "<<outra_conta.getsaldo()<<std::endl;
    minha_conta.credito(550);//invocando método credito com argumento 55
                            //passando a mensagem credito com o argumento 55 para o objeto minha_conta
    std::cout   << "Minha: "<<minha_conta.getsaldo() << " Outra: "<<outra_conta.getsaldo()<<std::endl;
    minha_conta.debito(200);
    outra_conta.debito(100);
    std::cout   << "Minha: "<<minha_conta.getsaldo() << " Outra: "<<outra_conta.getsaldo()<<std::endl;
    outra_conta.credito(100);
    std::cout   << "Minha: "<<minha_conta.getsaldo() << " Outra: "<<outra_conta.getsaldo()<<std::endl;
    outra_conta.debito(42);
    std::cout   << "Minha: "<<minha_conta.getsaldo() << " Outra: "<<outra_conta.getsaldo()<<std::endl;

    return 0;
}
