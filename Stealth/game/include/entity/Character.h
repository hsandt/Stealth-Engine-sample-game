//
//  Character.h
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include "world/GameObject.h"
#include "world/Actor.h"
#include "controller/Controller.h"
#include "controller/PlayerController.h"

/// Top-view character: an actor who can move on XY
class Character : public Actor
{
public:
    Character();
    virtual ~Character();
    Character(const Character &) = delete;
    Character &operator=(const Character &) & = delete;
    Character(Character&&) = delete;
    Character &operator=(Character&&) & = delete;

	/* Update */

	/// Character update: apply movement from control
	virtual void update(float dt) override;

	void init() override;

protected:

	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "Character"; }
};

