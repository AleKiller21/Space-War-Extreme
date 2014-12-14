#ifndef NPCBLUE3_H
#define NPCBLUE3_H
#include "NPC.h"

class NPCBlue3 : public NPC
{
    public:
        NPCBlue3(int x, int y, int HP, std::string bullet_path, BITMAP* sprite);
        virtual ~NPCBlue3();
    protected:
    private:
};

#endif // NPCBLUE3_H
