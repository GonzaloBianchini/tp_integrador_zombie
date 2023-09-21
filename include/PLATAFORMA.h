#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <SFML/Graphics.hpp>


class PLATAFORMA//: public sf::Drawable
{
public:
    PLATAFORMA();
    virtual ~PLATAFORMA();
    void update();
    void mobility();
    //void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    sf::Sprite& getDraw();

protected:

private:
    sf::Sprite _sprite_bloque;
    sf::Texture _texture_bloque;

};

#endif // PLATAFORMA_H
