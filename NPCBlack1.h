#ifndef NPCBLACK1_H
#define NPCBLACK1_H
#include "NPC.h"


class NPCBlack1 : public NPC
{
    public:
        NPCBlack1(int x, int y, int HP, std::string bullet_path, BITMAP* sprite);
        virtual ~NPCBlack1();
    protected:
    private:
};

#endif // NPCBLACK1_H
