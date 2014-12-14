#include "MainMenu.h"

MainMenu::MainMenu()
{
    this->isActive = true;
    this->buffer = create_bitmap(1280,720);
    this->cursor_ship = load_png("assets/green_cursor.png", NULL);
    set_alpha_blender();
}

void MainMenu::showMenu(int mouse_x, int mouse_y)
{
    bool menu = true;
    int posicion = 0;
    this->main_menu = load_png("assets/MainMenu/Main_menu.png", NULL);
    draw_sprite(buffer, main_menu,0,0);
    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);

    while(menu)
    {
        if(key[KEY_1])
        {
            clear_bitmap(buffer);
            draw_sprite(buffer, main_menu,0,0);
            draw_trans_sprite(buffer, cursor_ship,766,360);
            blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
            posicion = 1;
        }

        if(key[KEY_2])
        {
            clear_bitmap(buffer);
            draw_sprite(buffer, main_menu,0,0);
            draw_trans_sprite(buffer, cursor_ship,766,425);
            blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
            posicion = 2;
        }

        if(key[KEY_3])
        {
            clear_bitmap(buffer);
            draw_sprite(buffer, main_menu,0,0);
            draw_trans_sprite(buffer, cursor_ship,766,501);
            blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
            posicion = 3;
        }

        if(key[KEY_4])
        {
            clear_bitmap(buffer);
            draw_sprite(buffer, main_menu,0,0);
            draw_trans_sprite(buffer, cursor_ship,766,587);
            blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
            posicion = 4;
        }

        if(key[KEY_ENTER])
        {
            switch(posicion)
            {
                case 1:
                    menu = false;
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    exit(EXIT_SUCCESS);
            }
        }
    }
    destroy_bitmap(main_menu);
}

MainMenu::~MainMenu()
{
    //dtor
}
