#ifndef NPCBLUE1_H
#define NPCBLUE1_H
#include "NPC.h"


class NPCBlue1 : public NPC
{
    public:
        NPCBlue1(int x, int y, int HP, std::string bullet_path, BITMAP* sprite);
        virtual ~NPCBlue1();
    protected:
    private:
};

#endif // NPCBLUE1_H
