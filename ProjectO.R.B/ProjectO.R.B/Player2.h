/*
/Author: Aaron Curry
/date started: 25/1/2018
/date finished:
/time spent: 
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

class Player2
{
public:
	Player2();
	~Player2();

	bool goalreached = false;
	bool moveX = true;
	bool gravity = true;
	float pixelsToMetres;
	float m_radius;
	int distToGoal;

	void update(sf::Time t, float x, float y);
	void render(sf::RenderWindow &window);
	void applyForce(sf::Vector2f force);
	void jump();
	void moveLeft();
	void moveRight();
	void keyHandler();
	void collision();
	void respawn(float x, float y);
	sf::Text distance;
	sf::Text metresToGoal;
	std::stringstream distString;

	sf::Vector2f m_position;
	sf::Vector2f m_initialVelocity;
	Health m_health;
	int jumpCount = 0;
	bool jumpPress = false;
	int state = 0;


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