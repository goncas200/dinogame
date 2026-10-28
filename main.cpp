/*
    Dino game in C++
    main.cpp
*/
#include <raylib.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector>

#define WINDOWWIDTH 1000
#define WINDOWHEIGHT 800
#define FPS 120

#define GroundStartPos (Vector2) {0, 700}

inline void DrawRectanglePos(Vector2 pos, int width, int height, Color color) {
    DrawRectangle(pos.x, pos.y, width, height, color);
}

class dinoobj {
public:
    const int x = 10;
    const int y = 640;
    const int width = 40;
    const int height = 60;
    
    void draw(bool night) {
        if (night)
            DrawRectangle(this->x, this->y, this->width, this->height, WHITE);
        else 
            DrawRectangle(this->x, this->y, this->width, this->height, BLACK);
    }

};

int main() {
    int fd = open("/dev/null", O_WRONLY);
    dup2(fd, 1);
    dup2(fd, 2);
    close(fd);
    
    bool night = false;
    int clock_fps = 0;

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Dino");

    SetTargetFPS(FPS);

    dinoobj dino; 

    while (!WindowShouldClose()) {

        if (clock_fps == 120*1) {
            night = !night;
            clock_fps = 0;
        }
        else
            ++clock_fps;

        BeginDrawing();
        if (!night) {
            ClearBackground(WHITE);
            DrawRectanglePos(GroundStartPos, WINDOWWIDTH, 5, BLACK);
        }
        if (night) {
            ClearBackground(BLACK);
            DrawRectanglePos(GroundStartPos, WINDOWWIDTH, 5, WHITE);
        }
        dino.draw(night);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}