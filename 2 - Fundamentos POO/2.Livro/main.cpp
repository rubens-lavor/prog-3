#include <iostream>

#include "Livro.hpp"
#include "Livro.cpp"


int main(){

    Livro book("um teste pra ver se funciona", "rubens", "2566497","32","0012242","e");

    std::cout << "Livro: " << book.getTitulo() << std::endl;
    std::cout << "Autor: " << book.getAutor() << std::endl;
    std::cout << "ISBN: " << book.getISBN() << std::endl;
    
    return 0;
}