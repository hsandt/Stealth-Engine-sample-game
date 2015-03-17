//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//

#include <iostream>
#include <memory>

#include "Button.h"
#include "ButtonState.h"
#include "Locator.h"
#include "InputManager.h"

#include "HumanController.h"

using namespace std;

HumanController::HumanController() {

}

HumanController::~HumanController() {

}

void HumanController::setIntention() {
    weak_ptr<InputManager> wim = Locator::getWeakInputManager();
    //shared_ptr<InputManager> inputManager = Locator::getInputManager();
    shared_ptr<InputManager> inputManager = wim.lock();
    if (!inputManager) {
        cout << "HumanController: could not get shared pointer to InputManager" << endl;
        return;
    }

    // set move intention based on directional keys pressed (origin at top-left)
    if (inputManager->isPressedOrDown(Button::UP)) {
        intention.move = {0, -1, 0};
    }
}
