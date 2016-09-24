//
//  Guard.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "Guard.h"

#include "AIController.h"

using namespace std;


Guard::Guard(const int id, const std::string &name) : Character(id, name)
{
    controller = std::unique_ptr<Controller>(new AIController());
}

Guard::~Guard()
{
}

void Guard::update(double dt)
{
    Character::update(dt);
}
