//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//


#pragma once

#include "Controller.h"

// REFACTOR? PlayerController/AIController have no real differences, since the actor classes are doing all the job
class PlayerController : public Controller {
public:
    PlayerController();
    virtual ~PlayerController();

    PlayerController(const PlayerController &) = delete;
    PlayerController &operator=(const PlayerController &) & = delete;
    PlayerController(PlayerController &&) = default;
    PlayerController &operator=(PlayerController &&) & = default;

private:

};


