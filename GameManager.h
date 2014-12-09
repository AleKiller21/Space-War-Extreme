#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <cstdlib>
#include <list>
#include "NPC.h"

class GameManager
{
    public:
        bool nivel_terminado;
        int cantidad_enemigos_nivel;
        int nivel;
        bool juego_iniciado;
        std::list<NPC*>*npc_s;
        std::list<NPC*>::iterator npc_actual;

        GameManager(std::list<NPC*>* npcs);
        int npc_random_pos_x();
        int npc_random_pos_y();
        void iniciar_nuevo_nivel();
        void monitorear_estado_npc_lista();
        virtual ~GameManager();
    protected:
    private:
};

#endif // GAMEMANAGER_H
