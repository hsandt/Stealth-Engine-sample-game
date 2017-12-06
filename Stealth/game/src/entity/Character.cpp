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
#include "debug/Logger.h"
#include "entity/Character.h"
#include "entity/PlayerCharacter.h"

#include "renderer/Renderer.h"
#include "component/RenderComponent.h"
#include "component/SquareRenderComponent.h"

using namespace std;

Character::Character() : Actor()
{
//	addComponent<SquareRenderComponent>();
}

Character::~Character()
{
	if (controller != nullptr)
	{
		LOG("[CHARACTER] Deleting controller");
		delete controller;
	}
}

void Character::init()
{
	Actor::init();

	// TEST
	addComponent<SquareRenderComponent>();
}

void Character::update(float dt) {
    // update physics
    // if controller, let controller set moveIntention
    if (controller) {
        // move based on moveIntention
        transform->setPosition(transform->getPosition() + controller->getMoveIntention() * speed);
    }
    else {
        cout << "No controller found on Character" << endl;
    }
}

/*
void Character::render(Renderer *renderer) {
     //cout << "rendering at " << go -> GetPosition().x() << endl;
        //BOOST_LOG_TRIVIAL(warning) << "test";
	shared_ptr<RenderComponent> renderComponent = getComponent<RenderComponent>();
	if (renderComponent != nullptr)
		render(renderer);
	else
		cout << "No render component on character " << name << endl;
}
*/