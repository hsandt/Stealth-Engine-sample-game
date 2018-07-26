//
//  DynamicCharacter.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "component/Transform.h"
#include "core/Logger.h"
#include "entity/DynamicCharacter.h"
#include "entity/PlayerDynamicCharacter.h"

#include "component/DynamicCharacterMotor.h"
#include "component/RenderComponent.h"
#include "component/SquareRenderComponent.h"
#include "component/Rigidbody.h"

using namespace std;

DynamicCharacter::DynamicCharacter() : Actor()
{
//	addComponent<SquareRenderComponent>();
}

DynamicCharacter::~DynamicCharacter()
{
}

void DynamicCharacter::init()
{
	Actor::init();

	addComponent<DynamicCharacterMotor>();
	addComponent<Rigidbody>()->addBoxShape({10.f, 10.f});

	// TEST
	addComponent<SquareRenderComponent>();
}

void DynamicCharacter::update(float dt) {
}
