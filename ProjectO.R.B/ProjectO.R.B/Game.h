#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "License.h"
#include "Splash.h"
#include "GameScreen.h"
#include "MainMenu.h"
#include "Player.h"
#include "Xbox360Controller.h"
#include "TileMap.h"
#include "Enemy.h"


/// <summary>
/// @brief Main class for the projectO.R.B project.
/// author Aaron Curry
/// </summary>

//each class is declared
class License;
class Splash;
class GameScreen;
class MainMenu;

enum class
	GameState
{
	None,
	License,
	Splash,
	MainMenu,
	GameScreen

};

class Game
{
public:
	Game();
	~Game();
	void run();
	GameState m_currentGameState;
	GameState m_previousGameState;
	void setGameState(GameState gameState);

protected:
	void update(sf::Time time);
	void render();
	void processEvents();

	void processGameEvents();

	// main window
	sf::RenderWindow m_window;

	sf::Font m_agentOrange;//font 
	sf::Font m_meatLoaf;
	sf::Font m_adventure;

	License *m_licenseScreen;
	Splash *m_splashScreen;
	MainMenu *m_mainMenu;
	GameScreen *m_GameScreen;
	Xbox360Controller *controller;
	Player m_player;
	TileMap m_tileMap;
	Enemy m_enemy;

};
