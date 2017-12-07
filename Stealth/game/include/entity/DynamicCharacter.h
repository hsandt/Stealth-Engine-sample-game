//
//  DynamicCharacter.h
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include "entity/GameObject.h"
#include "entity/Actor.h"
#include "controller/Controller.h"
#include "controller/PlayerController.h"

/// Top-view character: an actor who can move on XY
class DynamicCharacter : public Actor
{
public:
    DynamicCharacter();
    virtual ~DynamicCharacter();
    DynamicCharacter(const DynamicCharacter &) = delete;
    DynamicCharacter &operator=(const DynamicCharacter &) & = delete;
    DynamicCharacter(DynamicCharacter&&) = delete;
    DynamicCharacter &operator=(DynamicCharacter&&) & = delete;

	/* Update */

	/// DynamicCharacter update: apply movement from control
	virtual void update(float dt) override;

	void init() override;

protected:

	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "DynamicCharacter"; }
};

