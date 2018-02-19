#pragma once
/*
*Author: Jack Dalton
*/

#include "Player.h"
#include "Enemy.h"
#include "GameScreen.h"
#include "TileMap2.h"
#include "Xbox360Controller.h"
#include "torch.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "Gem.h"
class GameScreen;

class Player;
class TileMap2;
class Enemy;
class Torch;
class Gem;

class Level2
{
public:
	Level2(GameScreen &gameScreen, Player &player, TileMap2 &tileMap, Enemy &enemy);
	~Level2();


	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void offScreenDetection();
	void TrapCollision();
	void updateScroll();
	void reset();
	void getHighscore();
	bool m_gameOver = false;
	float _highScore;
	float _score;
	std::string _Name;
	sf::Text tableName;
	sf::Text yourScore;
	sf::Text tableScore;
	std::string s_tableName;
	//	std::vector<std::string> m_highscoreData;
	std::vector<Torch *> checkpoints;
	std::vector<Gem *> gems;

private:
	std::map<int, std::string> m_highscoreTable;
	std::map<sf::Text, sf::Text> m_highscoreTableDisplay;
	sf::Time m_cumulativeTime;//the time 
	sf::CircleShape test;
	Player &m_player;
	Enemy &m_Enemy;
	TileMap2 &m_tileMap;
	GameScreen *m_gameScreen;
	sf::Font Font;
	std::stringstream m_s_score;
	std::stringstream m_s_Highscore;

	sf::View follow;
	sf::Text placement;

	sf::Text nameTable;
	sf::Text scoreTable;

	sf::Texture m_gemHUD;
	sf::Sprite m_gemHUDSprite;

	sf::Texture m_BGtexture;
	sf::Sprite m_BGsprite;

	sf::Texture m_GOtexture;
	sf::Sprite m_GOsprite;

	sf::Texture m_tableTxt;
	sf::Sprite m_TableSprite;

	sf::Shader m_snowShader;
	float updateShader = 0;
	sf::Texture m_snowTexture;
	sf::Sprite m_snowSprite;
	sf::Time time;
	std::string inputName;
	bool gettable = true;

	sf::Text Reset;

	sf::Text gemText;
	sf::Text gemText2;
	int gemCount = 0;
	sf::Text scoreHUD;
};