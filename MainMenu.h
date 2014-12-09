#ifndef MAINMENU_H
#define MAINMENU_H
#include <allegro.h>
#include <alpng.h>

class MainMenu
{
    public:
        BITMAP* main_menu;
        BITMAP* btn_play;
        BITMAP* btn_play_hover;
        //BITMAP* btn_score;
        //BITMAP* btn_score_hover;
        BITMAP* btn_options;
        BITMAP* btn_options_hover;
        BITMAP* btn_exit;
        BITMAP* btn_exit_hover;
        MainMenu();
        void iniciarJuego();
        void showMenu(BITMAP* canvas);
        void eliminarMenu();
        virtual ~MainMenu();
    protected:
    private:
};

#endif // MAINMENU_H
