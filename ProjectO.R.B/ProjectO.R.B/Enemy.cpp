#include "Enemy.h"
Enemy::Enemy() :
	m_position(1470, 800),
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

Enemy::~Enemy()
{

}
void Enemy::respawn()
{
	m_position.x = 1470;
	m_position.y = 800;
	m_velocity.x = 0;
}
void Enemy::update(sf::Time t)
{

	  if (m_velocity.x > 0)
		{
			animation.Update(0, 5.f);
		}
	  else
	  {
		  animation.Update(0, 0.f);
	  }
			

	enemyRect.setTextureRect(animation.uvRect);
	enemyRect.setPosition(m_position);



	if (goalreached == false)
	{
		m_position = m_position + m_velocity;
		distToGoal = 13930 - m_position.x;
	}

}



void Enemy::render(sf::RenderWindow &window)
{
	if (goalreached == false)
	{
		window.draw(enemyRect);

	}

}


