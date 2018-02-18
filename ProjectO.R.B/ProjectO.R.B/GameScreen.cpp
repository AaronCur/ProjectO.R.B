#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player, TileMap &tileMap, Enemy &enemy) :
	m_currentLevelState(LevelState::Level1)

{
	m_level1 = new Level1(*this, m_player, m_tileMap, m_enemy);


}

GameScreen::~GameScreen()
{

}


void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	switch (m_currentLevelState)
	{
	case LevelState::None:
		//	m_splashScreen->print(time);
		std::cout << "no LevelState" << std::endl;
		break;
	case LevelState::Level1:
		m_level1->update(t);
		break;
	case LevelState::Level2:
		//m_CoopScreen->update(time, *controller);
	default:
		break;
	}

}

/// <summary>
/// sets the current game state 
/// </summary>
/// <param name="gameState"></param>
void GameScreen::setLevelState(LevelState levelState)
{
	m_currentLevelState = levelState;
}
void GameScreen::render(sf::RenderWindow &window)
{

	

	switch (m_currentLevelState)
	{
	case LevelState::None:
		//	m_splashScreen->print(time);
		std::cout << "no LevelState" << std::endl;
		break;
	case LevelState::Level1:
		m_level1->render(window);
		break;
	case LevelState::Level2:
		//m_CoopScreen->update(time, *controller);
	default:
		break;
	}



}