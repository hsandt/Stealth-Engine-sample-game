//
//  Spy.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include <string>

// Engine
#include "Character.h"
#include "HumanController.h"

#include "Spy.h"

class Controller;

using namespace std;

Spy::Spy(const string &name, Vec3f const &pos) : Character(name, pos)
{
    controller = std::unique_ptr<Controller>(new HumanController());
    speed = 2;
}

Spy::~Spy()
{
}

