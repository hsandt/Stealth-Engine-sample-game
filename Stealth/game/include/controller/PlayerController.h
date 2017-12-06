//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//


#pragma once

#include "Controller.h"

// REFACTOR WIP: PlayerController/AIController have no real differences, since the actor classes are doing all the job
class PlayerController : public Controller {
public:
    PlayerController();
    virtual ~PlayerController();

	static std::string getStringID() { return "AIController"; }
	std::string getClassStringID() const override { return getStringID(); }

	PlayerController(const PlayerController &) = delete;
    PlayerController &operator=(const PlayerController &) & = delete;
    PlayerController(PlayerController &&) = default;
    PlayerController &operator=(PlayerController &&) & = default;

	void update() override;

private:
	/// Set the control move horizontal intention to a normalized intention vector
	void moveHorizontal(float value);

	/// Set the control move vertical intention to a normalized intention vector
	void moveVertical(float value);
};


