#include <iostream>
#include <SDL_image.h>
#include <TextureManager.h>

#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = SDL_WINDOW_SHOWN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow == 0)
        {
            std::cout << "SDL_CreateWindow FAILED\n";
            return false;
        }

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        if (m_pRenderer == 0)
        {
            std::cout << "SDL_CreateRenderer FAILED\n";
            return false;
        }

        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
        
        if (!TheTextureManager::Instance()->load("../assets/animate-alpha.png", "animate", m_pRenderer))
        {
            std::cout << "TextureManager FAILED\n";
            return false;
        }

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
    m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("animate", 0, 0, 128, 164, m_pRenderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 164, 1, m_currentFrame, m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

