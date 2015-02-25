//
//  GameObject.h
//  Stealth
//
//  Created by L Nguyen Huu on 04/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#import "Point3.h"

class GameObject
{
    
public:
    
    static int last_id;

    GameObject();
    GameObject(const Point3d & pos);
    virtual ~GameObject();
    GameObject(const GameObject &) = delete;
    GameObject &operator=(const GameObject &) & = delete;
    GameObject(GameObject&&) = delete;
    GameObject &operator=(GameObject&&) & = delete;

    // id
    int ID() const;

    // update
    virtual void update(double dt) = 0;

    // position
    Point3d GetPosition() const;
    void SetPosition(const Point3d & pos);

private:

    int id;
    Point3d pos;

};
