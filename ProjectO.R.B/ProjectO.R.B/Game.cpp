#include "SFML/Audio.hpp"
#include "Game.h"

static double const MS_PER_UPDATE = 10.0;

Game::Game() :
	m_window(sf::VideoMode(1920, 1080, 32), "ProjectO.R.B"),
	m_currentGameState(GameState::License)


{
	if (!m_agentOrange.loadFromFile("./resources/images/AGENTORANGE.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	if (!m_meatLoaf.loadFromFile("./resources/images/Meatloaf.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	if (!m_adventure.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	
	//initialsing screens
	m_licenseScreen = new License(*this, m_agentOrange);
	m_splashScreen = new Splash(*this, m_meatLoaf, m_adventure);
	m_mainMenu = new MainMenu(*this, m_meatLoaf, m_agentOrange);
	m_GameScreen = new GameScreen(*this, m_player);
	controller = new Xbox360Controller();
		
}

	Game::~Game()
	{
		delete(m_licenseScreen);
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

// <summary>
/// @brief Check for events
/// 
/// Allows window to function and exit. 
/// Events are passed on to the Game::processGameEvents() method
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		event.type == sf::Event::KeyPressed;
		//To check for the Akeypress to transition from splash screen to main menu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_currentGameState == GameState::Splash)
		{
			m_splashScreen->checkButtonPress();
		}
		if (m_mainMenu->close)
		{
			m_window.close();
		}
		///sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
	}

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
//{
	//sf::Event event;
	//while (m_window.pollEvent(event))
	//{
		//if (event.type == sf::Event::Closed)
		//{
		//	m_window.close();
		//}
		//event.type == sf::Event::KeyPressed;
		//To check for the Akeypress to transition from splash screen to main menu
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || controller->m_currentState.A == true && m_currentGameState == GameState::License)
	  //  {
		//	m_splashScreen->checkButtonPress();
		//}
		//if (m_mainMenu->close)
		//{
		//	m_window.close();
		//}
		//sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
	//}


//
/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	switch (m_currentGameState)
	{
	case GameState::None:
		//	m_splashScreen->print(time);
		std::cout << "no GameState" << std::endl;
		break;
	case GameState::License:
		m_licenseScreen->update(time);
		break;
	case GameState::Splash:
		m_splashScreen->update(time);
		break;
	case GameState::MainMenu:
		m_mainMenu->update(time, *controller);
		break;
	case GameState::GameScreen:
		m_GameScreen->update(time, *controller);
	default:
		break;
	}
	
}


/// <summary>
/// @brief draw the window for the game.
/// 
/// draw buttons and text on left side
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	switch (m_currentGameState)
	{
	case GameState::None:
		//	m_splashScreen->print(time);
		std::cout << "no GameState" << std::endl;
		break;
	case GameState::License:
		m_licenseScreen->render(m_window);
		break;
	case GameState::Splash:
		m_splashScreen->render(m_window);
		break;
	case GameState::MainMenu:
		m_mainMenu->render(m_window);
		break;
	case GameState::GameScreen:
		m_GameScreen->render(m_window);
	default:
		break;
	}
	m_window.display();
}


