#include <Game.h>

Game *g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();
    g_game->init("GameClass", 100, 100, 640, 580, false);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    g_game->clean();
}

