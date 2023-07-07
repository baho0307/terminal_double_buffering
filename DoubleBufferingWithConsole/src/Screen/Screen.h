#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

class Screen
{
public:
	Screen(int hX, int hY, std::string fs);
	void	Show();
private:
	int			x;
	int			y;
	std::string	prevBuffer;
	std::string	scrBuffer;
	void	setCursorPosition(int x, int y);
	void	Calc();
	void	Swap();
};

