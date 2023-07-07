#include "src/Screen/Screen.h"

int main()
{
    Screen  scr = Screen(6/*text x size*/, 2/*text y size*/, "TEST\nTEST\n");

    while (true)
    {
        scr.Show();
    }
}