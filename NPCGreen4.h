#ifndef NPCGREEN4_H
#define NPCGREEN4_H
#include "NPC.h"


class NPCGreen4 : public NPC
{
    public:
        NPCGreen4(int x, int y, int HP, std::string bullet_path, BITMAP* sprite);
        virtual ~NPCGreen4();
    protected:
    private:
};

#endif // NPCGREEN4_H
