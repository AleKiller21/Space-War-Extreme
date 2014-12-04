#include <allegro.h>
#include <iostream>
#include <alpng.h>
#include <cstdlib>
#include <time.h>
#include "Jugador.h"
#include "NPC.h"
#include <math.h>

//using namespace std;

volatile long speed_counter = 0;
//int screen_width = 1200;
//int screen_height = 720;


void initiate()
{
    allegro_init();
    install_timer();
    install_mouse();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0);
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

int npc_random_pos_x()
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
        return (SCREEN_W-80);
    }
}

int npc_random_pos_y()
{
    return (rand()%(SCREEN_H-80));
}

int main(int argc, char * argv[])
{
    srand(time(0));
    initiate();
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));
    set_alpha_blender();

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);

    BITMAP* background = load_png("assets/Background/Background-4.png", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
    Jugador ship(300,300);
    //int y = npc_random_pos_y();
    NPC npc(npc_random_pos_x(),npc_random_pos_y(),100);
    //std:: cout << y << std::endl;

    while(!key[KEY_ESC])
    {
//-------------------LOGIC----------------------------
        while(speed_counter > 0)
        {
            ship.logic(&npc);
            npc.logic(ship.pos_x, ship.pos_y);
            speed_counter--;
        }

//-------------------DRAWING----------------------------
        draw_sprite(buffer, background, 0,0);

        ship.draw(buffer);
        npc.draw(buffer);
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

