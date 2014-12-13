#ifndef NPCRED4_H
#define NPCRED4_H
#include "NPC.h"


class NPCRed4 : public NPC
{
    public:
        NPCRed4(int x, int y, int HP, std::string bullet_path);
        virtual ~NPCRed4();
    protected:
    private:
};

#endif // NPCRED4_H
