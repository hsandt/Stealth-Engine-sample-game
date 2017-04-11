//
//  GameApplication.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

// REFACTOR: move to Engine once all dependencies to Spy/Guard have been removed

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <vector>
#include <renderer/ShaderUtils.h>
//#include <boost/log/trivial.hpp>

// Engine
#include "debug/Logger.h"
#include "core/EngineCore.h"
#include "component/Transform.h"
#include "entity/GameObject.h"
#include "factory/Factory.h"
#include "renderer/Renderer.h"
#include "service/Locator.h"
#include "scene/Scene.h"
#include "geometry/Vector2.h"

// Game
#include "entity/Guard.h"
#include "entity/Spy.h"

#include "application/GameApplication.h"
#include "renderer/ShaderUtils.h"

using namespace std;

GameApplication::GameApplication(GLFWwindow *window, int fps) :
		window(window), isRunning(false), fps(fps) {
	secPerUpdate = 1. / fps;  // fixed deltaTime
}

GameApplication::~GameApplication() {
	destroy();
}

void GameApplication::run() {

	double currentTime;
//    double elapsed;
	double endTime = glfwGetTime();
	double lag = 0;
	double sleep;

	isRunning = true;

	// update loop
	while (isRunning) {
		currentTime = glfwGetTime();
		lag += currentTime - endTime;

		// CHANGE: if using glfwWait, maybe don't poll twice
		glfwPollEvents();

		if (glfwWindowShouldClose(window))
			isRunning = false;

		processInput();
		applyInputBindings();

		while (lag >= secPerUpdate) {
			// TODO: add limit for number of iterations to catch back
			// pass fixed deltaTime as update argument, in sec
			// ALT: use a service locator for deltaTime (fixed)
			update((float) secPerUpdate);
			// TODO: compute at once
			lag -= secPerUpdate;
		}

		render();

		endTime = glfwGetTime();
		lag += endTime - currentTime;

		sleep = secPerUpdate - lag;
		if (sleep > 0) {
			// we are in advance, wait
//			SDL_Delay(sleep);
//			Sleep();
			glfwWaitEventsTimeout(sleep);
		} else {
			// rendering required more than the end of the frame, not time to sleep!
			cout << "No time to sleep!" << endl;
//			glfwPollEvents();
		}

		glfwSwapBuffers(window);

	}

}

void GameApplication::stop() {
	isRunning = false;
}

void GameApplication::init() {
	// Initialize Engine Core, which will initialize all the modules
	engineCore = new EngineCore(this);

	// register Service Providers to Service Locators
	Locator::gameApplication = this;

	currentScene = new Scene();
	currentScene->init();

	Actor* spy = Locator::factory->CreateGameObject<Spy>();
	Actor* guard = Locator::factory->CreateGameObject<Guard>();

	spy->transform->position = {10.0f, 10.0f};
	guard->transform->position = {20.0f, 30.0f};
};

void GameApplication::destroy() {
	delete currentScene;
	delete engineCore;

	Locator::gameApplication = nullptr;

	cout << "[GAME] GameApplication destroyed" << endl;
}

void GameApplication::processInput() {
	Locator::inputManager->processInputs();
}
void GameApplication::applyInputBindings()
{
	Locator::inputManager->applyInputBindings();
}

void GameApplication::update(float dt) {
	map<int, GameObject*> gameObjects{currentScene->getGameObjects()};
	for (auto goPair : gameObjects) {
		GameObject* go{goPair.second};
		go->update(dt);
		// go -> SetPosition(go -> GetPosition() + Vector3 {23, 2, 0});
	}
	// DEBUG

}

void GameApplication::render()
{

	Locator::renderer->clear();

	Locator::renderer->render();

	/*
	std::map<int, std::shared_ptr<GameObject>> gameObjects {currentScene->getGameObjects()};
	for (auto goIt(gameObjects.begin()); goIt != gameObjects.end(); ++goIt) {
		// do not use GameObject& which would be invalid if all shared_ptr
		// to the game object disappeared in the meanwhile (~raw pointer issue)
		shared_ptr<GameObject> go {goIt->second};
		go->render(renderer);
	}
	*/

//	SDL_RenderPresent(renderer);
}

GLFWwindow* GameApplication::getWindow() const
{
	return window;
}
