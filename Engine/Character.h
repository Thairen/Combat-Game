#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "ButtonTypes.h"

#include <iostream>
#include <string>
#include <vector>

class Stat;
class Owner;
class Character;
class PanelWithStats;
class PanelWithButtons;
class AnimationManager;

class Character : public GameObject
{
public:
	Character(std::string texturePath, const sf::Vector2f & pos, Owner* owner);
	~Character();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

	float GetCurrent(std::string desired);
	float GetMax(std::string desired);

	float Attack();
	void TakeDamage(float dmg);

	void SetOwner(Owner* owner);

	void Action(ButtonType type); // Does behavior based off type of button clicked.
	std::string SetName();

	std::string m_name; // Make a getter or something, just fix the reason this isnt private

private:

	Owner* m_owner;

	PanelWithStats* m_panel;
	PanelWithButtons* m_buttonPanel;

	AnimationManager* anim;

	//std::vector<Stat*> m_stats;  Preffered way to store stats
	Stat* m_health;
	Stat* m_strength;
	Stat* m_defense;
	Stat* m_level;
	Stat* m_exp;

	//SUPER TEMP======================
	std::string prefix[16] = { "Ste", "Mah", "Joa", "Mar", "Tin", "Gra", "Flo", "Sto", "Cor", "Dor", "Gan", "Ch", "Bra", "Da", "Fra", "Sta" };
	std::string mid[16] = { "ven", "tun", "tre", "sun", "ohn", "ger", "der", "fla", "net", "meh", "harl", "guh", "and", "ave", "gin", "sin" };
	std::string suffix[16] = { "son", "yen", "ith", "tran", "gov", "man", "jer", "ser", "don", "ez", "en", "an", "ve", "net", "fo", "ohm" };
	//================================

	//Inventory* m_inventory Will have vector<Item*>

	//May need to extend to equipped, IE std::vector<Item*> m_equippedItems
	//Maybe better as an Array since amount of equipped items will be known
};

