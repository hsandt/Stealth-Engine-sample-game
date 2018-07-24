//
// Created by wing on 17/02/12.
//

#pragma once

#include "entity/Character.h"

/**  Character controlled by the AI
 *
 */
class AICharacter : public Character {
public:
	AICharacter();
	AICharacter(const std::string &name);
	virtual ~AICharacter();
	AICharacter(const AICharacter &) = delete;
	AICharacter &operator=(const AICharacter &) & = delete;

	/* Update */

	/// Update intention and physics
	virtual void update(float dt) override;

protected:
	/* Identifier */

	/// Return the default name of a new instance of this game object
	virtual std::string getDefaultName() const override { return "AICharacter"; }

	/// Think and update the intention
	virtual void updateIntention() = 0;
};

