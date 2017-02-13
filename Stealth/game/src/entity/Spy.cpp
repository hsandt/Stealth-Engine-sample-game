//
//  Spy.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include <string>

#include "entity/Character.h"
#include "entity/PlayerCharacter.h"
#include "component/InputComponent.h"

#include "entity/Spy.h"

class Controller;

using namespace std;

Spy::Spy() : PlayerCharacter()
{
    speed = 2;
}

Spy::~Spy()
{
}

void Spy::setupInputBindings()
{
    // for now, use update until delegates work
//    inputComponent->bindAxisKey<Character>(Key::LEFT, &Character::moveHorizontal);
//    inputComponent->bindAxisKey<Spy>(Key::RIGHT, &Spy::moveVertical);
}
