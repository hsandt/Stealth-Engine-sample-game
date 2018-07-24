//
//  Guard.h
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <string>

#include "AICharacter.h"

class Guard : public AICharacter
{
public:
    Guard();
    virtual ~Guard();

    Guard(const Guard &) = delete;
    Guard &operator=(const Guard &) & = delete;
    Guard(Guard&&) = default;
    Guard &operator=(Guard&&) & = default;

protected:
	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "Guard"; }

	void updateIntention() override;

};
