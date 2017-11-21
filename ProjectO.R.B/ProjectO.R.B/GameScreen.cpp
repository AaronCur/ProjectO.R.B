#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player, TileMap &tileMap):
m_player(player),
m_tileMap(tileMap)
{
	follow.setViewport(sf::FloatRect(0, 0, 1, 1));
	follow.setSize(3480, 2160);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
	m_BGtexture.loadFromFile("./resources/images/BG.png");
	m_BGsprite.setTexture(m_BGtexture);
	m_BGsprite.setPosition(0, 0);

	
}

GameScreen::~GameScreen()
{

}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	m_player.update(t);

	if (m_player.m_position.x > 2865)
	{
		follow.setCenter(2865, m_player.m_position.y - 200);
	}

	else if (m_player.m_position.x < 990)
	{
		
		follow.setCenter(990, m_player.m_position.y - 200);
	}
	else
	{
		follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
	}
	//std::cout << m_player.m_position.x << std::endl;
}

void GameScreen::render(sf::RenderWindow &window)
{
	window.clear();
	window.setView(follow);
	window.draw(m_BGsprite);
	m_tileMap.render(window);
	m_player.render(window);

	
}