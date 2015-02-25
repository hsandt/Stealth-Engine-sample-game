//
//  SdlApplication.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>

#define APPTITLE "SDL Template Program"

class SdlApplication
{

public:

    SdlApplication();
    virtual ~SdlApplication();

    SdlApplication(const SdlApplication &) = delete;
    SdlApplication &operator=(const SdlApplication &) & = delete;
    SdlApplication(SdlApplication&&) = delete;
    SdlApplication &operator=(SdlApplication&&) & = delete;

    // Application state (just convenience instead of 0, 1, ...).
    enum APP_STATE
    {
        APP_OK = 0,
        APP_FAILED = 1
    };

    // Run application, called by your code.
    int run(int width, int height);

private:
    // Initialize application, called by run(), don't call manually.
    int init(int width, int height);
    
    // Destroy application, called by destructor, don't call manually.
    void destroy();
    
    // Called to process SDL event.
    void onEvent(SDL_Event* ev);
    
    // Called to render content into buffer.
    void Render();
    
    // Whether the application is in event loop.
    bool _running;
    SDL_Window *win;
    SDL_Renderer *renderer;

};
