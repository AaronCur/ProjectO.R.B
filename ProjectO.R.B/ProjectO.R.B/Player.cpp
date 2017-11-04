#include "Player.h"

Player::Player() :
	m_position(500, 0),
	m_initialVelocity(1, 1),
	m_gravity(0,.098*pixelsToMetres),
	pixelsToMetres(10)
{

}
	Player::~Player()
{

}

void Player::update(sf::Time t)
{
	

	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(m_position.x>0)
		{
			applyForce(sf::Vector2f(-5, 0));
			m_position.x = m_position.x + m_velocity.x;
		}
		
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_position.x<1000)
		{
			applyForce(sf::Vector2f(5, 0));
			m_position.x = m_position.x + m_velocity.x;
		}

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)&&jumped==false)
	{
		if (m_position.y <400)
		{
			applyForce(sf::Vector2f(0, 10));
			jumped = true;
			m_position.y = m_position.y - m_velocity.y*pixelsToMetres+.5*m_gravity.y;
			std::cout << "jump" << std::endl;
		}		
	}

	 if (m_position.y < 300)
	 {
		 m_position.y += m_gravity.y*pixelsToMetres;
	 }
	 else
		 jumped = false;
}

void Player::applyForce(sf::Vector2f force)
{
	sf::Vector2f f = m_initialVelocity;
	if (m_initialVelocity.x<10 || m_initialVelocity.x>-10)
	{
		m_velocity.x = f.x+force.x;
	}
	
	if (m_initialVelocity.y < 100)
	{
		m_velocity.y = f.y + force.y;
		
	}
}

void Player::render(sf::RenderWindow &window)
{
	window.clear();
	sf::CircleShape player(30);
	player.setFillColor(sf::Color::Green);
	player.setPosition(m_position);
	window.draw(player);
}