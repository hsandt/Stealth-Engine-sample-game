//
//  Spy.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#import "Character.h"
#import "HumanController.h"

#include "Spy.h"

class Controller;

Spy::Spy()
: Character()
{
    controller = std::unique_ptr<Controller>(new HumanController());
}

Spy::Spy(const Point3d & pos)
: Character(pos)
{
    controller = std::unique_ptr<Controller>(new HumanController());
}

Spy::~Spy()
{
}

