#include "Screen.h"

Screen::Screen(int hX, int hY, std::string fs)
{
	x = hX;
	y = hY;
	prevBuffer = fs;
	scrBuffer = fs;
	std::cout << scrBuffer;
}

void Screen::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void Screen::Show()
{
	Calc();
	for (int i = 0; i < prevBuffer.size(); i++)
	{
		if (scrBuffer[i] != prevBuffer[i])
		{
			setCursorPosition((i % x), (i / x));
			std::cout << scrBuffer[i];
		}
	}
}

void Screen::Calc()
{
	prevBuffer[5] = prevBuffer[5] != '@' ? '@' : 'A';
	/*MANUPILATING PREVBUFFER (you can do your own process here)*/
	Swap();
}

void Screen::Swap()
{
	std::string tmp;

	tmp = prevBuffer;
	prevBuffer = scrBuffer;
	scrBuffer = tmp;
}
