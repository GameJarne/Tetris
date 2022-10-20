#include "Game.h"
#include "Settings.h"

int main(void)
{
    Game game{ settings::boardWidthHeight.GetX(), // screen width
        settings::boardWidthHeight.GetY(), // screen height
        settings::fps, // fps
        "Tetris Raylib" }; // window name

    while (!game.GameShouldClose())
    {
       game.Tick();
    }
    return 0;
}