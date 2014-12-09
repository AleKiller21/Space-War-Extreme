#include "Audio.h"

Audio::Audio(std::string path)
{
    this->panning = 128;
    this->pitch = 1000;
    this->volume = 128;
    this->sample = load_sample(path.c_str());

    if (sample == NULL)
    {
        allegro_message("Error reading wave file");
    }
}

void Audio::play()
{
    play_sample(sample, volume, panning, pitch, TRUE);
}

Audio::~Audio()
{
    //dtor
}
