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

	float GetCurrent(std::string desired); // Get the current of desired stat
	float GetMax(std::string desired); // Get the max of stat

	bool HasActed() { return hasActed; }
	void SetActedBool(bool t) { hasActed = t; }

	float Attack(); // Calculate Damage
	void TakeDamage(float dmg); // Do damage reduc calculations and set Hit animation

	void MoveTo(float dt); // Move the character to its enemy
	void SetTarget(const sf::Vector2f& target) { m_target = target; }

	void SetOwner(Owner* owner);
	std::string SetName();
	std::string GetName() { return m_name; }

	AnimationManager* anim;

private:

	Owner* m_owner; // The owner of the character (IE :: Player / Enemy)
	sf::Vector2f m_target; // Target location

	PanelWithStats* m_panel; //.. Stat panel

	std::string m_name;
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

	bool hasActed;
	bool hasArrived;

	//Inventory* m_inventory Will have vector<Item*>
};

