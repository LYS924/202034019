#include <iostream>
#include <conio.h>
#include "GameOver.h"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET    "\x1b[0m"

void GameOver::PrintOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??������ �����ұ��??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "         >> �ٽ��ϱ�         " << std::endl;
    std::cout << "         >> ��������         " << std::endl;
    std::cout << "============================" << std::endl;
}
void GameOver::DownOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??������ �����ұ��??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> �ٽ��ϱ�         " << std::endl;
    std::cout << ANSI_COLOR_RED"         >> ��������         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}void GameOver::UpOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ??������ �����ұ��??   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RED"         >> �ٽ��ϱ�         " << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> ��������         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
void GameOver::PlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ����� �׾����ϴ�   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "         >> �ٽ��ϱ�         " << std::endl;
    std::cout << "         >> ��������         " << std::endl;
    std::cout << "============================" << std::endl;
}
void GameOver::DownPlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ����� �׾����ϴ�   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> �ٽ��ϱ�         " << std::endl;
    std::cout << ANSI_COLOR_RED"         >> ��������         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
void GameOver::UpPlayOver()
{
    std::cout << "============================" << std::endl;
    std::cout << "   ����� �׾����ϴ�   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << ANSI_COLOR_RED"         >> �ٽ��ϱ�         " << std::endl;
    std::cout << ANSI_COLOR_RESET"         >> ��������         " << std::endl;
    std::cout << ANSI_COLOR_RESET"============================" << std::endl;
}
char GameOver::GetInput()
{
    return _getch();
}
