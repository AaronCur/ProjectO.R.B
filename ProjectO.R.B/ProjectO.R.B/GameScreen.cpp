#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player):
m_player(player)
{
	
	
}

GameScreen::~GameScreen()
{

}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	m_player.update(t);
}

void GameScreen::render(sf::RenderWindow &window)
{

	m_player.render(window);
}