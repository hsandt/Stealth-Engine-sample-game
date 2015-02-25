//
//  Spy.h
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include "Character.h"

class Spy : public Character
{
public:
    Spy();
    Spy(const Point3d & pos);
    virtual ~Spy();

    Spy(const Spy &) = delete;
    Spy &operator=(const Spy &) & = delete;
    Spy(Spy&&) = default;
    Spy &operator=(Spy&&) & = default;
private:
};

