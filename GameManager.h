#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <cstdlib>
#include <list>
#include <fstream>
#include "Jugador.h"
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
        int cantidad_enemigos_nivel;
        int nivel;
        int turno_npc;

        BITMAP* ship1;
        BITMAP* ship2;
        BITMAP* ship3;
        BITMAP* ship4;
        BITMAP* ship5;
        BITMAP* ship6;
        BITMAP* ship7;
        BITMAP* ship8;

        std::list<NPC*>*npc_s;
        std::list<NPC*>::iterator npc_actual;
        MainMenu* menu;
        Jugador* jugador;

        GameManager(std::list<NPC*>* npcs, MainMenu* menu, Jugador* ship);
        int npc_random_pos_x();
        int npc_random_pos_y();
        void iniciar_nuevo_nivel();
        void monitorear_estado_npc_lista();
        void monitorear_estado_jugador();
        void cargar_primera_vez();
        void guardar_score();
        virtual ~GameManager();
    protected:
    private:
};

#endif // GAMEMANAGER_H
