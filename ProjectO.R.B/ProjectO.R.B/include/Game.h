#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


/// <summary>
/// @brief Main class for the projectO.R.B project.
/// author Aaron Curry
/// </summary>

//each class is declared
//class License;

enum class
	GameState
{
//	None,

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

};
