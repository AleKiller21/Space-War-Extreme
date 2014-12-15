#include "GameManager.h"

GameManager::GameManager(std::list<NPC*>* npcs, MainMenu* menu, Jugador* ship)
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
    this->jugador = ship;
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
    allegro_message("You beat all the enemy ships!");
    allegro_message("Get ready for level: %d", nivel);
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
                   npc_s->push_back(new NPCRed5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/Green.bmp", ship2));
                   break;
                }

            case 3:
                {
                    npc_s->push_back(new NPCBlack1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserRed03.bmp", ship3));
                    break;
                }

            case 4:
                {
                    npc_s->push_back(new NPCBlue1(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp", ship4));
                    break;
                }

            case 5:
                {
                    npc_s->push_back(new NPCBlack2(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserRed03.bmp", ship5));
                    break;
                }

            case 6:
                {
                    npc_s->push_back(new NPCGreen4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/Green.bmp", ship6));
                    break;
                }

            case 7:
                {
                    npc_s->push_back(new NPCRed4(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserRed03.bmp", ship7));
                    break;
                }

            case 8:
                {
                    npc_s->push_back(new NPCGreen5(npc_random_pos_x(), npc_random_pos_y(), 1, "assets/Proyectil/NPCs/Green.bmp", ship8));
                    break;
                }
        }
    }
    turno_npc++;
    if(turno_npc > 8)
        turno_npc = 1;
    //std::cout << "Nivel: " << nivel << std::endl;
}

void GameManager::monitorear_estado_npc_lista()
{
    if(npc_s->size() == 0 && menu->isActive == false)
    {
        iniciar_nuevo_nivel();
    }
}

void GameManager::guardar_score()
{
    int scores[4];
    for(int i = 0; i < 4; i++)
        scores[i] = 0;
    int iterador = 0;
    int num = jugador->score;
    std::ifstream in("save", std::ios::ate);
    if(in != NULL)
    {
        int finale = in.tellg();
        int x;
        in.seekg(0);
        while(in.tellg() < finale)
        {
            in.read((char*)&x, 4);
            scores[iterador++] = x;
        }
        in.close();

        scores[3] = num;
        for(int i = 0; i < 4; i++)
        {
            for(int x = 0; x < 3; x++)
            {
                if(scores[x] < scores[x+1])
                {
                    int temp = scores[x];
                    scores[x] = scores[x+1];
                    scores[x+1] = temp;
                }
            }
        }

        std::ofstream out("save");
        int pos;
        for(int i = 0; i < 3; i++)
        {
            pos = scores[i];
            out.write((char*)&pos, 4);
        }
        out.close();

        std::ifstream ino("save", std::ios::ate);
        int last = ino.tellg();
        ino.seekg(0);
        int numero;
        while(ino.tellg() < last)
        {
            ino.read((char*)&numero, 4);
            //std::cout << numero << std::endl;
        }
        ino.close();
    }

    else
    {
        in.close();
        std::ofstream out("save");
        out.write((char*)&num, 4);
        out.close();
    }
}

void GameManager::monitorear_estado_jugador()
{
    if(jugador->HP <= 0)
    {
        this->nivel = 1;
        this->cantidad_enemigos_nivel = 10;
        this->turno_npc = 2;
        menu->isActive = true;
        jugador->HP = 200;
        for(npc_actual = npc_s->begin(); npc_actual != npc_s->end(); npc_actual++)
        {
            delete *npc_actual;
            npc_s->erase(npc_actual);
        }
        guardar_score();
        jugador->score = 0;
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
