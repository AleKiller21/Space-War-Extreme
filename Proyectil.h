#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <allegro.h>
#include <alpng.h>
#include <iostream>

//using namespace std;

class Proyectil
{
public:
    fixed pos_x;
    fixed pos_y;
    std::string path;
    BITMAP* proyectil;
    Proyectil(fixed x, fixed y, std::string path);
    void mover(fixed speed_vector, fixed angle);
    void actualizar_pos(fixed x, fixed y);
    virtual ~Proyectil();
    protected:
    private:
};

#endif // PROYECTIL_H
