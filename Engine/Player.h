#pragma once
#include "Panel.h"
#include "Owner.h"

//Sample Locations (to be fixed with a state machine)
/////////////////////////////////////////////////////
enum class Location
{
	Main_Menu,
	Battle,
	Options
};

/////////////////////////////////////////////////////

class Player : public Owner
{
public:
	Player(const sf::Vector2f& pos, float gold, Location loc);

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

private:
	float m_gold; // $$ yall

	Character* starter; // FIX THIS, DONT WANT A STARTER!!!

	//Inventory* m_inventory; Player's inventory (to be decided what player specific items) may not be needed

	Location m_location;
};

