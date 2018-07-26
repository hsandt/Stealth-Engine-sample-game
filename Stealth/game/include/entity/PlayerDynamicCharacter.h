//
// Created by wing on 17/02/12.
//

#pragma once

#include "entity/DynamicCharacter.h"

class InputComponent;

/**  Character controlled by the player
 *
 */
class PlayerDynamicCharacter : public DynamicCharacter {
public:
	PlayerDynamicCharacter();
	virtual ~PlayerDynamicCharacter();
	PlayerDynamicCharacter(const PlayerDynamicCharacter &) = delete;
	PlayerDynamicCharacter &operator=(const PlayerDynamicCharacter &) & = delete;

	virtual void setupInputBindings() {}

	virtual void init() override;

	virtual void update(float dt) override;

protected:
	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "PlayerDynamicCharacter"; }

	/* Components */

	/// Input component
	InputComponent* inputComponent = nullptr;
};

