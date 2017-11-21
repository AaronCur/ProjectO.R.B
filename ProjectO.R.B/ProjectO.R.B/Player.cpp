#include "Player.h"

Player::Player() :
	m_position(900, 0),
	m_initialVelocity(1, 1),
	m_gravity(0,.07*pixelsToMetres),
	pixelsToMetres(7),
	m_maxForce(15, 30),
	m_force(15,-30),
	m_groundLocation(0, 1500),
	m_radius(30)
{

}
	Player::~Player()
{

}

void Player::update(sf::Time t)
{
	
	 if (m_position.y < m_groundLocation.y - 10)
	 {
		 m_velocity.y += m_gravity.y*pixelsToMetres;

	 }
	 else
	 {
		 m_velocity.y = 0;
		 m_position.y = m_groundLocation.y;

	 }
	

	 keyHandler();

	 m_position = m_position + m_velocity;

}
void Player::moveLeft()
{
	if (m_velocity.x < m_maxForce.x)
	{
		m_velocity.x = - m_force.x;
	}
	
	
}
void Player::moveRight()
{
	if (m_velocity.x < m_maxForce.x)
	{
		m_velocity.x = + m_force.x;
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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false)
	{
		m_velocity.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		
	
		moveLeft();
		
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
	}

	



}

void Player::render(sf::RenderWindow &window)
{
	sf::CircleShape player(m_radius);
	player.setFillColor(sf::Color::Green);
	player.setPosition(m_position);
	window.draw(player);
}

