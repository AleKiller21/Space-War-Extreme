#ifndef MAINMENU_H
#define MAINMENU_H
#include <allegro.h>
#include <iostream>
#include <fstream>
#include "alfont.h"
#include <alpng.h>

class MainMenu
{
    public:
        BITMAP* main_menu;
        BITMAP* buffer;
        BITMAP* cursor_ship;
        BITMAP* instructions;
        BITMAP* score;
        bool isActive;
        MainMenu();
        void showMenu();
        void showInstructions();
        void showScores();
        virtual ~MainMenu();
    protected:
    private:
};

#endif // MAINMENU_H
