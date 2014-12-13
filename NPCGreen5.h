#ifndef NPCGREEN5_H
#define NPCGREEN5_H
#include "NPC.h"


class NPCGreen5 : public NPC
{
    public:
        NPCGreen5(int x, int y, int HP, std::string bullet_path);
        virtual ~NPCGreen5();
    protected:
    private:
};

#endif // NPCGREEN5_H
