//
//  Guard.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "Guard.h"

Guard::Guard()
{
    //controller = std::unique_ptr<Controller>(new HumanController());
}

Guard::Guard(const Point3d & pos) : Character(pos)
{
    //controller = std::unique_ptr<Controller>(new HumanController());
}

Guard::~Guard()
{
}

void Guard::update(double dt)
{
	SetPosition(GetPosition() + dt * Point3d {30, 30, 0});
}
