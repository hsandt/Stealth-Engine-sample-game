//
//  Guard.h
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#import "Character.h"

class Guard : public Character
{
public:
    Guard();
    Guard(const Point3d & pos);
    virtual ~Guard();

    Guard(const Guard &) = delete;
    Guard &operator=(const Guard &) & = delete;
    Guard(Guard&&) = default;
    Guard &operator=(Guard&&) & = default;
    
    virtual void update(double dt) override;
    
private:
};

