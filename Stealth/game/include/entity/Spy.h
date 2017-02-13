//
//  Spy.h
//  Stealth
//
//  Created by L Nguyen Huu on 14/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//

#pragma once

#include <string>

#include "entity/PlayerCharacter.h"

class Spy : public PlayerCharacter
{
public:
    Spy();
    virtual ~Spy();

    Spy(const Spy &) = delete;
    Spy &operator=(const Spy &) & = delete;
    Spy(Spy&&) = default;
    Spy &operator=(Spy&&) & = default;

	void setupInputBindings() override;

protected:
	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "Spy"; }

};
