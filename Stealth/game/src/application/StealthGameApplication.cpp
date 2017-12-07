//
// Created by wing on 17/04/12.
//

#include <iostream>

#include "entity/PlayerDynamicCharacter.h"
#include "entity/Guard.h"
#include "entity/Spy.h"
#include "component/Transform.h"
#include "physics/PhysicsManager.h"
#include "physics/Rigidbody.h"

#include "application/StealthGameApplication.h"

using namespace std;

StealthGameApplication::StealthGameApplication() : GameApplication()
{

}

StealthGameApplication::~StealthGameApplication()
{
	LOG("[GAME] Destroying StealthGameApplication...");
}

void StealthGameApplication::onLoadNextScene()
{
	// create objects before super so thay can start correctly
	// this is a hack, the scene should have been started from data anyway
    EngineCore::getPhysicsManager()->setGravity({0,-10});

	Actor* spy = EngineCore::getFactory()->CreateGameObject<Spy>();
	Actor* dynamicPlayerCharacter = EngineCore::getFactory()->CreateGameObject<PlayerDynamicCharacter>();
	Actor* guard = EngineCore::getFactory()->CreateGameObject<Guard>();

	spy->transform->setPosition({50.0f, 200.0f});
	dynamicPlayerCharacter->transform->setPosition({150.0f, 150.0f});
	guard->transform->setPosition({50.0f, 300.0f});

	spy->addComponent<Rigidbody>()->addBoxShape({10.f, 10.f});
	guard->addComponent<Rigidbody>()->addBoxShape({10.f, 10.f});

	GameApplication::onLoadNextScene();
}
