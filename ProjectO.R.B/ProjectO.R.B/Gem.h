#pragma once
#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Player.h"
#include "Animation.h"
#include <sstream>
#include "SFML\Audio.hpp"

class Player;
class TileMap;
class Animation;

class Gem
{
public:
	Gem(float x, float y);
	~Gem();

	bool collide = false;
	void update(sf::Time t, Player &e);
	void render(sf::RenderWindow &window);
	void collision(Player &player);
	sf::Vector2f m_position;
	sf::RectangleShape gemRect;


private:
	TileMap m_tilemap;
	sf::Texture gemTexture;
	sf::Sprite gemSprite;
	sf::Time time;
	sf::Time m_cumulativeTime;
	Animation animation;
	sf::Music item;
};
