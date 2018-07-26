//
//  Character.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Engine
#include "component/RenderComponent.h"
#include "component/SquareRenderComponent.h"
#include "component/Transform.h"
#include "core/Logger.h"

// Game
#include "entity/Character.h"
#include "entity/PlayerCharacter.h"
#include "component/CharacterMotor.h"

using namespace std;

Character::Character() : Actor()
{
//	addComponent<SquareRenderComponent>();
}

Character::~Character()
{
}

void Character::init()
{
	Actor::init();

	addComponent<CharacterMotor>();

	// TEST
	addComponent<SquareRenderComponent>();
}

void Character::update(float dt) {
}
