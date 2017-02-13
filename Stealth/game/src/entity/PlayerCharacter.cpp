//
// Created by wing on 17/02/12.
//

#include "controller/PlayerController.h"
#include "entity/Character.h"
#include "service/Locator.h"
#include "service/InputManager.h"

#include "entity/PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Character() {
	controller = new PlayerController();
	inputComponent = addComponent<InputComponent>();
}

PlayerCharacter::~PlayerCharacter() {

}

void PlayerCharacter::init()
{
	Character::init();

	// pure virtual methods need to be called outside constructor for polymorphism to work
	setupInputBindings();
}

void PlayerCharacter::update(float dt)
{
	Character::update(dt);

	// delegates not ready so use this instead of key bindings
	if (Locator::getInputManager()->isKeyDown(Key::LEFT))
	{
		moveHorizontal(-1.f);
	}
	else if (Locator::getInputManager()->isKeyDown(Key::RIGHT))
	{
		moveHorizontal(1.f);

	}
	else
	{
		moveHorizontal(0.f);
	}

	if (Locator::getInputManager()->isKeyDown(Key::DOWN))
	{
		moveVertical(-1.f);

	}
	else if (Locator::getInputManager()->isKeyDown(Key::UP))
	{
		moveVertical(1.f);
	}
	else
	{
		moveVertical(0.f);
	}
}
