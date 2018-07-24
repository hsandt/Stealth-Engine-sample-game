//
// Created by wing on 17/02/12.
//

#include "controller/AIController.h"
#include "entity/Character.h"

#include "entity/AICharacter.h"

AICharacter::AICharacter() : Character() {
}

AICharacter::~AICharacter() {

}

void AICharacter::update(float dt)
{
	// exceptionally call this before super implementation
	// REFACTOR: update all intentions before physics, in a separate loop (AI loop, at different frequency)
	updateIntention();

	Character::update(dt);
}
