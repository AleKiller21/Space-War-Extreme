#ifndef NIVEL_H
#define NIVEL_H
#include <list>
#include "NPC.h"
class Nivel
{
    public:
        int score;
        int cantidad_enemigos;
        Nivel(int* score_actual, int cantidad_enemigos, std::list<NPC*>* npc);
        virtual ~Nivel();
    protected:
    private:
};

#endif // NIVEL_H
