/*
Author: Jack Dalton
Date started: 3/11/2017
Date finished:
time spent: 7 hours
*/

#pragma once
//#include "Level1.h"
#include "Level2.h"
#include "Level1.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include "TileMap.h"
#include "Tilemap2.h"
#include "Enemy.h"
#include "Player2.h"
class Game;
class Level1;
class Level2;
enum class
	LevelState
{
	None,
	Level1,
	Level2

};

class GameScreen
{
public:
	GameScreen(Game &game, Player &player, TileMap &tileMap, TileMap2 &tilemap2, Enemy &enemy);
	~GameScreen();

	LevelState m_currentLevelState;
	LevelState m_previousLevelState;
	void setLevelState(LevelState levelState);
	void update(sf::Time t, Xbox360Controller &controller);
	void render(sf::RenderWindow &window);
	void offScreenDetection();

private:
	sf::Time m_cumulativeTime;//the time 
	sf::CircleShape test;
	Game *m_game;
	Level1 *m_level1;

	Level2 *m_level2;

	Player m_player;
	Player2 m_player2;
	TileMap m_tileMap;
	TileMap2 m_tileMap2;
	Enemy m_enemy;
};