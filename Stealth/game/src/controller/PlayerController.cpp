//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//

#include <iostream>

#include "controller/PlayerController.h"

#include "core/EngineCore.h"
#include "controller/Controller.h"
#include "input/Key.h"
#include "service/InputManager.h"

using namespace std;

PlayerController::PlayerController() {

}

PlayerController::~PlayerController() {

}

void PlayerController::update(float dt)
{
	Component::update(dt);

	// delegates not ready so use this instead of key bindings
	if (EngineCore::getInputManager()->isKeyDown(Key::LEFT))
	{
		moveHorizontal(-1.f);
	}
	else if (EngineCore::getInputManager()->isKeyDown(Key::RIGHT))
	{
		moveHorizontal(1.f);
	}
	else
	{
		moveHorizontal(0.f);
	}

	if (EngineCore::getInputManager()->isKeyDown(Key::DOWN))
	{
		moveVertical(-1.f);

	}
	else if (EngineCore::getInputManager()->isKeyDown(Key::UP))
	{
		moveVertical(1.f);
	}
	else
	{
		moveVertical(0.f);
	}
}

void PlayerController::moveHorizontal(float value)
{
	Vector2 newMoveIntention {value, getMoveIntention().y()};
	setMoveIntention(newMoveIntention);
}

void PlayerController::moveVertical(float value)
{
	Vector2 newMoveIntention {getMoveIntention().x(), value};
	setMoveIntention(newMoveIntention);
}
