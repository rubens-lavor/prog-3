#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <vector>

void preencher(std::map<std::string, double>& mapa, unsigned int num) {
    std::string prefix{"chave"};
    double valor = 1.0;
    for (int pos = 1; pos < 151; ++pos) {
        mapa.try_emplace(std::to_string(num) + prefix + std::to_string(pos), valor++);
    }
}

class OutraClasse {
    int atr1=0;
   public:
    void ummetodo(int novo=42) {
        atr1 = novo;
    }
};

class MinhaClasse {
    double valor;
    OutraClasse outro;
    void altera() {}

   public:
    MinhaClasse(double val=100.0) : valor{val} {
        altera();
    }
    void incrementa() {
        outro.ummetodo();  //abordagem 1
        valor *= 1.1;
    }

    void recebeInfo(OutraClasse obj) {  //abordagem 2
        obj.ummetodo(66);
    }

    void recebeInfo() {  //abordagem 3
        OutraClasse obj;
        obj.ummetodo();
    }

    double info() const {
        return valor;
    }
};

int mainmapa() {
    std::vector<std::map<std::string, double>> dados{};
    std::list<MinhaClasse> umalista{};

    auto meuptr = std::make_unique<MinhaClasse>(0.0);

    for (int h = 0; h < 5; ++h) {
        MinhaClasse umobj{static_cast<double>(h)};
        umalista.push_back(umobj);
    }

    std::cout << "Antes..." << std::endl;
    for (auto cl : umalista) {
        std::cout << cl.info() << std::endl;
    }
    std::cout << "Incrementou..." << std::endl;
    for (auto& cl : umalista) {
        cl.incrementa();
        std::cout << cl.info() << std::endl;
    }
    std::cout << "Depois..." << std::endl;
    for (auto cl : umalista) {
        std::cout << cl.info() << std::endl;
    }

    exit(0);

    //inicializando
    for (unsigned int i = 0; i < 10; ++i) {
        dados.emplace_back();
        auto& mapa = dados.back();
        preencher(mapa, i);
    }
    //mostrando
    std::for_each(dados.cbegin(), dados.cend(), [](auto& mapa) {
        std::for_each(mapa.cbegin(), mapa.cend(), [](auto& par) {
            std::cout << par.first << " - " << par.second << std::endl;
        });
    });
    return 0;
}

/*
//carta.h
class Carta {
    Naipe n;
    Valor v;
};

//arquivo cartaui.h
#include <QObject>
#include "carta.h"

class CartaUI {//depende do QT
    QT::QObject qo;
    Carta card;
};
*/
