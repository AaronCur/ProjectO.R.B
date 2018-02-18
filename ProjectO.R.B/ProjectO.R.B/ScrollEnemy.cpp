#include "ScrollEnemy.h"

ScrollEnemy::ScrollEnemy() :
	m_position(10000,1150),
	m_velocity(0, 0),
	m_maxForce(15, 3),
	m_force(0, -30),
	enemyRect(sf::Vector2f(100.f, 100.f)),
	animation(&enemyTxt, sf::Vector2u(12, 4), 10.f)
	//m_tileMap(tileMap)
{
	if (!enemyTxt.loadFromFile("resources/images/enemy.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}


	enemyRect.setTexture(&enemyTxt);
	enemyRect.setTextureRect(animation.uvRect);
	animation = Animation(&enemyTxt, sf::Vector2u(11, 4), 10.f);
	//animation.Update(3, 0.f);

}

ScrollEnemy::~ScrollEnemy()
{

}

void ScrollEnemy::update(sf::Time t)
{

	if (m_velocity.x > 0)
	{
		animation.Update(0, 5.f);
	}
	else if (m_velocity.x < 0)
	{
		animation.Update(1, 5.f);
	}
	else
	{
		animation.Update(0, 0.f);
	}


	if (m_position.x >= 13000)
	{
		left = true;
	}
	else if(m_position.x <= 12300)
	{
		left = false;
	}
	
	if (left==true)
	{
		m_velocity.x = -8;
		m_position += m_velocity;
	}
	if(left==false )
	{
		m_velocity.x = 8;
		m_position.x += m_velocity.x;
	}

		


	enemyRect.setTextureRect(animation.uvRect);
	enemyRect.setPosition(m_position);
}



void ScrollEnemy::render(sf::RenderWindow &window)
{
	if (goalreached == false)
	{
		window.draw(enemyRect);

	}

}


