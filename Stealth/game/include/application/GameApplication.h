//
//  GameApplication.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <memory>

#include "scene/Scene.h"
#include "service/InputManager.h"
#include "renderer/Renderer.h"
#include "factory/Factory.h"

class EngineCore;

class GameApplication
{

public:
    GameApplication(GLFWwindow *win, int fps = 30);
    GameApplication() = default;
    virtual ~GameApplication();

    GameApplication(const GameApplication &) = default;
    GameApplication &operator=(const GameApplication &) & = default;
    GameApplication(GameApplication&&) = default;
    GameApplication &operator=(GameApplication&&) & = default;

    /// Initialize game, called by run()
    void init();

    /// Run application
    void run();

    /// Exit application
    void stop();

	GLFWwindow* getWindow() const;

private:
    /// Destroy application, called by destructor
    void destroy();
    /// Called to process user input and store the new input dynamic states
    void processInput();
    /// Called to apply any callbacks bound to an input, mainly via InputComponents
    void applyInputBindings();
    /// Called to update AI and physics (mainly via BehaviourComponents)
    void update(float dt);
    /// Called to render the game view, mainly via RenderComponents
    void render();

    /// Application window
    GLFWwindow *window = nullptr;

    /// Engine core
    EngineCore *engineCore = nullptr;

    /// Is the game running
    bool isRunning;
    
    /// Game FPS
    int fps;
	/// Time per update (s)
    double secPerUpdate;

    /// active scene (make it a unique_ptr if you are sure no one else uses it)
    Scene* currentScene;

};

