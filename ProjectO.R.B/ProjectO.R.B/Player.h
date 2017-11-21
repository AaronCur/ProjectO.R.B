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
#include "Animation.h"

class Game;

class Player
{
public:
	Player();
	~Player();

	bool jumped=false;
	float pixelsToMetres;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void applyForce(sf::Vector2f force);

	sf::Vector2f m_position;
	sf::Vector2f m_initialVelocity;



	

private:
	sf::CircleShape player;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Texture playerTxt;
	sf::Sprite playerSprite;


	
};