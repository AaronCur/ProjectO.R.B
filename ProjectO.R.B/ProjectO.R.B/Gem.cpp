#include "Gem.h"

Gem::Gem(float x, float y) :
	m_position(x, y - 15),
	animation(&gemTexture, sf::Vector2u(6, 1), 10.f),
	gemRect(sf::Vector2f(55.f, 55.f))
{
	if (!gemTexture.loadFromFile("resources/Gem.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	gemRect.setTexture(&gemTexture);
	gemRect.setTextureRect(animation.uvRect);
	animation = Animation(&gemTexture, sf::Vector2u(6, 1), 10.f);

}

Gem::~Gem()
{

}

void Gem::collision(Player &e)
{
	if ((m_position.x < e.m_position.x + e.playerColWidth) &&
		(m_position.x + 55 >e.m_position.x) &&
		(m_position.y + 55 > e.m_position.y) &&
		(m_position.y < e.m_position.y + e.playerColHeight) && collide == false)
	{
		collide = true;
		e.m_heartscore += 0.3;
		e.gemCount += 1;
	}
}

void Gem::update(sf::Time t, Player &e)
{
	gemRect.setTextureRect(animation.uvRect);
	gemRect.setPosition(m_position.x + 10, m_position.y - 15);
	m_cumulativeTime = t;
	animation.Update(0, 2.f);
	collision(e);
	
}

void Gem::render(sf::RenderWindow &window)
{
	if (collide == false)
	{
		window.draw(gemRect);
	}
		
}