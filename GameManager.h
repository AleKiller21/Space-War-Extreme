#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <cstdlib>
#include <list>
//#include "NPC.h"
#include "MainMenu.h"
#include "NPCBlue3.h"
#include "NPCBlack1.h"
#include "NPCBlack2.h"
#include "NPCBlue1.h"
#include "NPCGreen4.h"
#include "NPCGreen5.h"
#include "NPCRed4.h"
#include "NPCRed5.h"

class GameManager
{
    public:
        bool nivel_terminado;
        int cantidad_enemigos_nivel;
        int nivel;
        int turno_npc;
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
