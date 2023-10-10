#ifndef LIFEBAR_H
#define LIFEBAR_H


#include <SFML/Graphics.hpp>


class Lifebar : public sf::Drawable
{
    public:
        Lifebar();
        virtual ~Lifebar();

        void draw(sf::RenderTarget& target,sf::RenderStates states) const override;   //reescribimos el metodo DRAW por haberlo heredado de DRAWABLE

        void initTexture();
        int getLifePoints()const;
        void setLifePoints(int points);
        void update();

    private:
        int _life_points;     //Segun spritesheet
        sf::Texture _life_bar_texture;
        sf::Sprite _life_bar_sprite;
        sf::IntRect _current_frame;

};

#endif // LIFEBAR_H
