//
// Created by wing on 17/02/12.
//

#pragma once

#include "entity/Character.h"

/**  Character controlled by the player
 *
 */
class PlayerCharacter : public Character {
public:
	PlayerCharacter();
	virtual ~PlayerCharacter();
	PlayerCharacter(const PlayerCharacter &) = delete;
	PlayerCharacter &operator=(const PlayerCharacter &) & = delete;

	virtual void setupInputBindings() = 0;

	virtual void init() override;

	virtual void update(float dt) override;

protected:
	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "PlayerCharacter"; }

	/* Components */

	/// Input component
	InputComponent* inputComponent = nullptr;
};

