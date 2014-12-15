#include "NPCRed4.h"

NPCRed4::NPCRed4(int x, int y, int HP, std::string bullet_path, BITMAP* sprite)
{
    this->pos_x = itofix(x);
    this->pos_y = itofix(y);
    this->speed_vector = itofix(1);
    this->angle = itofix(0);
    this->HP = HP;
    this->fire = false;
    this->moviendo = false;
    this->ship = sprite;
    this->bullet = new Proyectil(pos_x,pos_y, bullet_path);

    //std::cout << x << ", " << y << std::endl;
}

NPCRed4::~NPCRed4()
{
    //destroy_bitmap(ship);
    delete bullet;
}
