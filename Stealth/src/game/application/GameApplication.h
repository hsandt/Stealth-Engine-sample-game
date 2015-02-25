//
//  GameApplication.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#import <memory>

// SDL
#import <SDL2/SDL.h>

#import "Scene.h"

class GameApplication
{

public:
    GameApplication(SDL_Window *win, SDL_Renderer *renderer, int fps = 30);
    virtual ~GameApplication();

    GameApplication(const GameApplication &) = delete;
    GameApplication &operator=(const GameApplication &) & = delete;
    GameApplication(GameApplication&&) = delete;
    GameApplication &operator=(GameApplication&&) & = delete;

    // Run application
    void run();

private:
    // Initialize game, called by run()
    void init();
    // Destroy application, called by destructor
    void destroy();
    // Called to process user input
    void processInput();
    // Called to update AI and physics
    void update(double dt);
    // Called to render the game view
    void render();

    // Pointers passed by the SDL application
    SDL_Window *win;
    SDL_Renderer *renderer;

    // Is the game running
    bool running;
    
    // FPS and timer per update (ms)
    int fps;
    Uint32 msecPerUpdate;
    double secPerUpdate;  // avoids converting to sec every time

    // active scene
    std::shared_ptr<Scene> currentScene;

};

