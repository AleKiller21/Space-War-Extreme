#include "MainMenu.h"

MainMenu::MainMenu()
{
    this->main_menu = load_png("assets/MainMenu/space.png", NULL);
    this->btn_play = load_png("assets/MainMenu/play.png", NULL);
    this->btn_play_hover = load_png("assets/MainMenu/play_hover.png", NULL);
    this->btn_options = load_png("assets/MainMenu/options.png", NULL);
    this->btn_options_hover = load_png("assets/MainMenu/options_hover.png", NULL);
    this->btn_exit = load_png("assets/MainMenu/exit.png", NULL);
    this->btn_exit_hover = load_png("assets/MainMenu/exit_hover.png", NULL);

    if(main_menu == NULL || btn_play == NULL || btn_play_hover == NULL || btn_options == NULL || btn_options_hover == NULL || btn_exit == NULL || btn_exit_hover == NULL)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Could not load sprite's menu!");
        exit(EXIT_FAILURE);
    }
}

void MainMenu::eliminarMenu()
{
    destroy_bitmap(main_menu);
    destroy_bitmap(btn_play);
    destroy_bitmap(btn_play_hover);
    destroy_bitmap(btn_options);
    destroy_bitmap(btn_options_hover);
    destroy_bitmap(btn_exit);
    destroy_bitmap(btn_exit_hover);
}

void MainMenu::showMenu(BITMAP* canvas)
{
    draw_trans_sprite(canvas, main_menu,0,0);
}

void MainMenu::iniciarJuego()
{

}

MainMenu::~MainMenu()
{
    //dtor
}
