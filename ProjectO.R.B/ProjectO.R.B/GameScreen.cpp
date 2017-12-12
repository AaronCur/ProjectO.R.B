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
	m_GOtexture.loadFromFile("./resources/images/gameoverbg.png");
	m_GOsprite.setTexture(m_GOtexture);
	m_GOsprite.setPosition(0, 0);

	follow.setCenter(960, m_player.m_position.y - 300);
	getHighscore();


}

GameScreen::~GameScreen()
{

}
void GameScreen::offScreenDetection()
{
	if ((follow.getCenter().x - (1920 / 2)) >= m_player.m_position.x + 100
		|| (follow.getCenter().y + (1080/2)) <= m_player.m_position.y-30)
	{
		if (m_player.m_position.x > 1475)
		{
			m_gameOver = true;
		}
		
	}
	else
	{
		m_gameOver = false;
	}


}
void GameScreen::updateScroll()
{
	if (m_player.m_position.x >= 1475 && follow.getCenter().x < 1475 +1392)
	{
		follow.move(8, 0);

	}
	else if (follow.getCenter().x >= 1475 + 1392 && follow.getCenter().x < 1475 + (1392 * 2))
	{
		follow.move(8.7, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 2)&& follow.getCenter().x < 1475 +(1392 * 3))
	{
		follow.move(9.4, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 3) && follow.getCenter().x < 1475 + (1392 * 4))
	{
		follow.move(10.1, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 4) && follow.getCenter().x < 1475 + (1392 * 5))
	{
		follow.move(10.8, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 5) && follow.getCenter().x < 1475 + (1392 * 6))
	{
		follow.move(11.4, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 6) && follow.getCenter().x < 1475 + (1392 * 7))
	{
		follow.move(12.1, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 7) && follow.getCenter().x < 1475 + (1392 * 8))
	{
		follow.move(12.8, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 8) && follow.getCenter().x < 1475 + (1392 * 9))
	{
		follow.move(13.5, 0);

	}


}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	if (m_gameOver == false)
	{
		m_player.update(t);
		offScreenDetection();

		if (m_player.m_position.x < 1470 && m_player.m_position.x > 960)
		{
			follow.setCenter(m_player.m_position.x, m_player.m_position.y - 300);
			//follow.setCenter(2865, m_player.m_position.y - 200);
		}

		//else if (m_player.m_position.x < 990)
		//{

		//follow.setCenter(990, m_player.m_position.y - 200);
		//}
		//else
		//{
		//	follow.setCenter(m_player.m_position.x, 1300);
		//}


		if (m_player.m_position.x > 1470 && follow.getCenter().x < 13040)
		{
			follow.setCenter(follow.getCenter().x, 510);
			updateScroll();
			m_GOsprite.setPosition(follow.getCenter().x - (1920/2) , follow.getCenter().y - (1080 /2));

		}
	}
	
	////else
	//{
	//	follow.move(0, 0);

	//}
	
		
	
}

void GameScreen::getHighscore()
{
	std::ifstream readFile;
	readFile.open("./resources/HighScore.txt");

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> _highScore;
			//std::cout << "Highscores:" + _highScore << std::endl;
			m_highscoreData.push_back(_highScore);
			std::cout << "Data" + _highScore << std::endl;
		}
		//std::cout << "Highscores:" + _highScore << std::endl;
	}
	
	readFile.close();

	//std::ofstream writeFile("./resources/HighScore.txt");

	//if (writeFile.is_open())
	//{
		//if (_score > _highScore)
		//{
		//	_highScore = _score;
		//
		//}
		//writeFile << _highScore << endl;
	//}
	//writeFile.close();
}
void GameScreen::render(sf::RenderWindow &window)
{
	window.clear(sf::Color(208, 244, 247));
	window.setView(follow);
	window.draw(m_BGsprite);
	m_tileMap.render(window);
	m_player.render(window);


	if (m_gameOver == true)
	{
		window.draw(m_GOsprite);
	}
	
	

	
}