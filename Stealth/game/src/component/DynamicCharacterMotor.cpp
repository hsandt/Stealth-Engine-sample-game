//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//

#include "component/DynamicCharacterMotor.h"

#include "entity/Actor.h"
#include "controller/Controller.h"
#include "component/Transform.h"
#include "physics/Rigidbody.h"

DynamicCharacterMotor::DynamicCharacterMotor() {

}

DynamicCharacterMotor::~DynamicCharacterMotor() {

}

void DynamicCharacterMotor::start()
{
	Component::start();

	controller = actor->getComponent<Controller>();
}

void DynamicCharacterMotor::update(float dt)
{
	Component::update(dt);

	// update physics
	// if controller, let controller set moveIntention
	if (controller) {
		// move character directly with transform for a kinematic motion
		actor->getComponent<Rigidbody>()->setVelocity(controller->getMoveIntention() * speed);
	}
	else {
		cout << "No controller found on Character" << endl;
	}
}
