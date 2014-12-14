#ifndef NPCBLACK2_H
#define NPCBLACK2_H

#include "NPC.h"


class NPCBlack2 : public NPC
{
    public:
        NPCBlack2(int x, int y, int HP, std::string bullet_path, BITMAP* sprite);
        virtual ~NPCBlack2();
    protected:
    private:
};

#endif // NPCBLACK2_H
