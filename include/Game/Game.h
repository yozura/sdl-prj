#ifndef __GAME__
#define __GAME__
#include <SDL.h>

class Game
{
public:
    Game() {}
    ~Game() {}
   
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_bRunning; }

private:
    SDL_Window      *m_pWindow;
    SDL_Renderer    *m_pRenderer;

    bool             m_bRunning;
    int              m_currentFrame;
};

#endif /* defined (__GAME__) */

