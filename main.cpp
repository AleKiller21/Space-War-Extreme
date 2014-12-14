#include <allegro.h>
#include <iostream>
#include <alpng.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
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
    install_keyboard();
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
    std::list<BITMAP*> stars;
    int star_pos_x = 0;
    int star_pos_y = 0;

    int star_pos_x2 = worldWidth/2;
    int star_pos_y2 = worldHeight/2;

    int star_pos_x3 = 2000;
    int star_pos_y3 = 1400;

    int star_frame_counter = 0;

    srand(time(0));
    initiate();
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));
    set_alpha_blender();
    Jugador ship(worldWidth/2,worldHeight/2);
    Camera cam(worldWidth, worldHeight);
    Audio audio("assets/Music/sound.wav");
    MainMenu menu;
    GameManager manager(&npcs, &menu, &ship);

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);

    BITMAP* background = load_png("assets/Background/background.png", NULL);
    BITMAP* buffer = create_bitmap(worldWidth,worldHeight);

    set_alpha_blender();

    stars.push_back(load_png("assets/effects/star.png", NULL));
    stars.push_back(load_png("assets/effects/star2.png", NULL));
    stars.push_back(load_png("assets/effects/star3.png", NULL));
    stars.push_back(load_png("assets/effects/star4.png", NULL));

    std::list<BITMAP*>::iterator star_actual = stars.begin();

    while(!key[KEY_ESC])
    {
//-------------------LOGIC----------------------------
        if(menu.isActive)
        {
            audio.stop();
            menu.showMenu();
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
            manager.monitorear_estado_jugador();
            star_pos_x+=10;
            star_pos_x2+=10;
            star_pos_x3+=10;
            if(star_frame_counter%3 == 0)
                star_actual++;

            if(star_actual == stars.end())
                star_actual = stars.begin();

            if(star_pos_x > 2510)
            {
                star_pos_x = 0;
                star_pos_y = manager.npc_random_pos_y();
                std::cout << star_pos_y << std::endl;
            }

            if(star_pos_x2 > 2510)
            {
                star_pos_x2 = 0;
                star_pos_y2 = manager.npc_random_pos_y();
                std::cout << star_pos_y2 << std::endl;
            }

            if(star_pos_x3 > 2510)
            {
                star_pos_x3 = 0;
                star_pos_y3 = manager.npc_random_pos_y();
                std::cout << star_pos_y3 << std::endl;
            }

            star_frame_counter++;
            speed_counter--;
        }

//-------------------DRAWING----------------------------
        draw_trans_sprite(buffer, background, background_pos_x - cam.cameraX,background_pos_y - cam.cameraY);
        draw_trans_sprite(buffer, *star_actual, star_pos_x-cam.cameraX, star_pos_y-cam.cameraY);
        draw_trans_sprite(buffer, *star_actual, star_pos_x2-cam.cameraX, star_pos_y2-cam.cameraY);
        draw_trans_sprite(buffer, *star_actual, star_pos_x3-cam.cameraX, star_pos_y3-cam.cameraY);

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

