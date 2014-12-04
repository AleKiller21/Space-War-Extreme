#include "Proyectil.h"

Proyectil::Proyectil(fixed x, fixed y, std::string path)
{
    this->pos_x = x;
    this->pos_y = y;
    this->path = path;
    proyectil = load_bitmap(path.c_str(), NULL);

    if(proyectil == NULL)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Proyectile sprite couln't loaded!");
        exit(EXIT_FAILURE);
    }
}

void Proyectil::mover(fixed speed_vector, fixed angle)
{
    this->pos_x+= fmul(speed_vector, fcos(angle));
    this->pos_y+= fmul(speed_vector, fsin(angle));
}

void Proyectil::actualizar_pos(fixed x, fixed y)
{
    this->pos_x = x;
    this->pos_y = y;
}

Proyectil::~Proyectil()
{
    destroy_bitmap(proyectil);
}
