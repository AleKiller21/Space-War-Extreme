#include "GameManager.h"

GameManager::GameManager(std::list<NPC*>* npcs)
{
    this->nivel_terminado = true;
    this->npc_s = npcs;
    this->nivel = 1;
    this->cantidad_enemigos_nivel = 10;
    this->juego_iniciado = false;
}

int GameManager::npc_random_pos_x()
{
    //0 - izquierda
    //1 - derecha
    int extremo_x = rand()%2;

    if(extremo_x == 0)
    {
        return 0;
    }

    else
    {
        return 2000;
    }
}

int GameManager::npc_random_pos_y()
{
    return (rand()%2000);
}

void GameManager::iniciar_nuevo_nivel()
{
    nivel++;
    this->cantidad_enemigos_nivel*= nivel;
    for(int i = 0; i < cantidad_enemigos_nivel; i++)
    {
        npc_s->push_back(new NPC(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
    }
    std::cout << "Nivel: " << nivel << std::endl;
}

void GameManager::monitorear_estado_npc_lista()
{
    if(npc_s->size() == 0)
    {
        allegro_message("You beat all the enemy ships!");
        allegro_message("Get ready for next level");
        iniciar_nuevo_nivel();
    }
}

GameManager::~GameManager()
{
    //dtor
}
