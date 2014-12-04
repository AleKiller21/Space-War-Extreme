#ifndef NPC_H
#define NPC_H
#include <allegro.h>
#include <math.h>
#include "Proyectil.h"

class NPC
{
public:
    fixed pos_x;
    fixed pos_y;
    fixed speed_vector;
    fixed angle;
    int HP;
    bool fire;
    bool moviendo;
    BITMAP* ship;
    Proyectil* bullet;
    NPC(int x, int y, int HP);
    NPC();
    virtual void logic(fixed target_x, fixed target_y);
    virtual void draw(BITMAP* canvas);
    void destroy_sprites();
    virtual ~NPC();
    protected:
    private:
};

#endif // NPC_H
