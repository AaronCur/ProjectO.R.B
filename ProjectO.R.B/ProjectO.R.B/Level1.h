#pragma once
/*
Author: Aaron Curry
Time taken: 12 hours
*/

#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameScreen.h"
#include "TileMap.h"
#include "Xbox360Controller.h"
#include "torch.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
class GameScreen;

class Player;
class TileMap;
class Enemy;
class Torch;

class Level1
{
public:
	Level1(GameScreen &gameScreen, Player &player, TileMap &tileMap, Enemy &enemy);
	~Level1();


	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	void offScreenDetection();
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

private:
	std::map<int, std::string> m_highscoreTable;
	std::map<sf::Text, sf::Text> m_highscoreTableDisplay;;
	sf::Time m_cumulativeTime;//the time 
	sf::CircleShape test;
	Player &m_player;
	Enemy &m_Enemy;
	TileMap &m_tileMap;
	GameScreen *m_gameScreen;
	sf::Font Font;
	std::stringstream m_s_score;
	std::stringstream m_s_Highscore;

	sf::View follow;
	sf::Text placement;

	sf::Text nameTable;
	sf::Text scoreTable;

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
};