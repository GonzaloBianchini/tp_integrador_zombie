#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include"Colisionable.h"


class ZOMBIE: public Colisionable//: public sf::Drawable
{
public:
    ZOMBIE();
    virtual ~ZOMBIE();
    void update();
    //void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    void mobility();
    sf::Sprite& getDraw();
    void suelo(float x, float y);
    float getjump_force();

    sf::FloatRect getBounds() const override;

protected:

private:
    enum ESTADOS{
        QUIETO,
        CAMINANDO_DER,
        CAMINANDO_IZQ,
        SALTANDO
    };

    sf::Sprite _sprite_zombie;
    sf::Texture _texture_zombie;
    ESTADOS _estado;
    int _xtexture=0;
    float _jump_force;


};

#endif // ZOMBIE_H
