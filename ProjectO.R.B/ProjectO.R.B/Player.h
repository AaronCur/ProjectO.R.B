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
#include "Tilemap2.h"
#include "Animation.h"
#include "Health.h"
#include <sstream>
#include "SFML\Audio.hpp"

class Game;
class TileMap;
class TileMap2;
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
	float score = 1.0f;
	float m_heartscore = 1.0f;
	float m_radius;
	int distToGoal;
	bool level2 = true;

	void update(sf::Time t, float x, float y);
	void render(sf::RenderWindow &window);
	void applyForce(sf::Vector2f force);
	void jump();
	void moveLeft();
	void moveRight();
	void keyHandler();
	void collision();
	bool goalCollision();
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
	sf::RectangleShape playerRect;
	sf::Texture playerTxt;
	float playerColWidth;
	float playerColHeight;

	bool trapCollided = false;

	int gemCount = 0;


private:
	sf::CircleShape player;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Vector2f m_force;
	sf::Vector2f m_maxForce;
	sf::Vector2f m_groundLocation;
	sf::Texture m_BGtexture;
	sf::Sprite m_BGSprite;
	bool dirLeft = true ;
	bool dirRight = true;

	sf::Font Font;
	Animation animation;
	TileMap m_tileMap;
	TileMap2 m_tileMap2;
	sf::SoundBuffer buffer;
	sf::Music jumpsound;
	sf::Music item;
	sf::Music wall;
	sf::Music die;
	bool jumped;

};