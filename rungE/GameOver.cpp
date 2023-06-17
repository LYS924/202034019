#include <iostream>
#include <conio.h>
#include "GameOver.h"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET    "\x1b[0m"

void GameOver::PrintOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??게임을 종료할까요??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "         >> 다시하기         " << std::endl;
    std::cout << "         >> 게임종료         " << std::endl;
    std::cout << "============================" << std::endl;
}
void GameOver::DownOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??게임을 종료할까요??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> 다시하기         " << std::endl;
    std::cout << ANSI_COLOR_RED"         >> 게임종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}void GameOver::UpOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??게임을 종료할까요??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RED"         >> 다시하기         " << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> 게임종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
void GameOver::PlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   당신은 죽었습니다   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "         >> 다시하기         " << std::endl;
    std::cout << "         >> 게임종료         " << std::endl;
    std::cout << "============================" << std::endl;
}
void GameOver::DownPlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   당신은 죽었습니다   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> 다시하기         " << std::endl;
    std::cout << ANSI_COLOR_RED"         >> 게임종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
void GameOver::UpPlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   당신은 죽었습니다   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RED"         >> 다시하기         " << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> 게임종료         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
char GameOver::GetInput()
{
    return _getch();
}
