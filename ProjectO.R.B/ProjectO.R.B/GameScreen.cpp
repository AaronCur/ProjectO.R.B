#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player, TileMap &tileMap):
m_player(player),
m_tileMap(tileMap)
{
	follow.setViewport(sf::FloatRect(0, 0, 1, 1));
	follow.setSize(1920, 1080);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
	m_BGtexture.loadFromFile("./resources/images/BG.png");
	m_BGsprite.setTexture(m_BGtexture);
	m_BGsprite.setPosition(0, 0);

	follow.setCenter(960, m_player.m_position.y - 300);

}

GameScreen::~GameScreen()
{

}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	m_player.update(t);

	if (m_player.m_position.x < 1470 && m_player.m_position.x > 960)
	{
		follow.setCenter(m_player.m_position.x, m_player.m_position.y - 300);
		m_player.distance.setPosition(follow.getCenter().x, 100);
		m_player.metresToGoal.setPosition(follow.getCenter().x + 300, 100);
		
	}

	//else if (m_player.m_position.x < 990)
	//{
		
		//follow.setCenter(990, m_player.m_position.y - 200);
	//}
	//else
	//{
	//	follow.setCenter(m_player.m_position.x, 1300);
	//}
	

	if (m_player.m_position.x > 1470 && follow.getCenter().x < 13040 )
	{
		follow.setCenter(follow.getCenter().x, 510);
		m_player.distance.setPosition(follow.getCenter().x, 100);
		m_player.metresToGoal.setPosition(follow.getCenter().x + 300, 100);

		follow.move(5, 0);
	}

	
		
	
}

void GameScreen::render(sf::RenderWindow &window)
{

	window.clear(sf::Color(208,244,247));
	window.setView(follow);
	window.draw(m_player.distance);
	window.draw(m_BGsprite);
	m_tileMap.render(window);
	m_player.render(window);

	
}