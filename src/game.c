#include "raylib.h"

Texture2D texture;

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    texture = LoadTexture("assets/pyramid.png");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawTexture(texture, 50, 50, WHITE);
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}