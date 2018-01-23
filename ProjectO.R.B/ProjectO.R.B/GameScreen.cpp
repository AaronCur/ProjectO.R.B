#include "GameScreen.h"

GameScreen::GameScreen(Game &game, Player &player, TileMap &tileMap,Enemy &enemy):
m_player(player),
m_Enemy(enemy),
m_tileMap(tileMap)

{
	if (!Font.loadFromFile("resources/images/Adventure.otf"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	follow.setViewport(sf::FloatRect(0, 0, 1, 1));
	follow.setSize(1920, 1080);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y - 200);
	m_BGtexture.loadFromFile("./resources/images/BG.png");
	m_BGsprite.setTexture(m_BGtexture);
	m_BGsprite.setPosition(0, -40);
	m_GOtexture.loadFromFile("./resources/images/gameoverbg.png");
	m_GOsprite.setTexture(m_GOtexture);
	m_GOsprite.setPosition(0, 0);
	m_tableTxt.loadFromFile("./resources/table.png");
	m_TableSprite.setTexture(m_tableTxt);

	m_snowTexture.loadFromFile("./resources/snowtexture.png");
	m_snowSprite.setTexture(m_snowTexture);

	if (!m_snowShader.loadFromFile("./resources/snowShader.frag", sf::Shader::Fragment))
	{
		std::cout << "Shader is not available" << std::endl;
	}

	m_snowShader.setParameter("time", 0);
	m_snowShader.setParameter("resolution", 1920, 1080);

	m_snowSprite.setPosition(0, 0);

	follow.setCenter(960, m_player.m_position.y - 300);
	
	yourScore.setFont(Font);
	yourScore.setCharacterSize(60);
	yourScore.setColor(sf::Color::Black);


	GoalReached.setFont(Font);
	GoalReached.setColor(sf::Color(255, 233, 0));
	GoalReached.setCharacterSize(100);
	GoalReached.setString("You reached the Goal!!");

	tableScore.setFont(Font);
	tableScore.setCharacterSize(45);
	tableScore.setColor(sf::Color::Black);

	tableName.setFont(Font);
	tableName.setCharacterSize(45);
	tableName.setColor(sf::Color::Black);
	
	m_s_score << 0;
	m_s_Highscore << 0;

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
	/*if (m_player.m_position.x >= 1475 && follow.getCenter().x < 1475 +1392)
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
		follow.move(13, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 6) && follow.getCenter().x < 1475 + (1392 * 7))
	{
		follow.move(14, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 7) && follow.getCenter().x < 1475 + (1392 * 8))
	{
		follow.move(16, 0);

	}
	else if (follow.getCenter().x >= 1475 + (1392 * 8) && follow.getCenter().x < 1475 + (1392 * 9))
	{
		follow.move(19, 0);

	}*/


}

void GameScreen::update(sf::Time t, Xbox360Controller &controller)
{
	if (m_gameOver == false)
	{
		m_cumulativeTime += t;
		updateShader = m_cumulativeTime.asSeconds();

		m_snowShader.setParameter("time", updateShader);
		
		m_player.update(t);
		m_Enemy.update(t);
		offScreenDetection();

		if (m_player.m_position.x < 1470 && m_player.m_position.x > 960)
		{
			follow.setCenter(m_player.m_position.x, follow.getCenter().y);
		}
		else if (m_player.m_position.x > 1470)
		{
			if (m_player.m_position.x >= m_Enemy.m_position.x)
			{
				follow.setCenter(m_player.m_position.x, follow.getCenter().y);
			}
			else if (m_Enemy.m_position.x >= m_player.m_position.x)
			{
				follow.setCenter(m_Enemy.m_position.x, follow.getCenter().y);
			}
		}


		if (m_player.m_position.x > 1470 && follow.getCenter().x < 13040)
		{
			follow.setCenter(follow.getCenter().x, 510);
			//updateScroll();
			m_GOsprite.setPosition(follow.getCenter().x - (1920/2) , follow.getCenter().y - (1080 /2));
			

		}
		m_player.distance.setPosition(follow.getCenter().x, 100);
		m_player.metresToGoal.setPosition(follow.getCenter().x + 300, 100);
		_score = 14000 - m_player.distToGoal;
		m_s_score.str("");
		m_s_score << _score;

	//	m_snowSprite.setPosition(follow.getCenter().x - (700), follow.getCenter().y - (1080 / 2));

	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			m_player.m_position.x = 500;
			m_player.m_position.y = 800;

			follow.setCenter(960, 500);

			m_gameOver = false;

		}
	}
		
	
}

void GameScreen::getHighscore()
{
	std::ifstream readFile;
	readFile.open("./resources/HighScore.txt");
	yourScore.setString(m_s_score.str()+" m");

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> _highScore;
			readFile >> _Name;
			//std::cout << "Highscores:" + _highScore << std::endl;
		}
		m_s_Highscore.str("");
		m_s_Highscore << _highScore;
		//std::cout << "Highscores:" + _highScore << std::endl;
	}

	
	

	
	readFile.close();

	std::ofstream writeFile("./resources/HighScore.txt");

	if (writeFile.is_open())
	{
		if (_score > _highScore)
		{
			_highScore = _score;
			m_s_Highscore.str("");
			m_s_Highscore << _highScore;
			std::cout << " NEW HIGHSCORE! Enter your name Below :" << std::endl;
			std::cin >> _Name;
		}
		writeFile << _highScore << "\n" ;
		writeFile << _Name;
	}
	writeFile.close();
	tableScore.setString(m_s_Highscore.str() + " m");
	tableName.setString(_Name);
}
void GameScreen::render(sf::RenderWindow &window)
{
	window.clear(sf::Color(208, 244, 247));
	window.setView(follow);
	window.draw(m_player.distance);
	window.draw(m_BGsprite);
	m_tileMap.render(window);
	m_player.render(window);
	m_Enemy.render(window);


	if (m_gameOver == true)
	{
		
		window.draw(m_GOsprite);
		m_TableSprite.setPosition(follow.getCenter().x-200, follow.getCenter().y-200);
		window.draw(m_TableSprite);
		getHighscore();
		yourScore.setPosition(follow.getCenter().x + 100, follow.getCenter().y + 100);
		window.draw(yourScore);
		tableScore.setPosition(follow.getCenter().x + 350, follow.getCenter().y );
		window.draw(tableScore);
		tableName.setPosition(follow.getCenter().x , follow.getCenter().y);
		window.draw(tableName);
	}

	if (m_player.goalreached == true)
	{
		window.draw(m_GOsprite);
 		GoalReached.setPosition(follow.getCenter().x-250, follow.getCenter().y-300);
		m_TableSprite.setPosition(follow.getCenter().x - 250, follow.getCenter().y - 200);
		window.draw(m_TableSprite);
		window.draw(GoalReached);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			m_player.m_position.x = 500;
			m_player.m_position.y = 800;

			follow.setCenter(960, 500);

			m_player.goalreached = false;

		}

	}
	window.draw(m_BGsprite, &m_snowShader);
	

	
}