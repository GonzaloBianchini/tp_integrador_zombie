#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#include "ZOMBIE.h"
#include "PLATAFORMA.h"

#include "PLANTA.h"

#include "DISPARO.h"

#include"GESTOR_DISPAROS.h"

/*
#include"Shoot_Fire.h"
#include"Shoot_Green.h"
#include"Shoot_Super_Green.h"
#include"Shoot_Ice.h"
#include"Shoot_Brain.h"
*/

/*
#include"Plant_Fire.h"
#include"Plant_Ice.h"
#include"Plant_Green.h"
#include"Plant_Super_Green.h"
*/
class GAME_PLAY
{
public:
    GAME_PLAY();
    virtual ~GAME_PLAY();
    void draw(sf::RenderWindow& window);
    void update();
    void cmd();
    void check_collision_platform();

protected:

private:
    ZOMBIE Z1;
    /*
    Plant_Fire planta1;
    Plant_Green planta2;
    Plant_Ice planta3;
    Plant_Super_Green planta4;
    */
    std::vector<Planta*>    _array_plantas;
    //std::vector<Disparo*>   _array_disparos;

    GESTOR_DISPAROS _shoot_manager;



    /*
    Shoot_Fire shoot1;
    Shoot_Green shoot2;
    Shoot_Ice shoot3;
    Shoot_Super_Green shoot4;
    Shoot_Brain shoot5;
    */

    PLATAFORMA Plats[30];

    enum ESTADOS_GAME_PLAY{
        ACTION,
        PAUSE
    };

    ESTADOS_GAME_PLAY _estado;
    sf::Font _font_pause;
    sf::Text _text_pause;

};

#endif // GAME_PLAY_H
