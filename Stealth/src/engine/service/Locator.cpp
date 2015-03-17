//
// Created by L Nguyen Huu on 25/02/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//

#include <iostream>
#include "Locator.h"

using namespace std;

weak_ptr<GameApplication> Locator::gameApplication;  // default initialization to nullptr (required)
weak_ptr<InputManager> Locator::inputManager;

// maybe return a shared_ptr for faster processing
weak_ptr<GameApplication> Locator::getGameApplication() {
    if (gameApplication.expired()) {
        cout << "Locator: could not locate GameApplication service." << endl;
    }
    return gameApplication;
}

shared_ptr<InputManager> Locator::getInputManager() {
    if (inputManager.expired()) {
        cout << "Locator: could not locate InputManager service." << endl;
    }
    return inputManager.lock();
}

weak_ptr<InputManager> Locator::getWeakInputManager() {
    return inputManager;
}