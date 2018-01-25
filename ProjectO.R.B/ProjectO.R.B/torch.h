#pragma once
#include "Player.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Animation.h"
#include <sstream>

class Torch
{
public:
	Torch();
	~Torch();

	bool checkpoint = false;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void collision();
	sf::Vector2f m_position;
	
private:
	sf::Texture torchTxt;
	Player *m_player;
	sf::Shader torchShader;
	float updateShader = 0;
	sf::Texture m_shaderTexture;
	sf::Sprite m_shaderSprite;
	sf::Sprite torchSprite;
	sf::Time time;
	sf::Time m_cumulativeTime;
};