/*
Author: Jack Dalton
Date started: 3/11/2017
Date finished:
time spent: 7 hours
*/

#pragma once
#include "Player.h"
#include "Game.h"
#include "TileMap.h"
#include "Xbox360Controller.h"
#include <iostream>
#include <fstream>
class Game;
class Player;
class TileMap;

class GameScreen
{
public:
	GameScreen(Game &game, Player &player,TileMap &tileMap);
	~GameScreen();

	void update(sf::Time t, Xbox360Controller &controller);
	void render(sf::RenderWindow &window);
	void offScreenDetection();
	void updateScroll();
	void getHighscore();
	bool m_gameOver = false;
	float _highScore;
	float _score;
//	std::vector<std::string> m_highscoreData;
	
private:
	sf::CircleShape test;
	Player &m_player;
	TileMap &m_tileMap;
	Game *m_game;
	
	sf::View follow;

	sf::Texture m_BGtexture;
	sf::Sprite m_BGsprite;

	sf::Texture m_GOtexture;
	sf::Sprite m_GOsprite;

	sf::Texture m_tableTxt;
	sf::Sprite m_TableSprite;
};