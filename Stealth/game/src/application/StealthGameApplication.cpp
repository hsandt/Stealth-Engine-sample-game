//
// Created by wing on 17/04/12.
//

#include <iostream>

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
    EngineCore::getPhysicsManager()->setGravity({0,-10});

	Actor* spy = EngineCore::getFactory()->CreateGameObject<Spy>();
	Actor* guard = EngineCore::getFactory()->CreateGameObject<Guard>();

	spy->transform->position = {50.0f, 200.0f};
	guard->transform->position = {20.0f, 30.0f};

	spy->addComponent<Rigidbody>()->addBoxShape(10.f, 10.f);


}
