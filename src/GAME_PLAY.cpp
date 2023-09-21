#include "GAME_PLAY.h"
#include <iostream>

GAME_PLAY::GAME_PLAY()
{
    _estado=ESTADOS_GAME_PLAY::ACTION;

    Plats[0].getDraw().setPosition(250,400);
    Plats[1].getDraw().setPosition(310,400);
    Plats[2].getDraw().setPosition(500,400);
    Plats[3].getDraw().setPosition(560,400);
    Plats[4].getDraw().setPosition(750,400);
    Plats[5].getDraw().setPosition(810,400);
    Plats[6].getDraw().setPosition(870,400);


    Plats[7].getDraw().setPosition(190,270);
    Plats[8].getDraw().setPosition(370,270);
    Plats[9].getDraw().setPosition(430,270);
    Plats[10].getDraw().setPosition(750,270);
    Plats[11].getDraw().setPosition(740,270);
    Plats[12].getDraw().setPosition(680,270);
    Plats[13].getDraw().setPosition(900,270);
    Plats[14].getDraw().setPosition(1040,270);
    Plats[15].getDraw().setPosition(1100,270);
    Plats[16].getDraw().setPosition(1160,270);


    Plats[17].getDraw().setPosition(0,140);
    Plats[18].getDraw().setPosition(60,140);
    Plats[19].getDraw().setPosition(120,140);
    Plats[20].getDraw().setPosition(300,140);
    Plats[21].getDraw().setPosition(360,140);
    Plats[22].getDraw().setPosition(420,140);
    Plats[23].getDraw().setPosition(700,140);
    Plats[24].getDraw().setPosition(760,140);
    Plats[25].getDraw().setPosition(820,140);
    Plats[26].getDraw().setPosition(880,140);
    Plats[27].getDraw().setPosition(1040,140);
    Plats[28].getDraw().setPosition(1100,140);
    Plats[29].getDraw().setPosition(1160,140);


}

GAME_PLAY::~GAME_PLAY()
{
    //dtor
}

void GAME_PLAY::draw(sf::RenderWindow& window)
{
    window.draw(Z1.getDraw());
    for(auto Plat_1: Plats)
    {
        window.draw(Plat_1.getDraw());
    }
    window.draw(_text_pause);

}

void GAME_PLAY::update()
{
    if(_estado==ESTADOS_GAME_PLAY::ACTION) //SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
    {
        Z1.update();

        if(Z1.getDraw().getPosition().y>485) //Suelo... limite de caida
        {
            Z1.suelo(Z1.getDraw().getPosition().x,485);
        }

        for(auto Plat_1: Plats)
        {
            Plat_1.update();
        }


        check_collision_platform();

    }


}

void GAME_PLAY::cmd()
{
    if(_estado==ESTADOS_GAME_PLAY::ACTION)//SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
    {
        Z1.mobility();

        for(auto Plat_1: Plats)
        {
            Plat_1.mobility();
        }


        //...........comandos para poner en pausa el juego......

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _estado=ESTADOS_GAME_PLAY::PAUSE;

            if (!_font_pause.loadFromFile("font/Lethal Slime.ttf"))
            {
                std::cout<<"Error al cargar texto"<<std::endl;
            }
            std::cout<<"Pausa"<<std::endl;
            _text_pause.setFont(_font_pause);
            _text_pause.setString("PAUSA");
            _text_pause.setColor(sf::Color::Red);
            _text_pause.setPosition(488,228.50);

        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _estado=ESTADOS_GAME_PLAY::ACTION;
        }
    }
}

void GAME_PLAY::check_collision_platform()
{

    for(auto Plat_1: Plats)
    {
        if(Z1.getDraw().getGlobalBounds().intersects(Plat_1.getDraw().getGlobalBounds())&&Z1.getjump_force()<0)
        {
            //std::cout<<"Colision"<<std::endl;
            Z1.suelo(Z1.getDraw().getPosition().x,Plat_1.getDraw().getGlobalBounds().top-80); //80 es la altura del Sprite
        }
    }

}
