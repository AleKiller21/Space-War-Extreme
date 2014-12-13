#ifndef NPCRED5_H
#define NPCRED5_H
#include "NPC.h"


class NPCRed5 : public NPC
{
    public:
        NPCRed5(int x, int y, int HP, std::string bullet_path);
        virtual ~NPCRed5();
    protected:
    private:
};

#endif // NPCRED5_H
