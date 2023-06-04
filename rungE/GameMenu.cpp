#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "GameMenu.h"

#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"

void GameMenu :: PrintMenu()
{
    std::cout << "============================" << std::endl;
    std::cout << "     !!게임 메인 메뉴!!      " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "        1. 게임 시작         " << std::endl;
    std::cout << "        2. 게임 종료         " << std::endl;
    std::cout << "============================" << std::endl;
}
void GameMenu::DownMenu()
{
    std::cout << "============================" << std::endl;
    std::cout << "     !!게임 메인 메뉴!!      " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RESET"        1. 게임 시작         " << std::endl;
    std::cout << ANSI_COLOR_YELLOW"        2. 게임 종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
void GameMenu::UpMenu()
{
    std::cout << "============================" << std::endl;
    std::cout << "     !!게임 메인 메뉴!!      " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_YELLOW"        1. 게임 시작         " << std::endl;
    std::cout << ANSI_COLOR_RESET"        2. 게임 종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
char GameMenu::GetInput()
{
    return _getch();
}
void GameMenu::SetCursorState(bool visible)
{

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = visible;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
