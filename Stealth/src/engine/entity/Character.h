//
//  Character.h
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <memory>
#import "GameObject.h"
#include "Controller.h"
#include "HumanController.h"

class Character : public GameObject
{
public:
    Character(const Point3d & pos={0, 0, 0});
    virtual ~Character();
    Character(const Character &) = delete;
    Character &operator=(const Character &) & = delete;
    Character(Character&&) = delete;
    Character &operator=(Character&&) & = delete;

    virtual void update(double dt) override;

    virtual void render(SDL_Renderer* renderer) override;

protected:
    std::unique_ptr<Controller> controller = nullptr;
    double speed = 5.0;
};
