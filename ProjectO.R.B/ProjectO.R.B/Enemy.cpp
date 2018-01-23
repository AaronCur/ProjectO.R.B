#include "Enemy.h"
Enemy::Enemy() :
	m_position(500, 800),
	m_velocity(1, 0),
	m_maxForce(15, 3),
	m_force(6, -30),
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

void Enemy::update(sf::Time t)
{


	if (m_velocity.x < m_maxForce.x)
	{
		m_velocity.x = +m_force.x;
		if (m_velocity.y >= 0)
			animation.Update(0, 5.f);
	}

	enemyRect.setTextureRect(animation.uvRect);
	enemyRect.setPosition(m_position);



	if (goalreached == false)
	{
		m_position = m_position + m_velocity;
		distToGoal = 13930 - m_position.x;
	}
}

//void Player::collision()
//{
//
//	for (int i = 0; i < m_tileMap.m_object_position.size(); i++)
//	{
//		//Top of the onject 
//		if (m_position.y + animation.uvRect.height >= m_tileMap.m_object_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y
//			&& m_position.x >= m_tileMap.m_object_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
//		{
//			if (m_velocity.y > 0)
//			{
//				gravity = false;
//				m_velocity.y = 0;
//				m_position.y = m_tileMap.m_object_position.at(i).y - animation.uvRect.height;
//				jumped = false;
//			}
//
//
//
//		}
//		else
//		{
//			gravity = true;
//			jumped = true;
//		}
//		/*if (m_position.y - m_radius <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y && m_position.y - m_radius >= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y - 40
//		&& m_position.x >= m_tileMap.m_object_position.at(i).x && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
//		{
//
//		m_velocity.y = 0;
//
//
//
//		}
//		std::cout << gravity << std::endl;*/
//
//	}
//	for (int i = 0; i < m_tileMap.m_wall_position.size(); i++)
//	{
//		//Top of the onject 
//
//		//m_position.y + animation.uvRect.height <= m_tileMap.m_wall_position.at(i).y && m_position.y >= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y
//		//&& m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x <= m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x)
//		if (m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x
//			&& m_position.y + animation.uvRect.height >= m_tileMap.m_wall_position.at(i).y &&  m_position.y <= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y)
//		{
//			moveX = false;
//			m_velocity.x = 0;
//
//		}
//		else
//		{
//			moveX = true;
//		}
//
//	}
//
//	for (int i = 0; i < m_tileMap.m_goal_position.size(); i++)
//	{
//
//		if (m_position.x + animation.uvRect.width >= m_tileMap.m_goal_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap.m_goal_position.at(i).x + m_tileMap.m_goal_WH.at(i).x
//			&& m_position.y + animation.uvRect.height >= m_tileMap.m_goal_position.at(i).y &&  m_position.y <= m_tileMap.m_goal_position.at(i).y + m_tileMap.m_goal_WH.at(i).y)
//		{
//			goalreached = true;
//
//		}
//	}
//}

void Enemy::render(sf::RenderWindow &window)
{
	if (goalreached == false)
	{
		window.draw(enemyRect);

	}

}


