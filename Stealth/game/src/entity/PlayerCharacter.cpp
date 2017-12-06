//
// Created by wing on 17/02/12.
//

#include "controller/PlayerController.h"
#include "entity/Character.h"
#include "core/EngineCore.h"
#include "service/InputManager.h"

#include "entity/PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Character() {
}

PlayerCharacter::~PlayerCharacter() {
	// !! Do not delete inputComponent here! It's a weak pointer, GameObject takes care of deleting all components!
}

void PlayerCharacter::init()
{
	Character::init();

	inputComponent = addComponent<InputComponent>();
	controller = addComponent<PlayerController>();

	// pure virtual methods need to be called outside constructor for polymorphism to work
	setupInputBindings();
}

void PlayerCharacter::update(float dt)
{
	Character::update(dt);
}
