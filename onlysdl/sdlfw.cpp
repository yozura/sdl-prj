#include <SDL.h>

SDL_Window      * g_pWindow     = 0;
SDL_Renderer    * g_pRenderer   = 0;
bool              g_bRunning    = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        if (g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags))
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

void render()
{
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    
    SDL_RenderClear(g_pRenderer);

    SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* argv[])
{
    if (init("Chapter 1-1: Breaking Code", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1;
    }

    while (g_bRunning)
    {
        render();
    }

    SDL_Quit();

    return 0;
}
