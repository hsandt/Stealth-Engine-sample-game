//
//  InputManager.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#import <utility>

#include "InputManager.h"

using namespace std;

InputManager::InputManager()
{
    buttonStateMap.insert(pair<Button, ButtonState>());
}

InputManager::~InputManager()
{
}

