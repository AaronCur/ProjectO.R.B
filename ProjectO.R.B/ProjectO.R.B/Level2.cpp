#include "Level2.h"

Level2::Level2(GameScreen &gameScreen, Player &player, TileMap2 &tileMap, Enemy &enemy) :
	m_player(player),
	m_Enemy(enemy),
	m_tileMap(tileMap),
	m_gameScreen(&gameScreen)

{
	if (!Font.loadFromFile("resources/images/Adventure.otf"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_player.m_position.x -= 200;
	follow.setViewport(sf::FloatRect(0, 0, 1, 1));
	follow.setSize(1920, 1080);
	follow.setCenter(m_player.m_position.x, m_player.m_position.y-200);
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

	if (!m_gemHUD.loadFromFile("resources/gemHUD.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_gemHUDSprite.setTexture(m_gemHUD);

	for (int i = 0; i < m_tileMap.m_checkpoint_position.size(); i++)
	{
		checkpoints.push_back(new Torch(m_tileMap.m_checkpoint_position[i].x, m_tileMap.m_checkpoint_position[i].y));
	}

	for (int i = 0; i < m_tileMap.m_gem_position.size(); i++)
	{
		gems.push_back(new Gem(m_tileMap.m_gem_position[i].x, m_tileMap.m_gem_position[i].y));
	}
	m_snowShader.setParameter("time", 0);
	m_snowShader.setParameter("resolution", 1920, 1080);

	m_snowSprite.setPosition(0, 0);

	follow.setCenter(960, m_player.m_position.y-300);

	yourScore.setFont(Font);
	yourScore.setCharacterSize(60);
	yourScore.setColor(sf::Color::Black);


	placement.setFont(Font);
	placement.setColor(sf::Color(20, 20, 20));
	placement.setCharacterSize(55);


	tableScore.setFont(Font);
	tableScore.setCharacterSize(45);
	tableScore.setColor(sf::Color::Black);

	tableName.setFont(Font);
	tableName.setCharacterSize(45);
	tableName.setColor(sf::Color::Black);

	nameTable.setFont(Font);
	nameTable.setCharacterSize(50);
	nameTable.setColor(sf::Color::Black);

	scoreTable.setFont(Font);
	scoreTable.setCharacterSize(50);
	scoreTable.setColor(sf::Color::Black);

	Reset.setFont(Font);
	Reset.setCharacterSize(50);
	Reset.setColor(sf::Color(20, 20, 20));

	scoreHUD.setFont(Font);
	scoreHUD.setCharacterSize(50);
	scoreHUD.setColor(sf::Color(20, 20, 20));




	m_s_score << 0;
	m_s_Highscore << 0;

}

Level2::~Level2()
{

}
void Level2::offScreenDetection()
{
	if ((follow.getCenter().x - (1920 / 2)) >= m_player.m_position.x + 100
		|| (follow.getCenter().y + (1080 / 2)) <= m_player.m_position.y - 30)
	{
		if (m_player.m_position.x > 1475)
		{

			int tempX = 0;
			int tempY = 0;


			for (int i = 0; i < checkpoints.size(); i++)
			{
				if (checkpoints[i]->m_position.x> tempX && checkpoints[i]->m_position.x < m_player.m_position.x && checkpoints[i]->checkpoint == true)
				{
					tempX = checkpoints[i]->m_position.x;
					tempY = checkpoints[i]->m_position.y;
				}
			}

			m_player.respawn(tempX, tempY);
			follow.setCenter(tempX, tempY);
			m_Enemy.respawn();


		}

	}
	else
	{
		m_gameOver = false;
	}


}

void Level2::TrapCollision()
{
	if (m_player.trapCollided == true)
	{
		if (m_player.m_position.x > 1475)
		{

			int tempX = 0;
			int tempY = 0;

			for (int i = 0; i < checkpoints.size(); i++)
			{
				if (checkpoints[i]->m_position.x> tempX && checkpoints[i]->m_position.x < m_player.m_position.x && checkpoints[i]->checkpoint == true)
				{
					tempX = checkpoints[i]->m_position.x;
					tempY = checkpoints[i]->m_position.y;
				}
			}

			m_player.trapCollided = false;
			m_player.respawn(tempX, tempY);
			follow.setCenter(tempX, tempY);
			m_Enemy.respawn();



		}

	}
	else
	{
		m_gameOver = false;
	}
}

void Level2::updateScroll()
{
	if (m_player.m_position.x >= 600 && follow.getCenter().x < 1475 + 1392)
	{
		follow.move(8, 0);

	}
	else if (follow.getCenter().x >= 1475 + 1392 && follow.getCenter().x < 1475 + (1392 * 2))
	{
		follow.move(8.7, 0);



	}
	else if (follow.getCenter().x >= 1475 + (1392 * 2) && follow.getCenter().x < 1475 + (1392 * 3))
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
		follow.move(17, 0);

	}


}

void Level2::update(sf::Time t)
{
	//updateScroll();
	m_cumulativeTime += t;
	offScreenDetection();
	updateShader = m_cumulativeTime.asSeconds();
	for (int i = 0; i < checkpoints.size(); i++)
	{
		checkpoints[i]->update(t, m_player);
	}
	for (int i = 0; i < gems.size(); i++)
	{
		gems[i]->update(t, m_player);
	}
	m_snowShader.setParameter("time", updateShader);

	if (m_gameOver == false)
	{


		m_player.update(t, follow.getCenter().x, follow.getCenter().y);
		//m_Enemy.update(t);
		
		TrapCollision();;



		if (m_player.m_position.x < 1470 && m_player.m_position.x > 960)
	{
			follow.setCenter(m_player.m_position.x, m_player.m_position.y);
		}

		else if (m_player.m_position.x > 1470 && follow.getCenter().x < 13040)
		{
			m_Enemy.m_velocity.x = 6;
			if (m_player.m_position.x >= m_Enemy.m_position.x)
			{
				follow.setCenter(m_player.m_position.x, m_player.m_position.y);
			}
		
		}

		follow.setCenter(m_player.m_position.x, m_player.m_position.y);
	
			follow.setCenter(follow.getCenter().x, m_player.m_position.y);
			updateScroll();
			m_GOsprite.setPosition(follow.getCenter().x - (1920 / 2), follow.getCenter().y - (1080 / 2));

		_score = static_cast<int> (((14000 - m_player.distToGoal) - (m_cumulativeTime.asSeconds() * 50) * m_player.m_heartscore));
		m_s_score.str("");
		m_s_score << _score;
		scoreHUD.setString("Score: " + m_s_score.str());
		scoreHUD.setPosition(follow.getCenter().x - 200, follow.getCenter().y - 500);

		m_player.m_health.healthSprite.setPosition(follow.getCenter().x - 800, follow.getCenter().y - 500);

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

	m_gemHUDSprite.setPosition(follow.getCenter().x + 600, follow.getCenter().y - 500);

}
void Level2::getHighscore()
{
	std::ifstream readFile;
	readFile.open("./resources/HighScore2.txt");
	yourScore.setString(m_s_score.str() + " m");

	std::string Name;
	int score;
	//Read in the file and assign it to a map using the score as the key
	if (readFile.is_open())
	{
		while (readFile >> Name >> score)
		{
			m_highscoreTable[score] = std::string(Name);
		}
	}
	readFile.close();

	if (gettable == true)
	{
		std::cout << "PLEASE ENTER YOUR NAME" << std::endl;
		std::cin >> inputName;

		//GO through the string and remove blank space
		std::string::iterator end_pos = std::remove(inputName.begin(), inputName.end(), ' ');
		inputName.erase(end_pos, inputName.end());

		m_highscoreTable[_score] = std::string(inputName);
		gettable = false;
	}


	std::ofstream writeFile2("./resources/HighScore2.txt");

	// write back to the file with the new score
	if (writeFile2.is_open())
	{
		for (auto const& x : m_highscoreTable)
		{
			writeFile2 << x.second << " " << x.first << "\n";

		}

	}
	writeFile2.close();

}
// method to reset level and stats when called
void Level2::reset()
{

	m_player.m_position.x = 500;
	m_player.m_position.y = 800;

	follow.setCenter(960, 500);

	m_player.goalreached = false;
	for (int i = 0; i < checkpoints.size(); i++)
	{
		checkpoints[i]->checkpoint = false;
	}
	m_gameOver = false;
	gettable = true;
	m_player.m_health.m_healthValue = 6;
}

void Level2::render(sf::RenderWindow &window)
{

	window.clear(sf::Color(208, 244, 247));
	window.setView(follow);
	window.draw(m_player.distance);
	window.draw(m_BGsprite);
	m_tileMap.render(window);
	for (int i = 0; i < checkpoints.size(); i++)
	{
		checkpoints[i]->render(window);
	}
	for (int i = 0; i < gems.size(); i++)
	{
		gems[i]->render(window);


	}
	m_player.render(window);
	m_Enemy.render(window);
	gemText.setPosition(follow.getCenter().x + 700, follow.getCenter().y - 500);
	window.draw(m_gemHUDSprite);
	gemText.setString(std::to_string(m_player.gemCount) + " / " + std::to_string(gems.size()));
	window.draw(gemText);
	window.draw(scoreHUD);



	if (m_gameOver == true)
	{

		window.draw(m_GOsprite);
		m_TableSprite.setPosition(follow.getCenter().x - 530, follow.getCenter().y - 390);
		window.draw(m_TableSprite);
		tableScore.setPosition(follow.getCenter().x + 350, follow.getCenter().y);
		window.draw(tableScore);
		tableName.setPosition(follow.getCenter().x, follow.getCenter().y);
		window.draw(tableName);
	}

	if (m_player.goalreached == true)
	{
		m_gameOver = true;
		getHighscore();

		int temp = 0;
		//Reverse iterate through the map to get values in decending order
		for (auto iter = m_highscoreTable.rbegin(); iter != m_highscoreTable.rend(); ++iter)
		{
			temp++;
			//only display top 7 results
			if (temp <= 7)
			{
				nameTable.setString(iter->second);
				nameTable.setPosition(follow.getCenter().x - 350, (follow.getCenter().y - 540) + (100 * temp) + 180);
				scoreTable.setString(std::to_string(iter->first));
				scoreTable.setPosition(follow.getCenter().x + 200, (follow.getCenter().y - 540) + (100 * temp) + 180);

				window.draw(scoreTable);
				window.draw(nameTable);
			}
			//to find what positon you are in all entries even outside top 7
			//if player finished outside top 7 they can see where they finished
			if (iter->second == inputName)
			{
				placement.setString("You placed " + std::to_string(temp) + "/" + std::to_string(m_highscoreTable.size()));
			}


		}
		placement.setPosition(follow.getCenter().x - 250, follow.getCenter().y - 450);
		window.draw(placement);
		Reset.setPosition(follow.getCenter().x - 500, follow.getCenter().y + 450);
		Reset.setString("Press 'R' to replay or 'Space' to continue");
		window.draw(Reset);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{

			reset();
		}
		
	
	}

	if (m_player.m_health.m_healthValue == 0)
	{

		m_gameOver = true;
		placement.setPosition(follow.getCenter().x - 250, follow.getCenter().y - 450);
		window.draw(placement);
		window.draw(Reset);
		Reset.setPosition(follow.getCenter().x - 300, follow.getCenter().y + 450);
		Reset.setString("Press 'R' to replay");
		getHighscore();
		int temp = 0;
		//Reverse iterate through the map to get values in decending order
		for (auto iter = m_highscoreTable.rbegin(); iter != m_highscoreTable.rend(); ++iter)
		{
			temp++;
			if (temp <= 7)
			{
				nameTable.setString(iter->second);
				nameTable.setPosition(follow.getCenter().x - 350, (follow.getCenter().y - 540) + (100 * temp) + 180);
				scoreTable.setString(std::to_string(iter->first));
				scoreTable.setPosition(follow.getCenter().x + 200, (follow.getCenter().y - 540) + (100 * temp) + 180);

				window.draw(scoreTable);
				window.draw(nameTable);
			}
			if (iter->second == inputName)
			{
				placement.setString("You placed " + std::to_string(temp) + "/" + std::to_string(m_highscoreTable.size()));
			}


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{

			reset();

		}
	}

	window.draw(m_BGsprite, &m_snowShader);

}