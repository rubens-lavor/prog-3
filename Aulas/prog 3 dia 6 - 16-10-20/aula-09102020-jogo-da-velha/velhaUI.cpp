#include "velhaUI.h"

void VelhaUI::desenha_grid(sf::RenderWindow& janela, sf::Font fonte) const {
    unsigned int desloca_x{10}, desloca_y{10};
    sf::Text texto;
    texto.setFont(fonte);
    texto.setCharacterSize(20);          // em pixels
    texto.setFillColor(sf::Color::Red);  // define a cor
    texto.setStyle(sf::Text::Bold);

    //desenha a grade do jogo
    sf::RectangleShape line1(sf::Vector2f(205.f, 5.f));
    sf::RectangleShape line2(sf::Vector2f(205.f, 5.f));
    sf::RectangleShape line3(sf::Vector2f(205.f, 5.f));
    sf::RectangleShape line4(sf::Vector2f(205.f, 5.f));
    line3.setRotation(90.f);
    line4.setRotation(90.f);
    line3.setPosition(desloca_x + 65, desloca_y + 0);
    line4.setPosition(desloca_x + 135, desloca_y + 0);
    line1.setPosition(desloca_x + 0, desloca_y + 65);
    line2.setPosition(desloca_x + 0, desloca_y + 135);
    janela.draw(line1);
    janela.draw(line2);
    janela.draw(line3);
    janela.draw(line4);

    //escreve o texto de próximo
    texto.setPosition(10, 250);
    std::string quem_vez = proximo();
    if(vencendor != ' '){
        quem_vez = std::string{vencendor}+" VENCEU!!";
    }
    texto.setString("Vez: " + quem_vez);
    janela.draw(texto);

    //atualiza as jogadas
    for (int l = 0; l < 3; ++l) {
        for (int c = 0; c < 3; ++c) {
            int pos = (3 * l + c) + 1;
            if (!game.casa_diponivel(pos)) {
                char ocupa = game.quemOcupa(pos);
                texto.setCharacterSize(32);
                texto.setString(std::string{ocupa});
                texto.setPosition(20 + desloca_x + (l * 65), 15 + desloca_y + (c * 65));
                janela.draw(texto);
            }
        }
    }
}

void VelhaUI::jogar(const sf::Vector2i clique) {
    int des_x{10}, des_y{10};
    if(vencendor == ' ')
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if ((clique.x >= ((r)*65) + des_x) && (clique.x <= (r)*65 + 65 + des_x)) {
                if ((clique.y >= ((c)*65) + des_y) && (clique.y <= (c)*65 + 65 + des_y)) {
                    game.marca_jogada(prox, (3 * r + c) + 1);
                    if (game.verifica_venceu(prox)) {
                        vencendor = prox;
                    }
                    if (prox == 'x') {
                        prox = 'o';
                    } else {
                        prox = 'x';
                    }
                }
            }
        }
    }
}

const std::string VelhaUI::proximo() const {
    const std::string next{prox};
    return next;
}

VelhaUI::VelhaUI() : prox{'x'}, vencendor{' '} {
}
