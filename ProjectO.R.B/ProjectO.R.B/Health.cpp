#include "Health.h"
Health::Health() :
	m_position(700, 550),
	m_healthValue(6.0f)
{
	if (!health3_0Txt.loadFromFile("resources/images/health3_0.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health2_5Txt.loadFromFile("resources/images/health2_5.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health2_0Txt.loadFromFile("resources/images/health2_0.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health1_5Txt.loadFromFile("resources/images/health1_5.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health1_0Txt.loadFromFile("resources/images/health1_0.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health0_5Txt.loadFromFile("resources/images/health0_5.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	if (!health0_0Txt.loadFromFile("resources/images/health0_0.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}


	healthSprite.setTexture(health3_0Txt);
	healthSprite.setPosition(m_position);


}

Health::~Health()
{

}
void Health::update(float x, float y)
{

	switch (m_healthValue)
	{
	case 6:
		healthSprite.setTexture(health3_0Txt);
		break;
	case 5:
		healthSprite.setTexture(health2_5Txt);
		break;
	case 4:
		healthSprite.setTexture(health2_0Txt);
		break;
	case 3:
		healthSprite.setTexture(health1_5Txt);
		break;
	case 2:
		healthSprite.setTexture(health1_0Txt);
		break;
	case 1:
		healthSprite.setTexture(health0_5Txt);
		break;
	case 0:
		healthSprite.setTexture(health0_0Txt);
		break;
	default:
		break;
	}


}



void Health::render(sf::RenderWindow &window)
{
	
	window.draw(healthSprite);

}


