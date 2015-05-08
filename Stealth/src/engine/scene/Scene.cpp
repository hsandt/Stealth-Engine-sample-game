//
//  Scene.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#import <algorithm>
#import <iostream>
#import <memory>
#import <boost/format.hpp>
#import <boost/log/trivial.hpp>
#import <boost/chrono/floor.hpp>

#include "Scene.h"

using namespace std;
using namespace boost::log;

Scene::Scene()
{
}

Scene::~Scene()
{
}

std::map<int, std::shared_ptr<GameObject>> Scene::getGameObjects() const {
	return gameObjects;
}

void Scene::addGameObject(unique_ptr<GameObject> go) {
    
    shared_ptr<GameObject> sGo {move(go)};
    
    //cout << "Adding object at " << sGo -> GetPosition().x() << " from unique_ptr &go" << endl;
    
    auto emplacePair = gameObjects.emplace(sGo -> ID(), sGo);
    if (emplacePair.second) {
        cout << "[SCENE] Added game object with id: " << sGo -> ID() << endl;
    }
    else {
        cout << "Could not add game object with id: " << sGo -> ID() << ": game object with same ID already exists in the scene." << endl;
//        BOOST_LOG_VERSION_NAMESPACE;
//        BOOST_LOG_TRIVIAL(warning) << boost::format("Could not add game object with id %d: game object with same ID already exists in the scene.") % go -> ID();
//        BOOST_CHRONO_STATIC;
    }
}

void Scene::removeGameObject(weak_ptr<GameObject> &weakGo) {
    shared_ptr<GameObject> go {weakGo.lock()};
    if (go) {
        int nbErased = (int) gameObjects.erase(go -> ID());
        if (nbErased == 0) {
//            BOOST_LOG_TRIVIAL(warning) << boost::format("Could not remove game object with id %d: no game objects with this ID in the scene.") % go -> ID();
        }
    }
}