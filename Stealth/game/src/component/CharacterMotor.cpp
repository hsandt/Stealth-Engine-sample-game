//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//

#include "component/CharacterMotor.h"

#include "entity/Actor.h"
#include "controller/Controller.h"
#include "component/Transform.h"

CharacterMotor::CharacterMotor() {

}

CharacterMotor::~CharacterMotor() {

}

void CharacterMotor::start()
{
	Component::start();

	controller = actor->getComponent<Controller>();
}

void CharacterMotor::update(float dt)
{
	Component::update(dt);

	// update physics
	// if controller, let controller set moveIntention
	if (controller) {
		// move character directly with transform for a kinematic motion
		actor->transform->setPosition(actor->transform->getPosition() + controller->getMoveIntention() * speed * dt);
	}
	else {
		cout << "No controller found on Character" << endl;
	}
}
