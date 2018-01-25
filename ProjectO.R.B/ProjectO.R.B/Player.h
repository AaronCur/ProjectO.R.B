/*
/Author: Jack Dalton
/date started:3/11/2017
/date finished:
/time spent: 7 hours
*/
#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Animation.h"
#include "Health.h"
#include <sstream>

class Game;
class TileMap;
class Health;

class Player
{
public:
	Player();
	~Player();

	bool goalreached = false;
	bool moveX = true;
	bool gravity = true;
	float pixelsToMetres;
	float m_radius;
	int distToGoal;
	float m_health;

	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void applyForce(sf::Vector2f force);
	void jump();
	void moveLeft();
	void moveRight();
	void keyHandler();
	void collision();
	sf::Text distance;
	sf::Text metresToGoal;
	std::stringstream distString;

	sf::Vector2f m_position;
	sf::Vector2f m_initialVelocity;
	

private:
	sf::CircleShape player;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Vector2f m_force;
	sf::Vector2f m_maxForce;
	sf::Vector2f m_groundLocation;
	sf::Texture m_BGtexture;
	sf::Sprite m_BGSprite;
	sf::Texture playerTxt;
	sf::RectangleShape playerRect;
	sf::Font Font;
	Animation animation;
	TileMap m_tileMap;
	bool jumped;
};