#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player):
m_player(player)
{
	follow.setViewport(sf::FloatRect(0, 0, 1, 1));
	follow.setSize(1920, 1080);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
	
}

GameScreen::~GameScreen()
{

}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	m_player.update(t);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
}

void GameScreen::render(sf::RenderWindow &window)
{
	window.setView(follow);
	m_player.render(window);
}