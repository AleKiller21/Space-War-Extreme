#include "NPC.h"

NPC::NPC(int x, int y, int HP, std::string bullet_path)
{
//    this->pos_x = itofix(x);
//    this->pos_y = itofix(y);
//    this->speed_vector = itofix(1);
//    this->angle = itofix(0);
//    this->HP = HP;
//    this->fire = false;
//    this->moviendo = false;
//    this->ship = load_bitmap("assets/NPCs/enemyBlue3_right.bmp", NULL);
//    this->bullet = new Proyectil(pos_x,pos_y, bullet_path);
//
//    std::cout << x << ", " << y << std::endl;
}

NPC::NPC()
{

}

void NPC::logic(fixed target_x, fixed target_y, Camera* cam)
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
        if((fixtoi(bullet->pos_x) - cam->cameraX) < (SCREEN_W) && (fixtoi(bullet->pos_x) - cam->cameraX) > 0
           && (fixtoi(bullet->pos_y) - cam->cameraY) < (SCREEN_H) && (fixtoi(bullet->pos_y) - cam->cameraY) > 0)
        {
            bullet->mover(itofix(20), angle);
        }

        else
        {
            bullet->actualizar_pos(pos_x+itofix(20), pos_y+itofix(20));
        }
    }

    else
    {
        bullet->actualizar_pos(pos_x, pos_y);
    }
}

void NPC::draw(BITMAP* canvas, Camera* cam)
{
    rotate_sprite(canvas, ship, fixtoi(pos_x) - cam->cameraX, fixtoi(pos_y) - cam->cameraY, angle);
    if(fire)
    {
        rotate_sprite(canvas, bullet->proyectil, fixtoi(bullet->pos_x) - cam->cameraX, fixtoi(bullet->pos_y) - cam->cameraY, angle);
    }
}

void NPC::destroy_sprites()
{
    destroy_bitmap(ship);
}

NPC::~NPC()
{

}
