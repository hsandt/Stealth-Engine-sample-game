//
//  InputManager.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#import <map>

#import "Button.h"
#import "ButtonState.h"

class InputManager
{
public:
    InputManager();
    virtual ~InputManager();
    
    InputManager(const InputManager &) = delete;
    InputManager &operator=(const InputManager &) & = delete;
    InputManager(InputManager&&) = delete;
    InputManager &operator=(InputManager&&) & = delete;
    
    void processInputs();
    ButtonState getButtonState(Button button);

private:


    
    std::map<Button, ButtonState> buttonStateMap;
};

