#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "velhaUI.h"
/*
 Projeto exemplo de interface gráfica com SFML.
 O texto se movimenta de acordo com as teclas CIMA; BAIXO; ESQUERDA; e DIREITA.
 Configurado para utilizar C++17.
 Portanto, sugere-se um compilador que suporte essa versão.

 Para instalar o SFML:
 ubuntu: sudo apt-get install libsfml-dev
 fedora: sudo dnf install SFML SFML-devel
 windows: https://www.sfml-dev.org/download.php
*/

int main() {
    VelhaUI jogoVelha;
    bool jogou=false;
    sf::Vector2i pos_mouse;
    sf::RenderWindow window(sf::VideoMode(250, 300), "Jogo da Velha!");
    sf::Font opensans;
    if (!opensans.loadFromFile("./fonts/OpenSans-Bold.ttf")) {
        std::cerr << "ERRO: fonte não encontrada!\n";
    }

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    //window.setKeyRepeatEnabled(true);//habilita a repetição das teclas

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    pos_mouse.x = event.mouseButton.x;
                    pos_mouse.y = event.mouseButton.y;
                    jogou = true;
                    break;
                // key pressed
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        // --x_texto;
                        // std::cout << "Keyboard esquerda!" << std::endl;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        // ++x_texto;
                        // std::cout << "Keyboard direita!" << std::endl;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        // ++y_texto;
                        // std::cout << "Keyboard para baixo!" << std::endl;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        // --y_texto;
                        // std::cout << "Keyboard para cima!" << std::endl;
                    } else
                        std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                    break;
            }
        }

        window.clear();
        jogoVelha.desenha_grid(window, opensans);

        if(jogou){
            jogoVelha.jogar(pos_mouse);
            jogou = false;
        }
        window.display();
    }
    return 0;
}