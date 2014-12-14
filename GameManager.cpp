#include "GameManager.h"

GameManager::GameManager(std::list<NPC*>* npcs, MainMenu* menu)
{
    this->npc_s = npcs;
    this->nivel = 1;
    this->cantidad_enemigos_nivel = 10;
    this->turno_npc = 2;
    this->menu = menu;
    this->ship1 = load_bitmap("assets/NPCs/enemyBlue3.bmp", NULL);
    this->ship2 = load_bitmap("assets/NPCs/enemyRed5.bmp", NULL);
    this->ship3 = load_bitmap("assets/NPCs/enemyBlack1.bmp", NULL);
    this->ship4 = load_bitmap("assets/NPCs/enemyBlue1.bmp", NULL);
    this->ship5 = load_bitmap("assets/NPCs/enemyBlack2.bmp", NULL);
    this->ship6 = load_bitmap("assets/NPCs/enemyGreen4.bmp", NULL);
    this->ship7 = load_bitmap("assets/NPCs/enemyRed4.bmp", NULL);
    this->ship8 = load_bitmap("assets/NPCs/enemyGreen5.bmp", NULL);
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
                    npc_s->push_back(new NPCBlue3(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship1));
                    break;
                }

            case 2:
                {
                   npc_s->push_back(new NPCRed5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship2));
                   break;
                }

            case 3:
                {
                    npc_s->push_back(new NPCBlack1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship3));
                    break;
                }

            case 4:
                {
                    npc_s->push_back(new NPCBlue1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship4));
                    break;
                }

            case 5:
                {
                    npc_s->push_back(new NPCBlack2(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship5));
                    break;
                }

            case 6:
                {
                    npc_s->push_back(new NPCGreen4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship6));
                    break;
                }

            case 7:
                {
                    npc_s->push_back(new NPCRed4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship7));
                    break;
                }

            case 8:
                {
                    npc_s->push_back(new NPCGreen5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship8));
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
    if(npc_s->size() == 0 && menu->isActive == false)
    {
        allegro_message("You beat all the enemy ships!");
        allegro_message("Get ready for next level");
        iniciar_nuevo_nivel();
    }
}

void GameManager::monitorear_estado_jugador(Jugador* ship)
{
    if(ship->HP <= 0)
    {
        this->nivel = 1;
        this->cantidad_enemigos_nivel = 10;
        this->turno_npc = 2;
        menu->isActive = true;
        ship->HP = 200;
        for(npc_actual = npc_s->begin(); npc_actual != npc_s->end(); npc_actual++)
        {
            delete *npc_actual;
            npc_s->erase(npc_actual);
        }
    }
}

void GameManager::cargar_primera_vez()
{
    for(int i = 0; i < 10; i++)
    {
        npc_s->push_back(new NPCBlue3(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship1));;
    }
}

GameManager::~GameManager()
{
    //dtor
}
