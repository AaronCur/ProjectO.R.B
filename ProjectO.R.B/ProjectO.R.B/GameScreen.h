/*
Author: Jack Dalton
Date started: 3/11/2017
Date finished:
time spent: 7 hours
*/

#pragma once
#include "Player.h"
#include "Game.h"
#include "Xbox360Controller.h"

class Game;
class Player;

class GameScreen
{
public:
	GameScreen(Game &game, Player &player);
	~GameScreen();

	void update(sf::Time t, Xbox360Controller &controller);
	void render(sf::RenderWindow &window);
	
private:
	sf::CircleShape test;
	Player &m_player;
	Game *m_game;

	sf::View follow;

	sf::Texture m_BGtexture;
	sf::Sprite m_BGsprite;
};