#include <iostream>
#include <vector>
#include <cstdlib>
#include "GameSceen.h"
#include "GameOver.h"

GameSceen::GameSceen(int width, int height)
    : screenWidth(width), screenHeight(height), score(0), snake(screenWidth / 2, screenHeight / 2)
{
    screenBuffer = new char[screenWidth * screenHeight];
    snake.isHead = true;
    fruit = new Fruit(screenWidth, screenHeight);
}

GameSceen::~GameSceen()
{
    delete[] screenBuffer;
    delete fruit;
}

void GameSceen::InitScreenBuf()
{
    for (int i = 0; i < screenWidth * screenHeight; i++)
    {
        screenBuffer[i] = ' ';
    }
}

void GameSceen::ShowScreenBuf()
{
    for (int i = 0; i < screenWidth; i++)
    {
        screenBuffer[i] = '*';
    }

    for (int i = 1; i < screenHeight - 1; i++)
    {
        screenBuffer[i * screenWidth] = '*';
        screenBuffer[i * screenWidth + screenWidth - 1] = '*';
    }

    for (int i = 0; i < screenWidth; i++)
    {
        screenBuffer[(screenHeight - 1) * screenWidth + i] = '*';
    }

    
    screenBuffer[snake.GetY() * screenWidth + snake.GetX()] = '*';
    screenBuffer[fruit->GetY() * screenWidth + fruit->GetX()] = '@';
    ShowTail(&snake);
}

void GameSceen::Draw()
{
    ShowScreenBuf();
    for (int i = 0; i < screenHeight; i++)
    {
        for (int j = 0; j < screenWidth; j++)
        {
            std::cout << screenBuffer[i * screenWidth + j];
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;

    if (isGameOver)
    {
        
    }
}
void GameSceen::CheckCollision()
{
    if (snake.GetX() == fruit->GetX() && snake.GetY() == fruit->GetY())
    {
        score++;
        snake.AddTail(&snake);
        delete fruit;
        fruit = new Fruit(screenWidth, screenHeight);
    }
}

void Snake::AddTail(Snake *head)
{
    if (head -> tail == nullptr)
    {
        head->tail = new Snake(head->GetX(), head->GetY());
        head->tail->isSpawn = true;
        head->tail->body = head;
        head->tail->tail = nullptr;
        head->tail->isHead = false;
    }
    else
    {
        AddTail(head->tail);
    }
}

void Snake::MoveTail(Snake *head)
{
    if (head->tail == nullptr )
    {
        return;
    }
    MoveTail(head->tail);
    if (head->isSpawn == false)
    {
        head->tail->x = head->GetX();
        head->tail->y = head->GetY();
    }
    else if(head->isSpawn == true)
    {
        head->isSpawn = false;
    }
    
}
void GameSceen::ShowTail(Snake* head)
{
    if (head->tail == nullptr)
    {
        return;
    }
    screenBuffer[head->tail->GetY() * screenWidth + head->tail->GetX()] = '*';
    ShowTail(head->tail);
}
void GameSceen::MoveSnakeUp()
{
    snake.MoveTail(&snake);
    snake.MoveUp();
    CheckCollision();
}

void GameSceen::MoveSnakeDown()
{
    snake.MoveTail(&snake);
    snake.MoveDown();
    CheckCollision();
}

void GameSceen::MoveSnakeLeft()
{
    snake.MoveTail(&snake);
    snake.MoveLeft();
    CheckCollision();
}

void GameSceen::MoveSnakeRight()
{
    snake.MoveTail(&snake);
    snake.MoveRight();
    CheckCollision();
}

Snake::Snake(int startX, int startY)
    : x(startX), y(startY)
{
}

void Snake::MoveUp()
{
    y--;
}

void Snake::MoveDown()
{
    y++;
}

void Snake::MoveLeft()
{
    x--;
}

void Snake::MoveRight()
{
    x++;
}

int Snake::GetX() const
{
    return x;
}

int Snake::GetY() const
{
    return y;
}

bool GameSceen::CheckBoundary()
{
    int snakeX = snake.GetX();
    int snakeY = snake.GetY();

    // 테두리에 닿았을 때 게임 종료
    if (snakeX == 0 || snakeX == screenWidth - 1 || snakeY == 0 || snakeY == screenHeight - 1)
    {
        isGameOver = true;
        return true;
    }
    return false;
}

void Snake::SnakeMove()
{
    x = 50 / 2;
    y = 25 / 2;
}
