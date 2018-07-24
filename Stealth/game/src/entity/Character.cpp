//
//  Character.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "component/Transform.h"
#include "core/Logger.h"
#include "entity/Character.h"
#include "entity/PlayerCharacter.h"

#include "renderer/Renderer.h"
#include "component/CharacterMotor.h"
#include "component/RenderComponent.h"
#include "component/SquareRenderComponent.h"

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

/*
void Character::render(Renderer *renderer) {
     //cout << "rendering at " << go -> GetPosition().x() << endl;
        //BOOST_LOG_TRIVIAL(warning) << "tests";
	shared_ptr<RenderComponent> renderComponent = getComponent<RenderComponent>();
	if (renderComponent != nullptr)
		render(renderer);
	else
		cout << "No render components on character " << name << endl;
}
*/