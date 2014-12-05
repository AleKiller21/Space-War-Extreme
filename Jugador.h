#ifndef JUGADOR_H
#define JUGADOR_H
#include <allegro.h>
#include <alpng.h>
#include "Proyectil.h"
#include <math.h>
#include "NPC.h"
#include "Camera.h"

class Jugador
{
public:
    fixed pos_x;
    fixed pos_y;
    fixed speed_vector;
    fixed angle;
    BITMAP* ship;
    Proyectil* bullet;
    int HP;
    bool fire;
    bool moviendo;

    Jugador(int x, int y);
    void logic(NPC* npc, Camera* cam);
    void draw(BITMAP* canvas, Camera* cam);
    void check_collision(NPC* npc);
    void destroy_sprites();
    virtual ~Jugador();
protected:
private:
};

#endif // JUGADOR_H
