#include <iostream>

#include "Livro.hpp"
//#include "Livro.cpp"

int main(){

    Livro livro_01("um teste pra ver se funciona", "rubens", "2566497","32","0012242","e",Genero::ficcao);
    
    std::cout << "Livro: " << livro_01.getTitulo() << std::endl;
    std::cout << "Autor: " << livro_01.getAutor() << std::endl;
    std::cout << "ISBN: " << livro_01.getISBN() << std::endl;
    std::cout << "Genero: " << livro_01.getGen() << std::endl;
    
    return 0;
}