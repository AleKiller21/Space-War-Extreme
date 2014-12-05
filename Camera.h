#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
        int worldWidth;
        int worldHeight;
        int cameraX;
        int cameraY;
        Camera(int worldWidth, int worldHeight);
        virtual ~Camera();
    protected:
    private:
};

#endif // CAMERA_H
