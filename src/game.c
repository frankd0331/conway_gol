#include "raylib.h"

typedef enum Cell {
    EMPTY,
    ALIVE,
    DEAD
} Cell;

Cell current[500][500];
Cell next[500][500];

Texture2D texture;
int pauseToggle = 0;

int main(void)
{
    for(int x=0; x<500; x++){
        for(int y=0; y<500; y++){
            current[x][y] = next[x][y] = GetRandomValue(0, 1);
        }
    }
    InitWindow(500, 500, "raylib [core] example - basic window");
    texture = LoadTexture("assets/pyramid.png");
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        //DrawFPS(10, 10);
        
        if(IsKeyPressed(KEY_R)){
            for(int x=0; x<500; x++){
                for(int y=0; y<500; y++){
                    int random = GetRandomValue(0, 100);
                    current[x][y] = next[x][y] = random <= 25 ? ALIVE : EMPTY;
                }
            }
        }
        
        if(IsKeyPressed(KEY_A)){
            for(int x=0; x<500; x++){
                for(int y=0; y<500; y++){
                    current[x][y] = next[x][y] = EMPTY;
                }
            }
            current[252][251]=ALIVE;
            current[254][252]=ALIVE;
            current[251][253]=ALIVE;
            current[252][253]=ALIVE;
            current[255][253]=ALIVE;
            current[256][253]=ALIVE;
            current[257][253]=ALIVE;
        }
        
        if(IsKeyPressed(KEY_SPACE)){
            pauseToggle = !pauseToggle;
        }
    
        if(IsKeyPressed(KEY_S) || pauseToggle){
        for(int x=0; x<500; x++){
            for(int y=0; y<500; y++){
                int neighbours = 0;
                int topRow = x == 0 ? 499 : x-1;
                int middleRow = x;
                int bottomRow = x == 499 ? 0 : x+1;
                int leftColumn = y == 0 ? 499 : y-1;
                int middleColumn = y;
                int rightColumn = y == 499 ? 0 : y+1;
                if(current[topRow][leftColumn] == ALIVE){
                    neighbours++;
                }
                if(current[topRow][middleColumn] == ALIVE){
                    neighbours++;
                }
                if(current[topRow][rightColumn] == ALIVE){
                    neighbours++;
                }
                if(current[middleRow][leftColumn] == ALIVE){
                    neighbours++;
                }
                if(current[middleRow][rightColumn] == ALIVE){
                    neighbours++;
                }
                if(current[bottomRow][leftColumn] == ALIVE){
                    neighbours++;
                }
                if(current[bottomRow][middleColumn] == ALIVE){
                    neighbours++;
                }
                if(current[bottomRow][rightColumn] == ALIVE){
                    neighbours++;
                }
                if(current[x][y] == ALIVE){
                    if(neighbours < 2){
                        next[x][y] = DEAD;
                    } else if(neighbours == 2 || neighbours == 3){
                        next[x][y] = ALIVE;
                    } else if(neighbours > 3){
                        next[x][y] = DEAD;
                    }
                } else if(current[x][y] == DEAD || current[x][y] == EMPTY){
                    if(neighbours == 3){
                        next[x][y] = ALIVE;
                    }
                }
            }
        }
        for(int x=0; x<500; x++){
            for(int y=0; y<500; y++){
                current[x][y] = next[x][y];
            }
        }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(int x=0; x<500; x++){
            for(int y=0; y<500; y++){
                if(current[x][y] == ALIVE){
                    DrawPixel(x, y, BLACK);
                } else if(current[x][y] == EMPTY){
                    DrawPixel(x, y, RAYWHITE);
                } else if(current[x][y] == DEAD){
                    DrawPixel(x, y, GREEN);
                }
            }
        }
        EndDrawing();

    }
    CloseWindow();
    
    return 0;
}