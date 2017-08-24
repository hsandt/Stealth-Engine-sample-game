//
// Created by wing on 17/04/12.
//

#include <iostream>

#include "entity/Guard.h"
#include "entity/Spy.h"
#include "component/Transform.h"

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
	Actor* spy = EngineCore::getFactory()->CreateGameObject<Spy>();
	Actor* guard = EngineCore::getFactory()->CreateGameObject<Guard>();

	spy->transform->position = {10.0f, 10.0f};
	guard->transform->position = {20.0f, 30.0f};

//	GameObject* go = EngineCore::getFactory()->CreateGameObject<GameObject>();
//	go->addComponent<Transform>();
}
