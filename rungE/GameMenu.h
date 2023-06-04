#pragma once

class GameMenu
{
public:
	void PrintMenu();
	void DownMenu();
	void UpMenu();
	char GetInput();
	void SetCursorState(bool visible);
};
