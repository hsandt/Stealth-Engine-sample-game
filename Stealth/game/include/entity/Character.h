//
//  Character.h
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
class Character : public Actor
{
public:
    Character();
    virtual ~Character();
    Character(const Character &) = delete;
    Character &operator=(const Character &) & = delete;
    Character(Character&&) = delete;
    Character &operator=(Character&&) & = delete;

	/* Set control intention methods */

	/// Set the control move intention to a normalized intention vector
	void move(Vector2 moveVector);

	/// Set the control move horizontal intention to a normalized intention vector
	void moveHorizontal(float value);

	/// Set the control move vertical intention to a normalized intention vector
	void moveVertical(float value);

	/* Update */

	/// Character update: apply movement from control
	virtual void update(float dt) override;

protected:
	/* Pointers */

    Controller* controller = nullptr;

	/* Parameters*/

    float speed = 5.0;

	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "Character"; }
};

