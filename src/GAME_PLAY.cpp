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




    _array_plantas.push_back(new Planta(SUPER_GREEN,{400,500},LEFT,_shoot_manager));   //prueba posicion
    _array_plantas.push_back(new Planta(GREEN,{800,500},RIGHT,_shoot_manager));   //prueba posicion
    _array_plantas.push_back(new Planta(ICE,{400,200},LEFT,_shoot_manager));   //prueba posicion
    _array_plantas.push_back(new Planta(FIRE,{800,200},RIGHT,_shoot_manager));   //prueba posicion


}

GAME_PLAY::~GAME_PLAY()
{
    //dtor
}

void GAME_PLAY::draw(sf::RenderWindow& window)
{
    window.draw(Z1.getDraw());


    for(auto plant : _array_plantas)
    {
        window.draw(*plant);
    }



    for(auto disparo : _shoot_manager._array_disparos)
    {
        window.draw(*disparo);
    }


    /*
    window.draw(planta1);
    window.draw(planta2);
    window.draw(planta3);
    window.draw(planta4);

    window.draw(shoot1);
    window.draw(shoot2);
    window.draw(shoot3);
    window.draw(shoot4);
    window.draw(shoot5);
    */

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

        ////modificaciones planta

        /*
        planta1.update();
        planta2.update();
        planta3.update();
        planta4.update();
        ////
        shoot1.update();
        shoot2.update();
        shoot3.update();
        shoot4.update();
        shoot5.update();
        */

        //actualizo y borro en consecuencia
        //este bloque podria llamarse updateElements() o updatePlants()

        for(auto it=_array_plantas.begin(); it!=_array_plantas.end();)   //inicio el iterador IT en el principio del array y recorro hasta el final de array
        {
            Planta* planta = *it;       //defino el puntero a PLANTA llamado planta y apunta igual que IT, sera el objeto a actualizar y/o borrar
            planta->update();
            //chequeo colision zombie-planta
            if(Z1.isCollision(*planta))
            {
                delete planta;                  //libera memoria del objeto planta, pero ojo! el puntero planta aun tiene la direccion
                                                //de memoria del objeto eliminado, es decir, el objeto esta en la lista pero no es valido.
                it=_array_plantas.erase(it);    //con esto elimino completamente de la lista y el iterador IT queda apuntando al siguiente elemento

            }
            else
            {
                ++it;                           //Si no se elimina el enemigo, avanza al siguiente elemento
            }

        }

        for(auto it=_shoot_manager._array_disparos.begin();it!=_shoot_manager._array_disparos.end();)
        {
            Disparo* disp = *it;
            disp->update();
            if(Z1.isCollision(*disp))
            {
                delete disp;

                it=_shoot_manager._array_disparos.erase(it);
            }
            else
            {
                ++it;
            }
        }
///////////////////////////////////////
        //bloque similar al anterior pero con disparos
        /*
        for(auto it=_array_disparos.begin();it!=_array_disparos.end();)
        {
            Disparo* disparo = *it;
            disparo->update();

            if(Z1.isCollision(*disparo))
            {
                delete disparo;
                it=_array_disparos.erase(it);
            }
            else
            {
                ++it;
            }
        }
        */

        //_shoot_manager.agregarDisparo(new Disparo(GREEN,{10,10}));


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
