#include "Camera.h"

Camera::Camera(int worldWidth, int worldHeight)
{
    this->worldWidth = worldWidth;
    this->worldHeight = worldHeight;
    this->cameraX = 0;
    this->cameraY = 0;
}

Camera::~Camera()
{
    //dtor
}
