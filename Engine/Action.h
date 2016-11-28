#pragma once
#include <SFML\Graphics.hpp>
#include "Character.h"

// BASE ACTION CLASS - MOTHER CLASS FOR EVERY CHARACTER ACTION (SKILL, ATTACK, ITEM, ETC)

class Action
{
public:
	Action(Character* owner);

	virtual void Start(); // Run behavior that happens at the beginning of the skill
	virtual void End(); //Finish up behavior before the action gets destroyed
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);

	//For setting target (Can possibly be the owning character for self casting skills or whatever)
	void SetTarget(Character* target) { m_target = target; }

private:
	Character* m_owner;
	Character* m_target;
};

