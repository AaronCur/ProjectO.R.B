#include "Player.h"

Player::Player() :
	m_position(500, 0),
	m_initialVelocity(1, 1),
	m_gravity(0,.098*pixelsToMetres),
	pixelsToMetres(10),
	playerRect(sf::Vector2f(100.0f,100.0f)),
	animation(&playerTxt, sf::Vector2u(7, 4), 0.3f)
{

	if (!playerTxt.loadFromFile("resources/images/sprite.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	
	playerRect.setTexture(&playerTxt);
	playerRect.setTextureRect(animation.uvRect);
	animation = Animation(&playerTxt, sf::Vector2u(7, 4), 0.3f);

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
			animation.Update(1, t);
			playerRect.setRotation(180);
		}
		
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_position.x<1000)
		{
			applyForce(sf::Vector2f(5, 0));
			m_position.x = m_position.x + m_velocity.x;
			animation.Update(1, t);
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

	 playerRect.setTextureRect(animation.uvRect);
	 playerRect.setPosition(m_position);
	 
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
	
	window.draw(playerRect);
}