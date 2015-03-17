//
//  Character.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 28/01/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#include "Character.h"

using namespace std;

Character::Character() : GameObject()
{
}

Character::Character(const Point3d & pos) : GameObject(pos)
{
}

Character::~Character()
{
}

void Character::update(double dt)
{
    // let controller set intention
    if(controller)
        controller->setIntention();
    else {
        cout << "No controller found on Character" << endl;
    }
    speed = 10;
    // move based on intention
    pos += controller->getIntention().move * speed;
}

void Character::render(SDL_Renderer *renderer) {
     //cout << "rendering at " << go -> GetPosition().x() << endl;
        //BOOST_LOG_TRIVIAL(warning) << "test";
    SDL_Rect r;
    //int w = 640, h = 480;

    r.w = 20;
    r.h = 20;
    r.x = GetPosition().x();
    r.y = GetPosition().y();

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0, 0xff);
    SDL_RenderFillRect(renderer, &r);
}
