//
//  Guard.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "AIController.h"

#include "Guard.h"

Guard::Guard(const Point3d & pos) : Character(pos)
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
