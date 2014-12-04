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

    if(ship == NULL)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Ship's sprite couln't load correctly!");
        exit(EXIT_FAILURE);
    }
}

//void Jugador::rotate_trans_sprite(BITMAP* dest, BITMAP* source, int x, int y, fixed angle)
//{
//    float Ax = float(source->w);
//    float Ay = float(source->h);
//    float Bx = Ax;
//    float By = -Ay;
//    float c = cosf(fixtof(angle) / 128.0f * AL_PI);
//    float s = sinf(fixtof(angle) / 128.0f * AL_PI);
//    float Tx;
//    Tx = Ax;
//    Ax = c * Tx - s * Ay;
//    Ay = s * Tx + c * Ay;
//    Tx = Bx;
//    Bx = c * Tx - s * By;
//    By = s * Tx + c * By;
//    int max_width = fabs(Ax) > fabs(Bx) ? fabs(Ax) : fabs(Bx);
//    int max_height = fabs(Ay) > fabs(By) ? fabs(Ay) : fabs(By);
//    int devX = max_width - source->w;
//    devX /= 2;
//    int devY = max_height - source->h;
//    devY = max_height - source->h;
//    devY /= 2;
//
//    if(turno == 1)
//    {
//        this->rotate_buffer = create_bitmap(max_width, max_height);
//        rotate_sprite(rotate_buffer, source, devX, devY, angle);
//        draw_trans_sprite(dest, rotate_buffer, x - devX, y - devY);
//    }
//
//    else
//    {
//        this->rotate_buffer2 = create_bitmap(max_width, max_height);
//        rotate_sprite(rotate_buffer2, source, devX, devY, angle);
//        draw_trans_sprite(dest, rotate_buffer2, x - devX, y - devY);
//    }
//}

void Jugador::check_collision(NPC* npc)
{
    int bb_top = fixtoi(pos_y);
    int bb_bottom = (fixtoi(pos_y) + ship->h);
    int bb_left = fixtoi(pos_x);
    int bb_right = (fixtoi(pos_x) + ship->w);

    int npc_bb_top = fixtoi(npc->pos_y);
    int npc_bb_bottom = fixtoi(npc->pos_y) + npc->ship->h;
    int npc_bb_left = fixtoi(npc->pos_x);
    int npc_bb_right = fixtoi(npc->pos_x) + npc->ship->w;

    int bullet_bb_top = fixtoi(npc->bullet->pos_y);
    int bullet_bb_bottom = fixtoi(npc->bullet->pos_y) + npc->bullet->proyectil->h;
    int bullet_bb_left = fixtoi(npc->bullet->pos_x);
    int bullet_bb_right = fixtoi(npc->bullet->pos_x) + npc->bullet->proyectil->w;

    if(bb_right >= npc_bb_left && bb_left <= npc_bb_right && bb_bottom >= npc_bb_top && bb_top <= npc_bb_bottom)
    {
        this->HP--;
        std::cout << "Colision por nave!" << "HP: " << this->HP << std::endl;
    }

    if(npc->fire)
    {
        if(bb_right >= bullet_bb_left && bb_left <= bullet_bb_right && bb_bottom >= bullet_bb_top && bb_top <= bullet_bb_bottom)
        {
            this->HP--;
            std::cout << "Colision por tiro!" << "HP: " << this->HP << std::endl;
        }
    }

//    line(canvas, bullet_bb_left, bullet_bb_top, bullet_bb_right, bullet_bb_top, makecol(255,0,0));
//    line(canvas, bullet_bb_left, bullet_bb_bottom, bullet_bb_right, bullet_bb_bottom, makecol(255,0,0));
//    line(canvas, bullet_bb_left, bullet_bb_top, bullet_bb_left, bullet_bb_bottom, makecol(255,0,0));
//    line(canvas, bullet_bb_right, bullet_bb_top, bullet_bb_right, bullet_bb_bottom, makecol(255,0,0));
}

void Jugador::logic(NPC* npc)
{
    if(this->HP <= 0)
    {
        allegro_message("Game Over!");
        exit(EXIT_SUCCESS);
    }
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
        if(fixtoi(pos_x) < (SCREEN_W-80) && fixtoi(pos_x) > 0 && fixtoi(pos_y) < (SCREEN_H-80) && fixtoi(pos_y) > 0)
        {
            pos_x+= fmul(speed_vector, fcos(angle));
            pos_y+= fmul(speed_vector, fsin(angle));

        }

        else
        {
            if(fixtoi(pos_x) >= (SCREEN_W-80))
                pos_x = itofix(1);

            else if(fixtoi(pos_x) <= 0)
                pos_x = itofix(SCREEN_W-81);

            else if(fixtoi(pos_y) >= (SCREEN_H-80))
                pos_y = itofix(1);

            else if(fixtoi(pos_y) <= 0)
                pos_y = itofix(SCREEN_H-81);
        }
    }

    if(fire)
    {
        if(fixtoi(bullet->pos_x) < (SCREEN_W-40) && fixtoi(bullet->pos_x) > 0 && fixtoi(bullet->pos_y) < (SCREEN_H-40) && fixtoi(bullet->pos_y) > 0)
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

void Jugador::draw(BITMAP* canvas)
{
    rotate_sprite(canvas, ship, fixtoi(pos_x), fixtoi(pos_y), angle);
    if(fire)
    {
        rotate_sprite(canvas, bullet->proyectil, fixtoi(bullet->pos_x), fixtoi(bullet->pos_y), angle);
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
