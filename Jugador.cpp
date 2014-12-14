#include "Jugador.h"

Jugador::Jugador(int x, int y)
{
    this->HP = 200;
    this->pos_x = itofix(x);
    this->pos_y = itofix(y);
    this->ship = load_bitmap("assets/Jugador/naves_principales/player.bmp", NULL);
    this->bullet = new Proyectil(pos_x,pos_y, "assets/Proyectil/NPCs/laserRed03.bmp");
    this->speed_vector = itofix(1);
    this->fire = false;
    this->angle = itofix(0);
    this->moviendo = false;
    this->vidas = 3;
    this->score = 0;

    if(ship == NULL)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Ship's sprite couln't load correctly!");
        exit(EXIT_FAILURE);
    }
}

//TODO EL CODIGO ESTABA FUERA DEL FOR, SOLO RECIBIA DE PARAMETRO LA DIRECCION DE UN NPC. ESTO ERA PARA EVITAR METER AL JUGADOR EN EL
//FOR DEL LOOP DEL MAIN! TAMBIEN SE MODIFICO EL PARAMETRO DE LOGIC EL CUAL TAMBIEN SOLO RECIBIA LA DIRECCION DE UN NPC.
void Jugador::check_collision(std::list<NPC*>* npc)
{
    for(std::list<NPC*>::iterator i = npc->begin(); i != npc->end(); i++)
    {
        int bb_top = fixtoi(pos_y);
        int bb_bottom = (fixtoi(pos_y) + ship->h);
        int bb_left = fixtoi(pos_x);
        int bb_right = (fixtoi(pos_x) + ship->w);

        int npc_bb_top = fixtoi((*i)->pos_y);
        int npc_bb_bottom = fixtoi((*i)->pos_y) + (*i)->ship->h;
        int npc_bb_left = fixtoi((*i)->pos_x);
        int npc_bb_right = fixtoi((*i)->pos_x) + (*i)->ship->w;

        int bullet_bb_top = fixtoi(bullet->pos_y);
        int bullet_bb_bottom = fixtoi(bullet->pos_y) + bullet->proyectil->h;
        int bullet_bb_left = fixtoi(bullet->pos_x);
        int bullet_bb_right = fixtoi(bullet->pos_x) + bullet->proyectil->w;

        int npc_bullet_bb_top = fixtoi((*i)->bullet->pos_y);
        int npc_bullet_bb_bottom = fixtoi((*i)->bullet->pos_y) + (*i)->bullet->proyectil->h;
        int npc_bullet_bb_left = fixtoi((*i)->bullet->pos_x);
        int npc_bullet_bb_right = fixtoi((*i)->bullet->pos_x) + (*i)->bullet->proyectil->w;

        if(bb_right >= npc_bb_left && bb_left <= npc_bb_right && bb_bottom >= npc_bb_top && bb_top <= npc_bb_bottom)
        {
            this->HP--;
            std::cout << "Colision por nave!" << "HP: " << this->HP << std::endl;
        }

        if((*i)->fire)
        {
            if(bb_right >= npc_bullet_bb_left && bb_left <= npc_bullet_bb_right && bb_bottom >= npc_bullet_bb_top && bb_top <= npc_bullet_bb_bottom)
            {
                this->HP--;
                std::cout << "Colision por tiro!" << "HP: " << this->HP << std::endl;
            }
        }

        if(fire)
        {
            if(bullet_bb_right >= npc_bb_left && bullet_bb_left <= npc_bb_right && bullet_bb_bottom >= npc_bb_top && bullet_bb_top <= npc_bb_bottom)
            {
                (*i)->HP--;
                if((*i)->HP <= 0)
                {
                    //(*i)->~NPC();
                    delete *i;
                    npc->erase(i);
                    score+= 20;
                }
                std::cout << "Atacando naves enemigas" << std::endl;
                std::cout << "Score: " << score << std::endl;
            }
        }

//    line(canvas, npc_bullet_bb_left, npc_bullet_bb_top, npc_bullet_bb_right, npc_bullet_bb_top, makecol(255,0,0));
//    line(canvas, npc_bullet_bb_left, npc_bullet_bb_bottom, npc_bullet_bb_right, npc_bullet_bb_bottom, makecol(255,0,0));
//    line(canvas, npc_bullet_bb_left, npc_bullet_bb_top, npc_bullet_bb_left, npc_bullet_bb_bottom, makecol(255,0,0));
//    line(canvas, npc_bullet_bb_right, npc_bullet_bb_top, npc_bullet_bb_right, npc_bullet_bb_bottom, makecol(255,0,0));
    }
}

void Jugador::logic(std::list<NPC*>* npc, Camera* cam)
{
    moviendo = false;
    if(key[KEY_A])
    {
        angle = (angle - itofix(3))&0xFFFFFF;
    }

    if(key[KEY_D])
    {
        angle = (angle + itofix(3))&0xFFFFFF;
    }

    if(key[KEY_W])
    {
        moviendo = true;
        speed_vector = ftofix(7);
        speed_vector+= ftofix(0.005);
    }

    if(key[KEY_S])
    {
        speed_vector = ftofix(-7);
        moviendo = true;
        speed_vector-= ftofix(0.005);
    }

    if(key[KEY_SPACE])
    {
        fire = true;
    }

    else
    {
        fire = false;
    }

    if(moviendo)
    {
        pos_x+= fmul(speed_vector, fcos(angle));
        pos_y+= fmul(speed_vector, fsin(angle));

    }

    if(cam->cameraX < 0)
    {
        cam->cameraX = 0;
    }

    if(cam->cameraY < 0)
    {
        cam->cameraY = 0;
    }

    if(cam->cameraX > (cam->worldWidth - SCREEN_W))
    {
        cam->cameraX = cam->worldWidth - SCREEN_W;
    }

    if(cam->cameraY > (cam->worldHeight - SCREEN_H))
    {
        cam->cameraY = cam->cameraY - SCREEN_H;
    }

    cam->cameraX = fixtoi(pos_x) - SCREEN_W/2;
    cam->cameraY = fixtoi(pos_y) - SCREEN_H/2;

    if(fixtoi(pos_x) < 0)
    {
        pos_x = itofix(0);
    }

    if(fixtoi(pos_x) > 2510)
    {
        pos_x = itofix(2510);
    }

    if(fixtoi(pos_y) < 0)
    {
        pos_y = itofix(0);
    }

    if(fixtoi(pos_y) > 1550)
    {
        pos_y = itofix(1550);
    }

    if(fire)
    {
        if((fixtoi(bullet->pos_x) - cam->cameraX) < (SCREEN_W-40) && (fixtoi(bullet->pos_x) - cam->cameraX) > 0
           && (fixtoi(bullet->pos_y) - cam->cameraY) < (SCREEN_H-40) && (fixtoi(bullet->pos_y) - cam->cameraY) > 0)
        {
            bullet->mover(itofix(40), angle);
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

    check_collision(npc);
}

void Jugador::draw(BITMAP* canvas, Camera* cam)
{
    rotate_sprite(canvas, ship, fixtoi(pos_x) - cam->cameraX, fixtoi(pos_y) - cam->cameraY, angle);
    if(fire)
    {
        rotate_sprite(canvas, bullet->proyectil, fixtoi(bullet->pos_x) - cam->cameraX, fixtoi(bullet->pos_y) - cam->cameraY, angle);
    }
}

void Jugador::destroy_sprites()
{
    destroy_bitmap(ship);
}

Jugador::~Jugador()
{
    delete bullet;
}
