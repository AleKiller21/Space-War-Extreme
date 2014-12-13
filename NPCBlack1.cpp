#include "NPCBlack1.h"

NPCBlack1::NPCBlack1(int x, int y, int HP, std::string bullet_path)
{
    this->pos_x = itofix(x);
    this->pos_y = itofix(y);
    this->speed_vector = itofix(1);
    this->angle = itofix(0);
    this->HP = HP;
    this->fire = false;
    this->moviendo = false;
    this->ship = load_bitmap("assets/NPCs/enemyBlack1.bmp", NULL);
    this->bullet = new Proyectil(pos_x,pos_y, bullet_path);

    std::cout << x << ", " << y << std::endl;
}

NPCBlack1::~NPCBlack1()
{
    destroy_bitmap(ship);
    delete bullet;
}
