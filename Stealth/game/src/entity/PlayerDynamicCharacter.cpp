//
// Created by wing on 17/02/12.
//

#include "entity/PlayerDynamicCharacter.h"

#include "entity/Character.h"
#include "controller/PlayerController.h"
#include "core/EngineCore.h"
#include "input/InputManager.h"

PlayerDynamicCharacter::PlayerDynamicCharacter() : DynamicCharacter() {
}

PlayerDynamicCharacter::~PlayerDynamicCharacter() {
	// !! Do not delete inputComponent here! It's a weak pointer, GameObject takes care of deleting all components!
}

void PlayerDynamicCharacter::init()
{
	DynamicCharacter::init();

	inputComponent = addComponent<InputComponent>();
	addComponent<PlayerController>();

	// pure virtual methods need to be called outside constructor for polymorphism to work
	setupInputBindings();
}

void PlayerDynamicCharacter::update(float dt)
{
	DynamicCharacter::update(dt);
}
