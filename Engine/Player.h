#pragma once
#include <vector>
#include "Character.h"
#include "Panel.h"

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

	void Update(sf::RenderWindow* window, float dt);
	void Draw(sf::RenderWindow* window);

	void AddCharacter(Character* character);

private:
	float m_gold; // $$ yall
	std::vector<Character*> m_characterList; // List of the player's characters

	//Inventory* m_inventory; Player's inventory (to be decided what player specific items) may not be needed

	PanelWithStats* m_panel;
	PanelWithButtons* m_actionPanel;

	Location m_location; // Tell the game where the player is
};

