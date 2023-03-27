#include <iostream>
#include <conio.h>

int main()
{
	while(1)
	{
		std::cout<<"*";
		if(_kbhit() &&_getch()==27)
		{
			
			break;
		}
	}
	return 0;
}
