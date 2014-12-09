#include "Nivel.h"

Nivel::Nivel(int* score_actual, int cantidad_enemigos, std::list<NPC*>* npc)
{
    this->score = *score_actual;
    this->cantidad_enemigos = cantidad_enemigos;

//    for(int i = 0; i < cantidad_enemigos; i++)
//    {
//        npc->push_back(new NPC(int x, int y, 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
//    }
}

Nivel::~Nivel()
{
    //dtor
}
