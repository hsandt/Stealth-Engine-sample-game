//
//  SdlApplication.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameApplication.h"

#include "SdlApplication.h"

SdlApplication::SdlApplication() :
_running(false)
{
}

SdlApplication::~SdlApplication()
{
    destroy();
}

int SdlApplication::init(int width, int height)
{
    // Initialize the SDL library.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
        return APP_FAILED;
    }
    
    win = SDL_CreateWindow(APPTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    // Success.
    return APP_OK;
}

void SdlApplication::destroy()
{
    if (win)
    {
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
}

int SdlApplication::run(int width, int height)
{
    // Initialize application.
    int state = init(width, height);
    if (state != APP_OK) return state;
    
    // Enter to the SDL event loop.
    SDL_Event ev;
    _running = true;
    
    GameApplication gameApp {win, renderer, 30};
    gameApp.run();
    
    return APP_OK;
}

void SdlApplication::onEvent(SDL_Event* ev)
{
    switch (ev->type)
    {
        case SDL_QUIT:
            _running = false;
            break;
            
        case SDL_KEYDOWN:
        {
            if (ev->key.keysym.sym == SDLK_ESCAPE)
            {
                _running = false;
            }
        }
    }
}

void SdlApplication::Render()
{

}