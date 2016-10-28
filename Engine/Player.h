#pragma once
#include <vector>
#include "Character.h"

//Sample Locations (to be fixed with a state machine)
/////////////////////////////////////////////////////
enum class Location
{
	Main_Menu,
	Battle,
	Options
};

/////////////////////////////////////////////////////

class Player
{
public:
	Player(float gold, Location loc);

	void AddCharacter(Character* character);

private:
	float m_gold; // $$ yall
	std::vector<Character*> m_characterList; // List of the player's characters
	Location m_location; // Tell the game where the player is
};

