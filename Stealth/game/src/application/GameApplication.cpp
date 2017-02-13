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
	// load shaders
	loadAllShaders();

	// register Service Providers to Service Locators
	Locator::gameApplication = this;

	renderer = new Renderer(window);
	Locator::renderer = renderer;

	inputManager = new InputManager(window);
	Locator::inputManager = inputManager;

	gameObjectFactory = new Factory();
	Locator::factory = gameObjectFactory;

	currentScene = new Scene();
	currentScene->init();

	Actor* spy = gameObjectFactory->CreateGameObject<Spy>();
	Actor* guard = gameObjectFactory->CreateGameObject<Guard>();

	// implicit brace initialization does not seem to work on struct member assignment
	spy->transform->position = {10.0f, 10.0f};
	guard->transform->position = {20.0f, 30.0f};
};

void GameApplication::loadAllShaders() {
	// Create and compile our GLSL program from the shaders
	GLuint programID = loadShaders("resources/shaders/SimpleVertexShader.glsl", "resources/shaders/SimpleFragmentShader.glsl");
}

void GameApplication::destroy() {
	delete currentScene;

	delete renderer;  // or use unique_ptr
	delete inputManager;
	delete gameObjectFactory;

	// clear reverse references considered as weak
	Locator::gameApplication = nullptr;
	Locator::renderer = nullptr;
	Locator::inputManager = nullptr;
	Locator::factory = nullptr;
}

void GameApplication::processInput() {
	inputManager->processInputs();
}

void GameApplication::applyInputBindings()
{
	inputManager->applyInputBindings();
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

	renderer->clear();

	renderer->render();

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
