//
// Created by wing on 17/02/12.
//

#include "entity/PlayerCharacter.h"

#include "entity/Character.h"
#include "component/CharacterMotor.h"
#include "controller/PlayerController.h"
#include "core/EngineCore.h"
#include "input/InputManager.h"

PlayerCharacter::PlayerCharacter() : Character() {
}

PlayerCharacter::~PlayerCharacter() {
	// !! Do not delete inputComponent here! It's a weak pointer, GameObject takes care of deleting all components!
}

void PlayerCharacter::init()
{
	Character::init();

	inputComponent = addComponent<InputComponent>();
	addComponent<PlayerController>();

	// pure virtual methods need to be called outside constructor for polymorphism to work
	setupInputBindings();
}

void PlayerCharacter::update(float dt)
{
	Character::update(dt);
}
