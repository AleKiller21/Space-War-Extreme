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
int worldWidth = 2560;
int worldHeight = 1600;
int background_pos_x = 0;
int background_pos_y = 0;

void initiate()
{
    allegro_init();
    install_timer();
    install_mouse();
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


int main(int argc, char * argv[])
{
    std::list<NPC*> npcs;
    srand(time(0));
    initiate();
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));
    set_alpha_blender();
    Jugador ship(worldWidth/2,worldHeight/2);
    Camera cam(worldWidth, worldHeight);
    Audio audio("assets/Music/sound.wav");
    MainMenu menu;
    GameManager manager(&npcs, &menu);

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);

    BITMAP* background = load_png("assets/Background/background.png", NULL);
    BITMAP* buffer = create_bitmap(worldWidth,worldHeight);
    BITMAP* mouse_sprite = load_png("assets/cursor.png", NULL);

    set_mouse_sprite(mouse_sprite);
    mouse_x;
    mouse_y;

    //set_alpha_blender();

    while(!key[KEY_ESC])
    {
//-------------------LOGIC----------------------------
        if(menu.isActive)
        {
            audio.stop();
            menu.showMenu(mouse_x, mouse_y);
            menu.isActive = false;
            speed_counter = 0;
            audio.play();
            manager.cargar_primera_vez();
        }
        while(speed_counter > 0)
        {
            for(std::list<NPC*>::iterator i = npcs.begin(); i != npcs.end(); i++)
            {
                (*i)->logic(ship.pos_x, ship.pos_y, &cam);
            }
            ship.logic(&npcs, &cam);
            manager.monitorear_estado_npc_lista();
            manager.monitorear_estado_jugador(&ship);
            speed_counter--;
        }

//-------------------DRAWING----------------------------
        draw_trans_sprite(buffer, background, background_pos_x - cam.cameraX,background_pos_y - cam.cameraY);
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
    show_mouse(NULL);
    destroy_bitmap(buffer);
    destroy_bitmap(background);

    return 0;
}
END_OF_MAIN()

