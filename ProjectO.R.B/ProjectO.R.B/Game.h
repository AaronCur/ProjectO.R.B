#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "License.h"
#include "Splash.h"
#include "MainMenu.h"
#include "Xbox360Controller.h"


/// <summary>
/// @brief Main class for the projectO.R.B project.
/// author Aaron Curry
/// </summary>

//each class is declared
class License;
class Splash;
class MainMenu;

enum class
	GameState
{
	None,
	License,
	Splash,
	MainMenu

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
	Xbox360Controller *controller;

};
