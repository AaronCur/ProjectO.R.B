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

class Game;

class Player
{
public:
	Player();
	~Player();

	bool jumped=false;
	bool moveX = false;
	float pixelsToMetres;
	float m_radius;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void applyForce(sf::Vector2f force);
	void jump();
	void moveLeft();
	void moveRight();
	void keyHandler();

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
};