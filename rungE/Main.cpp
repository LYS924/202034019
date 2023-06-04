#include <iostream>
#include <conio.h>
#include "GameMenu.h"
#include "GameSceen.h"
#include "GameOver.h"

#define KEY_ESC 27
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ENTER 13

int main()
{
    GameMenu gameMenu;
    GameOver gameOver;

    char Input;
    char lastInput = '\0';

    static bool isKeep = true;
    static bool isOver = false;
    static bool isExit = false;
    static bool isOut = false;

    bool gameRunning = true;
    bool menuRunning = true;

    int screenWidth = 50;
    int screenHeight = 25;
    GameSceen gameScreen(screenWidth, screenHeight);
    int gameStatus = 0;

    while (gameRunning)
    {
        if (menuRunning)
        {
            gameMenu.PrintMenu();
            menuRunning = false; 
        }
        gameMenu.SetCursorState(false);
        Input = gameMenu.GetInput();
        if (Input != lastInput)
        {
            if (gameStatus == 0)
            {
                switch (Input)
                {
                case KEY_DOWN:
                    isOut = true;
                    if (isKeep)
                    {
                        system("cls");
                        gameMenu.DownMenu();
                    }
                    if (isOver)
                    {
                        isOut = true;
                        system("cls");
                        gameOver.DownOver();
                    }
                    break;
                case KEY_UP:
                    isOut = false;
                    if (isKeep)
                    {
                        system("cls");
                        gameMenu.UpMenu();
                    }
                    if (isOver)
                    {
                        isOut = false;
                        system("cls");
                        gameOver.UpOver();
                    }
                    break;
                case KEY_ENTER:
                    system("cls");
                    if (!isOut)
                    {
                        isKeep = false;
                        gameScreen.InitScreenBuf();
                        gameScreen.Draw();
                        gameStatus = 1;
                        isExit = true;
                    }
                    if (isOut)
                    {
                        system("cls");
                        std::cout << "게임을 종료합니다." << std::endl;
                        gameRunning = false;
                    }
                    break;
                case KEY_ESC:
                    system("cls");
                    isOver = true;
                    if (isExit)
                    {
                        gameOver.PrintOver();
                    }
                    break;
                default:
                    break;
                }
            }
            else if(gameStatus == 1)
            {
                system("cls");
                switch (Input)
                {
                case 'w':
                    gameScreen.MoveSnakeUp();
                    break;
                case 's':
                    gameScreen.MoveSnakeDown();
                    break;
                case 'a':
                    gameScreen.MoveSnakeLeft();
                    break;
                case 'd':
                    gameScreen.MoveSnakeRight();
                    break;
                case KEY_ESC:
                    system("cls");
                    isOver = true;
                    gameStatus = 2;
                    if (isExit)
                    {
                        gameOver.PrintOver();
                    }
                    break;
                }
                if (isOver == false)
                {
                    gameScreen.InitScreenBuf();
                    gameScreen.Draw();
                    if (gameScreen.CheckBoundary())
                    {
                        system("cls");
                        gameOver.PrintOver();
                        gameStatus = 2;
                        isOver = true;
                        //gameScreen.snake.SnakeMove();
                        
                    }
                }
            }
            else if (gameStatus == 2)
            {
                switch (Input)
                {
                case KEY_DOWN:
                    isOut = true;
                    if (isOver)
                    {
                        isOut = true;
                        system("cls");
                        gameOver.DownOver();
                    }
                    break;
                case KEY_UP:
                    isOut = false;
                    if (isOver)
                    {
                        isOut = false;
                        system("cls");
                        gameOver.UpOver();
                    }
                    break;
                case KEY_ENTER:
                    if (!isOut)
                    {
                        system("cls");
                        isKeep = false;
                        gameScreen.InitScreenBuf();
                        gameScreen.Draw();
                        gameStatus = 1;
                        isExit = true;
                        isOver = false;
                    }
                    if (isOut)
                    {
                        system("cls");
                        std::cout << "게임을 종료합니다." << std::endl;
                        gameRunning = false;
                    }
                    break;
                }
            }
            
        }
        else
        {
            switch (Input)
            {
            case KEY_ENTER:
                system("cls");
                if (isOut)
                {
                    system("cls");
                    gameRunning = false;
                }
                break;
            }
        }
    }
    return 0;
}
