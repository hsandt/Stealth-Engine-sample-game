//
// Created by wing on 17/04/12.
//

#pragma once

#include "application/GameApplication.h"

class StealthGameApplication : public GameApplication
{
private:

public:
	StealthGameApplication();
	virtual ~StealthGameApplication();

	StealthGameApplication(const StealthGameApplication &) = delete;
	StealthGameApplication & operator=(const StealthGameApplication &) = delete;

private:
	void onLoadNextScene() override;
};


