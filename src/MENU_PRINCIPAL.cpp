#include "MENU_PRINCIPAL.h"
#include<iostream>

MENU_PRINCIPAL::MENU_PRINCIPAL(float width, float height)
{
    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
         std::cout<<"Error al cargar texto"<<std::endl;
    }

    _texture_menu.loadFromFile("img/tumba.png");
    _fondo_menu.setTexture(_texture_menu);
    _fondo_menu.setScale(0.23,0.2);

    menu_p[0].setFont(font_item);
    menu_p[0].setString("INICIO");
    menu_p[0].setColor(sf::Color::Green);
    menu_p[0].setPosition(sf::Vector2f(width/2.08,height/5*1.2));

    menu_p[1].setFont(font_item);
    menu_p[1].setString("ESTADISTICA");
    menu_p[1].setColor(sf::Color(255,255,255,80));
    menu_p[1].setPosition(sf::Vector2f(width/2.3,height/5*1.7));

    menu_p[2].setFont(font_item);
    menu_p[2].setString("OPCIONES");
    menu_p[2].setColor(sf::Color(255,255,255,80));
    menu_p[2].setPosition(sf::Vector2f(width/2.2,height/5*2.2));

    menu_p[3].setFont(font_item);
    menu_p[3].setString("REGLAMENTO");
    menu_p[3].setColor(sf::Color(255,255,255,80));
    menu_p[3].setPosition(sf::Vector2f(width/2.25,height/5*2.7));

    menu_p[4].setFont(font_item);
    menu_p[4].setString("CREDITOS");
    menu_p[4].setColor(sf::Color(255,255,255,80));
    menu_p[4].setPosition(sf::Vector2f(width/2.17,height/5*3.2));

    seleccion_item=0;

}


MENU_PRINCIPAL::~MENU_PRINCIPAL()
{
    //dtor
}

void MENU_PRINCIPAL::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_fondo_menu,states);
    for(int x=0; x<Item; x++)
    {
        target.draw(menu_p[x],states);
    }

}

void MENU_PRINCIPAL::up()
{
    if(seleccion_item-1>=0)
    {
        menu_p[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item--;
        menu_p[seleccion_item].setColor(sf::Color::Green);
    }
}

void MENU_PRINCIPAL::down()
{
    if(seleccion_item+1<Item)
    {
        menu_p[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item++;
        menu_p[seleccion_item].setColor(sf::Color::Green);
    }
}
