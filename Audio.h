#ifndef AUDIO_H
#define AUDIO_H
#include <allegro.h>
#include <iostream>

class Audio
{
    public:
        int panning;
        int pitch;
        int volume;
        SAMPLE* sample;
        Audio(std::string path);
        void play();
        void stop();
        virtual ~Audio();
    protected:
    private:
};

#endif // AUDIO_H
