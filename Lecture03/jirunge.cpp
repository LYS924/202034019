#include <iostream>
#include <conio.h>
#include <Windows.h>

int print_title_screen()
{
    std::cout << "**************************************************************" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                      지렁이 게임                           *" << std::endl;
    std::cout << "*                     (Snake Bite)                           *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*                     1. 게임시작                            *" << std::endl;
    std::cout << "*                     2. 게임설명                            *" << std::endl;
    std::cout << "*                     3. 게임랭킹보기                        *" << std::endl;
    std::cout << "*                     4. 게임종료(esc)                       *" << std::endl;
    std::cout << "**************************************************************" << std::endl;
    return 0;
}
int print_introduction_screen()
{
    std::cout << "**************************************************************" << std::endl;
    std::cout << "*                    게임 설명 화면입니다.                   *" << std::endl;
    std::cout << "*               게임설명이 필요없는 게임입니다.              *" << std::endl;
    std::cout << "*                                                            *" << std::endl;
    std::cout << "*              타이틀 화면으로 돌아갈까요?(Y/N)              *" << std::endl;
    std::cout << "**************************************************************" << std::endl;
    return 0;
}
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int print_game_screen(int stage_width, int stage_height)
{
    system("cls");
    for (int i = 0; i <= stage_width + 1; i++)
    {
        gotoxy(i, 0);
        printf("*");
    }
    for (int i = 1; i <= stage_height; i++)
    {
        gotoxy(0, i);
        printf("*");
        gotoxy(stage_width + 1, i);
        printf("*");
    }
    for (int i = 0; i <= stage_width + 1; i++)
    {
        gotoxy(i, stage_height + 1);
        printf("*");
    }
    return 0;
}
int main()
{
    int game_state = 0;
    int is_game_running = 1;
    while (is_game_running)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            while (key_input != '1' && key_input != '2' && key_input != '4' && key_input != 27)
            {
                key_input = _getch();
            }
            switch (key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            print_game_screen(20, 10);
            key_input = _getch();
            break;
        case 2:
            print_introduction_screen();
            while (key_input != 'y' && key_input != 'n')
            {
                key_input = _getch();
            }
            switch (key_input)
            {

            case 'y':
                game_state = 0;
                break;
            case 'n':
                print_introduction_screen();
                key_input = _getch();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }


    }
    return 0;
}