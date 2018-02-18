#pragma once

/*
/Author: Jack Dalton
/date started:3/11/2017
/date finished:
/time spent: 7 hours
*/
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Animation.h"
#include <sstream>

class Game;
class TileMap;

class ScrollEnemy
{
public:
	ScrollEnemy();
	~ScrollEnemy();

	bool goalreached = false;
	int distToGoal;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void collision();
	void respawn();
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	bool left = true;

private:
	sf::Vector2f m_force;
	sf::Texture enemyTxt;
	sf::Vector2f m_maxForce;
	sf::RectangleShape enemyRect;
	Animation animation;
};