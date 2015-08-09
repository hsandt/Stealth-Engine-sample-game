//
//  Spy.h
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <string>

#include "entity/Character.h"
#include "entity/HumanController.h"

class Spy : public Character
{
public:
    Spy(const std::string &name, Point3d const &pos);
    virtual ~Spy();

    Spy(const Spy &) = delete;
    Spy &operator=(const Spy &) & = delete;
    Spy(Spy&&) = default;
    Spy &operator=(Spy&&) & = default;

protected:

};

