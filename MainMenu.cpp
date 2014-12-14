#include "MainMenu.h"

MainMenu::MainMenu()
{
    this->isActive = true;
    this->buffer = create_bitmap(1280,720);
    this->cursor_ship = load_png("assets/green_cursor.png", NULL);
}

void MainMenu::showInstructions()
{
    this->instructions = load_png("assets/MainMenu/Instructions.png", NULL);
    clear_bitmap(buffer);
    draw_sprite(buffer, instructions,0,0);
    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while(true)
    {
        if(key[KEY_ESC])
        {
            destroy_bitmap(instructions);
            return;
        }
    }
}

void MainMenu::showMenu()
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
                    showScores();
                    draw_sprite(buffer, main_menu,0,0);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    break;

                case 3:
                    showInstructions();
                    draw_sprite(buffer, main_menu,0,0);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    break;

                case 4:
                    exit(EXIT_SUCCESS);
            }
        }
    }
    destroy_bitmap(main_menu);
}

void MainMenu::showScores()
{
    alfont_init();
    ALFONT_FONT* font = alfont_load_font("kenvector_future.ttf");
    alfont_set_font_size(font, 32);
    this->score = load_png("assets/MainMenu/Scores.png", NULL);
    int scores[3];
    int pos_x = 70;
    int pos_y = 266;
    int iterador = 0;
    clear_bitmap(buffer);
    draw_sprite(buffer, score,0,0);
    for(int i = 0; i < 3; i++)
        scores[i] = 0;

    std::ifstream in("save", std::ios::ate);
    if(in != NULL)
    {
        int last = in.tellg();
        int num;
        in.seekg(0);
        while(in.tellg() < last)
        {
            in.read((char*)&num, 4);
            scores[iterador++] = num;
        }
        in.close();

        for(int i = 0; i < 3; i++)
        {
            if(scores[i] > 0)
            {
                alfont_textprintf_ex(buffer, font, pos_x, pos_y, makecol(197,192,192), -1, "%d", scores[i]);
                pos_y+= 63;
            }
        }
    }

    else
        in.close();

    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while(true)
    {
        if(key[KEY_ESC])
        {
            destroy_bitmap(score);
            alfont_destroy_font(font);
            alfont_exit();
            return;
        }
    }
}

MainMenu::~MainMenu()
{

}
