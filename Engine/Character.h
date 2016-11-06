#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Stat.h"
#include "Panel.h"
#include <vector>

//Temp
enum class CharacterType
{
	Cloud,
	Tifa,
	Aerith,
	RedX,
	Barrett,
	CaitSith,
	Yuffie,
	Vincent,
	Cid
};

class Character : public GameObject
{
public:
	Character(CharacterType type, const sf::Vector2f & pos);
	~Character();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

	float GetCurrent(std::string desired);
	float GetMax(std::string desired);

	void SetCharacter(); //Set the sprite rect depending on type

	std::string m_name; // Make a getter or something, just fix the reason this isnt private
private:

	
	Stat* m_health;
	Stat* m_strength;
	Stat* m_defense;
	Stat* m_level;
	Stat* m_exp;

	PanelWithStats* m_panel;
	PanelWithButtons* m_buttonPanel;



	//std::vector<Stat*> m_stats;  Preffered way to store stats

	//Inventory* m_inventory Will have vector<Item*>

	//May need to extend to equipped, IE std::vector<Item*> m_equippedItems
	//Maybe better as an Array since amount of equipped items will be known

	//Temporary till perm Sprites added
	CharacterType m_type;
};

