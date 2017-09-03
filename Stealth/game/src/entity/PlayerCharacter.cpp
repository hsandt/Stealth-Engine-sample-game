//
// Created by wing on 17/02/12.
//

#include "controller/PlayerController.h"
#include "entity/Character.h"
#include "core/EngineCore.h"
#include "service/InputManager.h"

#include "entity/PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Character() {
	controller = new PlayerController();
//	inputComponent = addComponent<InputComponent>();
}

PlayerCharacter::~PlayerCharacter() {
	delete controller;
}

void PlayerCharacter::init()
{
	Character::init();

	// TEST
	inputComponent = addComponent<InputComponent>();

	// pure virtual methods need to be called outside constructor for polymorphism to work
	setupInputBindings();
}

void PlayerCharacter::update(float dt)
{
	Character::update(dt);

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
