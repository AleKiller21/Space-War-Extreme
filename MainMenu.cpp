#include "MainMenu.h"

MainMenu::MainMenu()
{
    //this->main_menu = load_png("assets/MainMenu/Main_menu.png", NULL);
    this->isActive = true;
    this->buffer = create_bitmap(1280,720);
}

void MainMenu::showMenu(int mouse_x, int mouse_y)
{
    this->main_menu = load_png("assets/MainMenu/Main_menu.png", NULL);
    while(!key[KEY_ENTER])
    {
        draw_sprite(buffer, main_menu,0,0);
        show_mouse(buffer);
        blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);
    }
    destroy_bitmap(main_menu);
}

MainMenu::~MainMenu()
{
    //dtor
}
