#include "Funciones.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void Juego()
{
sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    sf::Sprite fondo;
    sf::Texture _fondo;

    if (!_fondo.loadFromFile("img/background_zombie_1.png"))
    {
        std::cout << "Error al cargar la textura del fondo" << std::endl;
        return;
    }
    fondo.setTexture(_fondo);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

          window.draw(fondo);



        window.display();
    }
}
