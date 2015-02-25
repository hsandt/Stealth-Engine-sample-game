//
//  GameObject.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#import <iostream>

#import "Point3.h"

#include "GameObject.h"



int GameObject::last_id = 0;

GameObject::GameObject()
{
    id = ++last_id;
}

GameObject::GameObject(const Point3d & pos) : GameObject()
{
    SetPosition(pos);
}

GameObject::~GameObject()
{
    std::cout << "GO destroyed" << std::endl;
}

int GameObject::ID() const {
    return id;
}

Point3d GameObject::GetPosition() const {
    return pos;
}

void GameObject::SetPosition(const Point3d & _pos) {
    pos = _pos;
}
