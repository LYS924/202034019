//#pragma once
#define GAMESCREEN_H

#include <vector>

struct TailPiece
{
    int x;
    int y;
    TailPiece* next;
    TailPiece* prev;
};
class Snake
{
public:
    Snake(int startX, int startY);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void AddTail(Snake *head);
    void MoveTail(Snake* head);
    int GetX() const;
    int GetY() const;
    void SnakeMove();
    bool CheckCollisionTail(Snake *tail, int x, int y);
    Snake* tail;
    Snake* body;
    bool isHead;
    
private:
    int x;
    int y;
    bool isSpawn;
    
};
class Fruit
{
private:
    int x;
    int y;
public:
    Fruit(int maxX, int maxY)
    {
        srand(static_cast<unsigned int>(time(0)));
        x = rand() % (maxX - 2) + 1;
        y = rand() % (maxY - 2) + 1;
    }
    int GetX() const { return x; }
    int GetY() const { return y; }
};
class GameSceen
{
public:
    GameSceen(int width, int height);
    ~GameSceen();
    void InitScreenBuf();
    void ShowScreenBuf();
    void Draw();
    void ShowTail(Snake *head);
    void MoveSnakeUp();
    void MoveSnakeDown();
    void MoveSnakeLeft();
    void MoveSnakeRight();
    bool CheckBoundary();
    void CheckCollision();
    void Init();
    

private:
    char* screenBuffer;
    int screenWidth;
    int screenHeight;
    int score;
    std::vector<std::vector<char>> screen;
    Snake snake;
    Fruit *fruit;

};
