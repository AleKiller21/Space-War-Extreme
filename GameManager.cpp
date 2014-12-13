#include "GameManager.h"

GameManager::GameManager(std::list<NPC*>* npcs)
{
    this->nivel_terminado = true;
    this->npc_s = npcs;
    this->nivel = 1;
    this->cantidad_enemigos_nivel = 10;
    this->juego_iniciado = false;
    this->turno_npc = 2;
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
        return 2560;
    }
}

int GameManager::npc_random_pos_y()
{
    return (rand()%1600);
}

void GameManager::iniciar_nuevo_nivel()
{
    nivel++;
    this->cantidad_enemigos_nivel*= nivel;
    for(int i = 0; i < cantidad_enemigos_nivel; i++)
    {
        switch(turno_npc)
        {
            case 1:
                {
                    npc_s->push_back(new NPCBlue3(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 2:
                {
                   npc_s->push_back(new NPCRed5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                   break;
                }

            case 3:
                {
                    npc_s->push_back(new NPCBlack1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 4:
                {
                    npc_s->push_back(new NPCBlue1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 5:
                {
                    npc_s->push_back(new NPCBlack2(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 6:
                {
                    npc_s->push_back(new NPCGreen4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 7:
                {
                    npc_s->push_back(new NPCRed4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }

            case 8:
                {
                    npc_s->push_back(new NPCGreen5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
                    break;
                }
        }
    }
    turno_npc++;
    if(turno_npc > 8)
        turno_npc = 1;
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
