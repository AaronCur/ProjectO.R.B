#include "Player.h"
Player::Player() :
	m_position(2000, 1000),
	m_initialVelocity(1, 1),
	m_gravity(0, .07*pixelsToMetres),
	pixelsToMetres(7),
	m_maxForce(15, 30),
	m_force(15, -30),
	m_groundLocation(0, 1500),
	m_radius(15),
	playerRect(sf::Vector2f(100.f, 100.f)),
	animation(&playerTxt, sf::Vector2u(12,4),0.3f)
	//m_tileMap(tileMap)
{
	if (!playerTxt.loadFromFile("resources/images/sprite.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	playerRect.setTexture(&playerTxt);
	playerRect.setTextureRect(animation.uvRect);
	animation = Animation(&playerTxt, sf::Vector2u(12, 4), 0.3f);
}
	Player::~Player()
{

}

void Player::update(sf::Time t)
{
	
	if (gravity == true)
	{
		m_velocity.y += m_gravity.y*pixelsToMetres;

	}


	playerRect.setTextureRect(animation.uvRect);
	playerRect.setPosition(m_position);

	 keyHandler();

	 m_position = m_position + m_velocity;

}
void Player::moveLeft()
{
	if (m_velocity.x < m_maxForce.x)
	{
		m_velocity.x = - m_force.x;
		animation.Update(1, 0.3f);
	}
	
	
}
void Player::moveRight()
{
	if (m_velocity.x < m_maxForce.x)
	{
		m_velocity.x = + m_force.x;
		animation.Update(2, 0.3f);
	}


}
void Player::jump()
{
	if (m_velocity.y == 0 && m_velocity.y < m_maxForce.y)
	{
		m_velocity.y = m_velocity.y - 40;
	}

	
}

void Player::keyHandler()
{
	collision();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false)
	{
		m_velocity.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
	{

		moveLeft();
		
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  )
	{
		moveRight();
	}

	



}
void Player::collision()
{

	for (int i = 0; i < m_tileMap.m_object_position.size(); i++)
	{	
		//Top of the onject 
		if (m_position.y + m_radius + 10 >= m_tileMap.m_object_position.at(i).y && m_position.y + m_radius + 10 <= m_tileMap.m_object_position.at(i).y + 40
		&& m_position.x >= m_tileMap.m_object_position.at(i).x && m_position.x  <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
		{
			gravity = false;
			m_velocity.y = 0;
			m_position.y = m_tileMap.m_object_position.at(i).y - m_radius - 10;
	
			
		}
		else
		{
			gravity = true;
		}
		/*if (m_position.y - m_radius <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y && m_position.y - m_radius >= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y - 40
			&& m_position.x >= m_tileMap.m_object_position.at(i).x && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
		{
			
			m_velocity.y = 0;
			


		}
		std::cout << gravity << std::endl;*/
		
	}
}

void Player::render(sf::RenderWindow &window)
{
	//window.clear();
	window.draw(playerRect);
}

