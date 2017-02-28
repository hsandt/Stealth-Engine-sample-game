//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//


#pragma once

// GCC7: use algorithm std::clamp
//#include <algorithm>
#include <iostream>

#include "geometry/Vector2.h"
#include "utils/MathUtil.h"

class Controller {

public:
	Controller();
	virtual ~Controller();
	Controller(const Controller &) = delete;
	Controller &operator=(const Controller &) & = delete;

	Vector2 getMoveIntention() const { return moveIntention; }
	void setMoveIntention(const Vector2& moveVector) {
		moveIntention = Vector2 { math::clamp(moveVector.x(), -1.0f, 1.0f), math::clamp(moveVector.y(), -1.0f, 1.0f) };
	}

protected:
    Vector2 moveIntention;

};
