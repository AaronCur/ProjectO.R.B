#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Player.h"
#include "Animation.h"
#include <sstream>

class Player;
class TileMap;
class Animation;

class Torch
{
public:
	Torch(float x, float y);
	~Torch();

	bool checkpoint = false;
	void update(sf::Time t, Player &e);
	void render(sf::RenderWindow &window);
	void collision(Player &player);
	sf::Vector2f m_position;
	sf::RectangleShape torchRect;

	
private:
	TileMap m_tilemap;
	sf::Texture torchLit;
	sf::Texture torchUnlit;
	sf::Shader torchShader;
	float updateShader = 0;
	sf::Texture m_shaderTexture;
	sf::Sprite m_shaderSprite;
	sf::Sprite torchSprite;
	sf::Sprite torchHolder;
	sf::Time time;
	sf::Time m_cumulativeTime;
	Animation animation;
};
