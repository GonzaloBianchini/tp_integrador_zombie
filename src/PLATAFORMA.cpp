#include "PLATAFORMA.h"

PLATAFORMA::PLATAFORMA()
{
    _texture_bloque.loadFromFile("img/Plataforma_ind.png");
    _sprite_bloque.setTexture(_texture_bloque);
    _sprite_bloque.setPosition(0,400);
}

PLATAFORMA::~PLATAFORMA()
{
    //dtor
}

void PLATAFORMA::update()
{

}

sf::Sprite& PLATAFORMA::getDraw()
{
    return _sprite_bloque;
}

void PLATAFORMA::mobility()
{

}
