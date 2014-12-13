#include <allegro.h>
#include <iostream>
#include <alpng.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <list>
#include "Jugador.h"
#include "NPC.h"
#include "GameManager.h"
#include "Audio.h"
#include "MainMenu.h"


volatile long speed_counter = 0;
int worldWidth = 2000;
int worldHeight = 2000;
int background_pos_x = 0;
int background_pos_y = 0;


void initiate()
{
    allegro_init();
    install_timer();
    //install_mouse();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0);

    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0)
    {
        allegro_message("Error initializing sound system");
        return;
    }
}

void load_image_error()
{
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Failed to load bitmap.");
    exit(EXIT_FAILURE);
}

void increment_speed_counter()
{
    speed_counter++;
}
END_OF_FUNCTION(increment_speed_counter)

void showMenuScreen()
{

}

int main(int argc, char * argv[])
{
    std::list<NPC*> npcs;
    srand(time(0));
    initiate();
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));
    set_alpha_blender();
    Jugador ship(worldWidth/2,worldHeight/2);
    GameManager manager(&npcs);
    Camera cam(worldWidth, worldHeight);
    Audio audio("assets/sound.wav");
    MainMenu menu();

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);

    BITMAP* background = load_png("assets/Background/background2.png", NULL);
    BITMAP* buffer = create_bitmap(worldWidth,worldHeight);

    audio.play();

    for(int i = 0; i < 10; i++)
    {
        npcs.push_back(new NPCBlue3(manager.npc_random_pos_x(), manager.npc_random_pos_y(), 1, "assets/Proyectil/NPCs/laserBlue03.bmp"));
    }

    while(!key[KEY_ESC])
    {
//-------------------LOGIC----------------------------
        while(speed_counter > 0)
        {
            for(std::list<NPC*>::iterator i = npcs.begin(); i != npcs.end(); i++)
            {
                (*i)->logic(ship.pos_x, ship.pos_y, &cam);
            }
            ship.logic(&npcs, &cam);//&npc
            manager.monitorear_estado_npc_lista();
            speed_counter--;
        }

//-------------------DRAWING----------------------------
        draw_sprite(buffer, background, background_pos_x - cam.cameraX,background_pos_y - cam.cameraY);
        for(std::list<NPC*>::iterator i = npcs.begin(); i != npcs.end(); i++)
        {
            (*i)->draw(buffer, &cam);
        }
        ship.draw(buffer, &cam);
        blit(buffer, screen, 0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);
    }
//-------------------Destruction----------------------------
    ship.destroy_sprites();
    destroy_bitmap(buffer);
    destroy_bitmap(background);

    return 0;
}
END_OF_MAIN()

