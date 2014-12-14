#ifndef MAINMENU_H
#define MAINMENU_H
#include <allegro.h>
#include <iostream>
#include <alpng.h>

class MainMenu
{
    public:
        BITMAP* main_menu;
        BITMAP* buffer;
        BITMAP* cursor_ship;
        bool isActive;
        MainMenu();
        void showMenu(int mouse_x, int mouse_y);
        virtual ~MainMenu();
    protected:
    private:
};

#endif // MAINMENU_H
