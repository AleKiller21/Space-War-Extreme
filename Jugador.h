#ifndef JUGADOR_H
#define JUGADOR_H
#include <allegro.h>
#include <alpng.h>
#include <math.h>
#include <list>
#include "Proyectil.h"
#include "NPC.h"
#include "Camera.h"
#include "Audio.h"

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
    int vidas;
    bool fire;
    bool moviendo;
    int score;

    Jugador(int x, int y);
    void logic(std::list<NPC*>* npc, Camera* cam);//NPC* npc
    void draw(BITMAP* canvas, Camera* cam);
    void check_collision(std::list<NPC*>* npc);//NPC* npc
    void destroy_sprites();
    virtual ~Jugador();
protected:
private:
};

#endif // JUGADOR_H
