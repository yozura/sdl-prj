#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    SDL_Surface    *pTempSurface = SDL_LoadBMP("/home/yozura/study/sdl-prj/assets/rider.bmp");
    int             flags        = SDL_WINDOW_SHOWN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL_Init SUCCESS\n";
    
        if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow == 0)
        {
            std::cout << "SDL_CreateWindow FAILED\n";
            return false;
        }

        std::cout << "SDL_CreateWindow SUCCESS\n";

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        if (m_pRenderer == 0)
        {
            std::cout << "SDL_CreateRenderer FAILED\n";
            return false;
        }

        std::cout << "SDL_CreateRenderer SUCCESS\n";
        
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);

        SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);
        m_destRect.x = m_srcRect.x = 0;
        m_destRect.y = m_srcRect.y = 0;
        m_destRect.w = m_srcRect.w;
        m_destRect.h = m_srcRect.h;

        m_bRunning = true;
    }
    else 
    {
        std::cout << "SDL_Init FAILED\n";
        return false;
    }

    return true;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update()
{
    
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_destRect);
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

