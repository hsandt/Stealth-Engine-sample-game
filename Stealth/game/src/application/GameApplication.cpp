//
//  GameApplication.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>
//#include <boost/log/trivial.hpp>

// Engine
#include "Locator.h"
#include "Scene.h"
#include "GameObject.h"

// Game
#include "entity/Guard.h"
#include "entity/Spy.h"

#include "GameApplication.h"

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

		while (lag >= secPerUpdate) {
			// TODO: add limit for number of iterations to catch back
			// pass fixed deltaTime as update argument, in sec
			// ALT: use a service locator for deltaTime (fixed)
			update(secPerUpdate);
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
	// register Service Providers to Service Locators
	Locator::gameApplication = this;

	renderer = new Renderer(window);

	inputManager = new InputManager(window);
	Locator::inputManager = inputManager;

	currentScene = make_shared<Scene>();
	currentScene->init();
};

void GameApplication::destroy() {
	delete renderer;  // or use unique_ptr
	delete inputManager;
}

void GameApplication::processInput() {
	inputManager->processInputs();
//	if (inputManager->getButtonState(Button::QUIT) == ButtonState::PRESSED ||
//		inputManager->getButtonState(Button::QUIT) == ButtonState::RELEASED_PRESSED) {
//		stop();
//	}
	//SDL_Event event;
	//while (SDL_PollEvent(&event)) {
	//    switch (event.type)
	//    {
	//        case SDL_QUIT:
	//            isRunning = false;
	//            break;
	//
	//        case SDL_KEYDOWN:
	//        {
	//            if (event.key.keysym.sym == SDLK_ESCAPE)
	//            {
	//                isRunning = false;
	//            }
	//        }
	//    }
	//}
}

void GameApplication::update(double dt) {
	map<int, std::shared_ptr<GameObject>> gameObjects{currentScene->getGameObjects()};
	for (auto goIt(gameObjects.begin()); goIt != gameObjects.end(); ++goIt) {
		shared_ptr<GameObject> go{goIt->second};
		go->update(dt);
		// go -> SetPosition(go -> GetPosition() + Vec3f {23, 2, 0});
	}
	// DEBUG

}

void GameApplication::render()
{

	renderer->clear();

	std::map<int, std::shared_ptr<GameObject>> gameObjects {currentScene->getGameObjects()};
	for (auto goIt(gameObjects.begin()); goIt != gameObjects.end(); ++goIt) {
		// do not use GameObject& which would be invalid if all shared_ptr
		// to the game object disappeared in the meanwhile (~raw pointer issue)
		shared_ptr<GameObject> go {goIt->second};
		go->render(renderer);
	}
//	SDL_RenderPresent(renderer);
}


