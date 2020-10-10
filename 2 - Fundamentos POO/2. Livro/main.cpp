#include <iostream>
#include "livro.h"

int main(){

    Livro livro_01("um teste pra ver se funciona", "rubens", "2566497","32","0012242","e");
    
    std::cout << "Livro: " << livro_01.getTitulo() << std::endl;
    std::cout << "Autor: " << livro_01.getAutor() << std::endl;
    std::cout << "ISBN: " << livro_01.getISBN() << std::endl;
    
    return 0;
}