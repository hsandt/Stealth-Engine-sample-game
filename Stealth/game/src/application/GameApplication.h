//
//  GameApplication.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <memory>

#include "Scene.h"
#include "InputManager.h"

class GameApplication : public std::enable_shared_from_this<GameApplication>
{

public:
    GameApplication(GLFWwindow *win, int fps = 30);
    GameApplication() = default;
    virtual ~GameApplication();

    GameApplication(const GameApplication &) = default;
    GameApplication &operator=(const GameApplication &) & = default;
    GameApplication(GameApplication&&) = default;
    GameApplication &operator=(GameApplication&&) & = default;

    // Initialize game, called by run()
    void init();
    // Run application
    void run();

    // Exit application
    void stop();
private:
    // Destroy application, called by destructor
    void destroy();
    // Called to process user input
    void processInput();
    // Called to update AI and physics
    void update(double dt);
    // Called to render the game view
    void render();

    // Application window
    GLFWwindow *window = nullptr;

    // Renderer
    Renderer *renderer = nullptr;

    // Input manager
    InputManager *inputManager = nullptr;

    // Is the game running
    bool isRunning;
    
    // FPS and timer per update (s)
    int fps;
    double secPerUpdate;

    // active scene (make it a unique_ptr if you are sure no one else uses it)
    std::shared_ptr<Scene> currentScene;

};

