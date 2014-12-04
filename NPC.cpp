#include "NPC.h"

NPC::NPC(int x, int y, int HP)
{
    this->pos_x = itofix(x);
    this->pos_y = itofix(y);
    this->speed_vector = itofix(1);
    this->angle = itofix(0);
    this->HP = HP;
    this->fire = false;
    this->moviendo = false;
    this->ship = load_bitmap("assets/NPCs/enemyBlue_right.bmp", NULL);
    this->bullet = new Proyectil(pos_x,pos_y, "assets/Proyectil/NPCs/laserBlue03.bmp");
}

NPC::NPC()
{

}

void NPC::logic(fixed target_x, fixed target_y)
{
    fixed target_angle = (fatan2((target_y-pos_y), (target_x-pos_x)))&0xFFFFFF;
    if(((angle-target_angle)&0xFFFFFF) < itofix(128))
    {
        angle = (angle-ftofix(0.5))&0xFFFFFF;
    }

    else
    {
        angle = (angle+ftofix(0.5))&0xFFFFFF;
    }

    pos_x+= fmul(speed_vector, fcos(angle));
    pos_y+= fmul(speed_vector, fsin(angle));

    if(abs(fixtoi(target_angle) - fixtoi(angle)) < 20)
    {
        fire = true;
    }
    else
    {
        fire = false;
    }


    if(fire)
    {
        if(fixtoi(bullet->pos_x) < (SCREEN_W-40) && fixtoi(bullet->pos_x) > 0 && fixtoi(bullet->pos_y) < (SCREEN_H-40) && fixtoi(bullet->pos_y) > 0)
        {
            bullet->mover(itofix(20), angle);
        }

        else
        {
            bullet->actualizar_pos(pos_x+itofix(20), pos_y+itofix(20));
        }

//        std::cout << "Target_x: " << fixtoi(target_x) << ", " << "Target_y: " << fixtoi(target_y) << std::endl;
//        std::cout << "Bullet_x: " << fixtoi(bullet->pos_x) << ", " << "Bullet_y: " << fixtoi(bullet->pos_y) << std::endl;
    }

    else
    {
        bullet->actualizar_pos(pos_x, pos_y);
    }
}

void NPC::draw(BITMAP* canvas)
{
    rotate_sprite(canvas, ship, fixtoi(pos_x), fixtoi(pos_y), angle);
    if(fire)
    {
        rotate_sprite(canvas, bullet->proyectil, fixtoi(bullet->pos_x), fixtoi(bullet->pos_y), angle);
    }
}

void NPC::destroy_sprites()
{
    destroy_bitmap(ship);
}

NPC::~NPC()
{
    //dtor
}
