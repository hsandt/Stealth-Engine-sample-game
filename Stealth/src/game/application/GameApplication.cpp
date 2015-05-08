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
#import "Locator.h"
#import "Scene.h"

// Game
#import "Guard.h"
#import "Spy.h"
#import "GameObject.h"

#include "GameApplication.h"

using namespace std;

GameApplication::GameApplication(SDL_Window *win, SDL_Renderer *renderer, int fps) :
        win(win), renderer(renderer), isRunning(false), fps(fps)
{
    msecPerUpdate = (Uint32) floor(1000. / fps);
    secPerUpdate = 1. / fps;  // fixed deltaTime
}

GameApplication::~GameApplication()
{
    destroy();
}

void GameApplication::run() {
    
    init();
    
    Uint32 currentTime;
//    Uint32 elapsed;
    Uint32 endTime {SDL_GetTicks()};
    Uint32 lag {0};
    int sleep;
    
    isRunning = true;

    // update loop
    while (isRunning) {
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

void GameApplication::stop() {
    isRunning = false;
}

void GameApplication::init() {
    // register Service Providers to Service Locators
    Locator::gameApplication = weak_ptr<GameApplication>(shared_from_this());
    inputManager = make_shared<InputManager>();
    Locator::inputManager = inputManager;

    currentScene = make_shared<Scene>();

    // T* &&arg did not work well, so to ensure I don't keep a ref of the GO I use only unique_ptr
    currentScene->addGameObject(unique_ptr<GameObject> {new Guard("Guard", {0, 20, 0})});  // use rhs or move only
    currentScene->addGameObject(unique_ptr<GameObject> {new Spy("Spy", {50., 50., 0.})});
};

void GameApplication::destroy() {
    // nothing for now
}

void GameApplication::processInput() {
    inputManager->processInputs();
    if (inputManager->getButtonState(Button::QUIT) == ButtonState::PRESSED ||
            inputManager->getButtonState(Button::QUIT) == ButtonState::RELEASED_PRESSED) {
        stop();
    }
    //SDL_Event event;
    //while (SDL_PollEvent(&event)) {
    //    switch (event.type)
    //    {
    //        case SDL_QUIT:
    //            isRunning = false;
    //            break;
    //
    //        case SDL_KEYDOWN:
    //        {
    //            if (event.key.keysym.sym == SDLK_ESCAPE)
    //            {
    //                isRunning = false;
    //            }
    //        }
    //    }
    //}
}

void GameApplication::update(double dt) {
    map<int, std::shared_ptr<GameObject>> gameObjects {currentScene->getGameObjects()};
    for (auto goIt (gameObjects.begin()); goIt != gameObjects.end(); ++goIt)
    {
        shared_ptr<GameObject> go {goIt->second};
        go -> update(dt);
        // go -> SetPosition(go -> GetPosition() + Point3d {23, 2, 0});
    }
    // DEBUG
    
}

void GameApplication::render() {
    
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0, 0xff);
    SDL_RenderClear(renderer);

    std::map<int, std::shared_ptr<GameObject>> gameObjects {currentScene->getGameObjects()};
    for (auto goIt (gameObjects.begin()); goIt != gameObjects.end(); ++goIt)
    {
        // do not use GameObject& which would be invalid if all shared_ptr
        // to the game object disappeared in the meanwhile (~raw pointer issue)
        shared_ptr<GameObject> go {goIt->second};
        go->render(renderer);
    }
    SDL_RenderPresent(renderer);
}


