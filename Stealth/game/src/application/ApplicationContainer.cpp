//
//  ApplicationContainer.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include <memory>
#include <iostream>
#include "GameApplication.h"

#include "ApplicationContainer.h"

using namespace std;

ApplicationContainer::ApplicationContainer() :
_running(false)
{
}

ApplicationContainer::~ApplicationContainer()
{
    destroy();
}

int ApplicationContainer::init(int width, int height)
{
    // Set callback for any GLFW error
    glfwSetErrorCallback(error_callback);

    // Initialise GLFW
    int initSuccess = glfwInit();
    if (!initSuccess)
    {
        cerr << "[GLFW] Could not initialize application." << endl;
        return FAILURE;
    }

    // Create window (OpenGL 2.0+)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(width, height, APPTITLE, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        cerr << "[GLFW] Could not create window." << endl;
        return FAILURE;
    }

    // may be useful for critical key events
    glfwSetKeyCallback(window, keyCallback);

    // in case player quickly presses and releases key between 2 frames, set to sticky mode not to miss that quick press
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    // Use this window as OpenGL context
    glfwMakeContextCurrent(window);

    // GL loader here

    // VSync
    glfwSwapInterval(1);

    return SUCCESS;
}

void ApplicationContainer::destroy()
{
    if (game)
        delete(game);

    if (window)
        glfwDestroyWindow(window);

    // Terminate application
    glfwTerminate();

}

void ApplicationContainer::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void ApplicationContainer::Render()
{

}

void ApplicationContainer::runGame(int fps) {
    _running = true;
    game = new GameApplication(window, 30);
    game->init();
    game->run();
}


void error_callback(int error, const char* description)
{
    cerr << "[GLFW] Error: " << description << endl;
}
