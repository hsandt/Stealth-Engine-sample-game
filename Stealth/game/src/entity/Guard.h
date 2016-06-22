//
//  Guard.h
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <string>

#include "Character.h"

class Guard : public Character
{
public:
    Guard(const std::string &name, Point3d const &pos);
    virtual ~Guard();

    Guard(const Guard &) = delete;
    Guard &operator=(const Guard &) & = delete;
    Guard(Guard&&) = default;
    Guard &operator=(Guard&&) & = default;

    virtual void update(double dt) override;

private:
};

