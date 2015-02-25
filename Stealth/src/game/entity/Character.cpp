//
//  Character.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "Character.h"

Character::Character() : GameObject()
{
}

Character::Character(const Point3d & pos) : GameObject(pos)
{
}

Character::~Character()
{
}

void Character::update(double dt)
{
}
