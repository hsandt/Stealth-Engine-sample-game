//
//  GameApplication.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#import <iostream>
#import <memory>
#import <vector>
#import <boost/log/trivial.hpp>

// SDL
#import <SDL2/SDL.h>

// Engine
#import "Scene.h"

// Game
#import "Guard.h"
#import "Spy.h"
#import "GameObject.h"

#include "GameApplication.h"

using namespace std;

GameApplication::GameApplication(SDL_Window *win, SDL_Renderer *renderer, int fps) : win(win), renderer(renderer), running(false), fps(fps)
{
    msecPerUpdate = 1000. / fps;
    secPerUpdate = 1. / fps;  // fixed deltaTime
}

GameApplication::~GameApplication()
{
}

void GameApplication::run() {
    
    init();
    
    Uint32 currentTime;
//    Uint32 elapsed;
    Uint32 endTime {SDL_GetTicks()};
    Uint32 lag {0};
    int sleep;
    
    running = true;

    // update loop
    while (running) {
        currentTime = SDL_GetTicks();
        lag += currentTime - endTime;

        processInput();

        while (lag >= msecPerUpdate) {
            // TODO: add limit for number of iterations to catch back
            // pass fixed deltaTime as update argument, in sec
            // ALT: use a service locator for deltaTime (fixed)
            update(secPerUpdate);
            // TODO: compute at once
            lag -= msecPerUpdate;
        }
        
        render();

        endTime = SDL_GetTicks();
        lag += endTime - currentTime;
        
        sleep = msecPerUpdate - lag;
        if (sleep > 0) {
            // we are in advance, wait
            SDL_Delay(sleep);
        } else {
            // rendering required more than the end of the frame, not time to sleep!
            cout << "No time to sleep!" << endl;
        }

    }

}

void GameApplication::init() {
    currentScene = make_shared<Scene>();
    
    currentScene -> addGameObject(unique_ptr<GameObject> {new Guard({0, 20, 0})});  // use rhs or move only
    currentScene -> addGameObject(unique_ptr<GameObject> {new Spy({50., 50., 0.})});
}

void GameApplication::destroy() {

}

void GameApplication::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
                
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }
    }
}

void GameApplication::update(double dt) {
    std::map<int, std::shared_ptr<GameObject>> gameObjects {currentScene -> getGameObjects()};
    for (auto goIt (gameObjects.begin()); goIt != gameObjects.end(); ++goIt)
    {
        shared_ptr<GameObject> go {goIt -> second};
        go -> update(dt);
        // go -> SetPosition(go -> GetPosition() + Point3d {23, 2, 0});
    }
}

void GameApplication::render() {
    
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0, 0xff);
    SDL_RenderClear(renderer);

    std::map<int, std::shared_ptr<GameObject>> gameObjects {currentScene -> getGameObjects()};
    for (auto goIt (gameObjects.begin()); goIt != gameObjects.end(); ++goIt)
    {
        // do not use GameObject& which would be invalid if all shared_ptr
        // to the game object disappeared in the meanwhile (~raw pointer issue)
        shared_ptr<GameObject> go {goIt -> second};
        
        // cout << "rendering at " << go -> GetPosition().x() << endl;
//        BOOST_LOG_TRIVIAL(warning) << "test";
        SDL_Rect r;
//        int w = 640, h = 480;

        r.w = 20;
        r.h = 20;
        r.x = go->GetPosition().x();
        r.y = go->GetPosition().y();
        
        
        
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0, 0xff);
        SDL_RenderFillRect(renderer, &r);
        
    }

    SDL_RenderPresent(renderer);
}
