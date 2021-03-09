#ifndef VELHA_UI_H
#define VELHA_UI_H

#include <SFML/Graphics.hpp>
#include "velha.h"

class VelhaUI {
    Velha game;
    char prox,vencendor;
    public:
    VelhaUI();
    void desenha_grid(sf::RenderWindow& janela,sf::Font fonte) const ;
    const std::string proximo() const;
    void jogar(const sf::Vector2i clique);

};

#endif