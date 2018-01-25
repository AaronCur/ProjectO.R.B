#include "Health.h"
Health::Health() :
	m_position(1470, 800),
	m_health(3.0f)
{
	if (!health3_0Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health2_5Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health2_0Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health1_5Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health1_0Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health0_5Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health0_0Txt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}


	healthSprite.setTexture(health3_0Txt);

}

Health::~Health()
{

}

void Health::update(sf::Time t)
{

	healthSprite.setPosition(m_position);

	switch (m_health)
	{
	case 5:
		//	m_splashScreen->print(time);
		std::cout << "no GameState" << std::endl;
		break;
	case 4:
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



void Health::render(sf::RenderWindow &window)
{
	
	window.draw(healthSprite);

}


