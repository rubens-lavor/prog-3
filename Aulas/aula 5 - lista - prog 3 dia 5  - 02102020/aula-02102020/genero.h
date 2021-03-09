#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
   public:
    enum class Genero { FICCAO,
                        ROMANCE };

    void genero(Genero novo);

    Genero genero() const;

    std::string generoStr() const;

   private:
    Genero mGenero;
};

#endif