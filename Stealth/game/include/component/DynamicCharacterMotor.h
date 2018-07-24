//
// Created by L Nguyen Huu on 02/03/15 ap. J.-C..
// Copyright (c) 2015 L Nguyen Huu. All rights reserved.
//


#pragma once

#include "component/ScriptComponent.h"

class Controller;

class DynamicCharacterMotor : public ScriptComponent
{

public:
	DynamicCharacterMotor();
	virtual ~DynamicCharacterMotor();
	DynamicCharacterMotor(const DynamicCharacterMotor &) = delete;
	DynamicCharacterMotor &operator=(const DynamicCharacterMotor &) & = delete;

	void start() override;
	void update(float dt) override;

private:
	Controller* controller = nullptr;

	/* Parameters*/

	float speed = 50.0f;
};
