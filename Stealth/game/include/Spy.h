//
//  Spy.h
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <string>

#include "Character.h"
#include "HumanController.h"

class Spy : public Character
{
public:
    Spy(const int id, const std::string &name);
    virtual ~Spy();

    Spy(const Spy &) = delete;
    Spy &operator=(const Spy &) & = delete;
    Spy(Spy&&) = default;
    Spy &operator=(Spy&&) & = default;

protected:

};
