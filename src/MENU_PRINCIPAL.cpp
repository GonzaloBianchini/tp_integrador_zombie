#include "MENU_PRINCIPAL.h"
#include<iostream>

MENU_PRINCIPAL::MENU_PRINCIPAL(float width, float height)
{
    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
        // error...
    }

    menu_p[0].setFont(font_item);
    menu_p[0].setString("INICIO");
    menu_p[0].setColor(sf::Color::Green);
    menu_p[0].setPosition(sf::Vector2f(width/2.5,height/3.5*1));

    menu_p[1].setFont(font_item);
    menu_p[1].setString("ESTADISTICA");
    menu_p[1].setColor(sf::Color(255,255,255,80));
    menu_p[1].setPosition(sf::Vector2f(width/2.8,height/3.5*1.5));

    menu_p[2].setFont(font_item);
    menu_p[2].setString("OPCIONES");
    menu_p[2].setColor(sf::Color(255,255,255,80));
    menu_p[2].setPosition(sf::Vector2f(width/2.7,height/3.5*2));

    menu_p[3].setFont(font_item);
    menu_p[3].setString("REGLAMENTO");
    menu_p[3].setColor(sf::Color(255,255,255,80));
    menu_p[3].setPosition(sf::Vector2f(width/2.8,height/3.5*2.5));

    menu_p[4].setFont(font_item);
    menu_p[4].setString("CREDITOS");
    menu_p[4].setColor(sf::Color(255,255,255,80));
    menu_p[4].setPosition(sf::Vector2f(width/2.7,height/3.5*3));

    seleccion_item=0;

}


MENU_PRINCIPAL::~MENU_PRINCIPAL()
{
    //dtor
}

void MENU_PRINCIPAL::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
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
