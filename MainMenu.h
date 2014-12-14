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
        BITMAP* instructions;
        bool isActive;
        MainMenu();
        void showMenu();
        void showInstructions();
        virtual ~MainMenu();
    protected:
    private:
};

#endif // MAINMENU_H
