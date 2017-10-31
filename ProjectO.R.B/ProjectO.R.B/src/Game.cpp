#include "SFML/Audio.hpp"
#include "Game.h"

static double const MS_PER_UPDATE = 10.0;

Game::Game() :
	m_window(sf::VideoMode(1000, 650, 32), "ProjectO.R.B")
	//m_currentGameState(GameState:://)

{
	
	

		
}

	Game::~Game()
	{
	
	}

	
/// <summary>
/// Main game entry point - runs until user quits.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);


	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}



/// <summary>
/// @brief Check for events
/// 
/// Allows window to function and exit. 
/// Events are passed on to the Game::processGameEvents() method
/// </summary>
void Game::processEvents()
{
	
}

/// <summary>
/// sets the current game state 
/// </summary>
/// <param name="gameState"></param>
void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

/// <summary>
/// @brief Handle all user input.
/// 
/// Detect and handle keyboard input.
/// </summary>
/// <param name="event">system event</param>
void Game::processGameEvents()
{



}

/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	
	
}


/// <summary>
/// @brief draw the window for the game.
/// 
/// draw buttons and text on left side
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	
	m_window.display();
}


