#include "genero.h"

void Livro::genero(Genero novo) {
    mGenero = novo;
}

Livro::Genero Livro::genero() const {
    return mGenero;
}

std::string Livro::generoStr() const {
    std::string str{"SEM GENERO"};
    switch (mGenero) {
        case Genero::FICCAO:
            str = "FICÇÃO";
            break;

        case Genero::ROMANCE:
            str = "ROMANCE";
            break;
    }
    return str;
}
