#include "Player.h"
Player::Player() :
	m_position(500, 800),
	m_initialVelocity(1, 1),
	m_gravity(0, .07*pixelsToMetres),
	pixelsToMetres(5),
	m_maxForce(15, 30),
	m_force(12.5, -30),
	m_groundLocation(0, 1500),
	m_radius(15),
	playerRect(sf::Vector2f(100.f, 100.f)),
	animation(&playerTxt, sf::Vector2u(12,4),10.f)
	//m_tileMap(tileMap)
{
	if (!playerTxt.loadFromFile("resources/images/sprite.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	if (!Font.loadFromFile("resources/images/Adventure.otf"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	playerRect.setTexture(&playerTxt);
	playerRect.setTextureRect(animation.uvRect);
	animation = Animation(&playerTxt, sf::Vector2u(11, 4), 10.f);
	//animation.Update(3, 0.f);

	distance.setFont(Font);
	distance.setCharacterSize(36);
	distance.setColor(sf::Color::Black);
	distance.setPosition(960, 100);

	metresToGoal.setFont(Font);
	metresToGoal.setCharacterSize(36);
	metresToGoal.setColor(sf::Color::Black);
	metresToGoal.setPosition(1200, 100);

	jumpsound.openFromFile("./resources/swoosh.wav");
	item.openFromFile("./resources/Goal.wav");
	wall.openFromFile("./resources/Drop.wav");
	die.openFromFile("./resources/rocks.wav");
	
}
	Player::~Player()
{

}

void Player::update(sf::Time t, float x, float y)
{
	m_health.update(x,y);
	playerColWidth = animation.uvRect.width;
	playerColHeight = animation.uvRect.height;
	if (gravity == true)
	{
		m_velocity.y += m_gravity.y*pixelsToMetres;

	}
	if (m_velocity.y < 1)
	{
		animation.Update(2, 1.f);

	}

	
	playerRect.setTextureRect(animation.uvRect);
	playerRect.setPosition(m_position);

	 keyHandler();

	 if (goalreached == false)
	 {
		 m_position = m_position + m_velocity;
		 distToGoal = 13930 - m_position.x;
		 distance.setString("Distance to goal");
		 distString.str("");
		 distString << distToGoal;

		 metresToGoal.setString(distString.str());
	 }
	 else
	 {
		 distToGoal = 0;
		 distString.str("");
		 distString << distToGoal;
	 }
	

}
void Player::moveLeft()
{
	if (m_velocity.x < m_maxForce.x )
	{
		m_velocity.x = - m_force.x;
		if(m_velocity.y>=0&& jumped == true)
		animation.Update(1, 5.f);
		
	}
	
	
}
void Player::moveRight()
{
	if (m_velocity.x < m_maxForce.x  )
	{
		m_velocity.x = + m_force.x;
		if (m_velocity.y>=0 && jumped ==true)
			animation.Update(0, 5.f);
	
	}


}
void Player::jump()
{
	if (m_velocity.y < m_maxForce.y && jumpPress == false)
	{
		jumpsound.play();
		jumpCount++;

		if (jumpCount <= 1)
		{
			m_velocity.y = m_velocity.y - 30;
			jumpPress = true;
		}
		else if (jumpCount <= 2 && m_velocity.y >=0)
		{
			m_velocity.y = m_velocity.y - 30;
			jumpPress = true;
		}
		
		
	}

	
}

void Player::keyHandler()
{
	collision();

	if (state == 0)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			jump();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
		{
			jumpPress = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false)
		{
			m_velocity.x = 0;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

		{

			moveLeft();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveX == true)

		{
			moveRight();
			
		}
	}
	

}
void Player::collision()
{
	if (level2 == false)
	{
		for (int i = 0; i < m_tileMap.m_object_position.size(); i++)
		{
			//Top of the onject 
			if (m_position.y + animation.uvRect.height >= m_tileMap.m_object_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y
				&& m_position.x >= m_tileMap.m_object_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
			{
				if (m_velocity.y > 0)
				{
					gravity = false;
					m_velocity.y = 0;
					m_position.y = m_tileMap.m_object_position.at(i).y - animation.uvRect.height;
					jumped = false;
					jumpCount = 0;
				}

			}

			else
			{
				gravity = true;
				jumped = true;
			}


			/*if (m_position.y - m_radius <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y && m_position.y - m_radius >= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y - 40
			&& m_position.x >= m_tileMap.m_object_position.at(i).x && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
			{

			m_velocity.y = 0;



			}
			std::cout << gravity << std::endl;*/

		}
		//for (int i = 0; i < m_tileMap.m_wall_position.size(); i++)
		//{
		//	//Top of the onject 
		//	
		//	//m_position.y + animation.uvRect.height <= m_tileMap.m_wall_position.at(i).y && m_position.y >= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y
		//		//&& m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x <= m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x)
		//	if(m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x
		//		&& m_position.y + animation.uvRect.height >= m_tileMap.m_wall_position.at(i).y &&  m_position.y <= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y)
		//	{
		//		moveX = false;
		//		m_velocity.x = 0;


		//	}
		//	else
		//	{
		//		moveX = true;
		//	}
		//	
		//}

		//


		for (int i = 0; i < m_tileMap.m_wall_position.size(); i++)
		{
			//test moving right collision 
			if (m_position.x <= m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x &&
				m_position.x >= m_tileMap.m_wall_position.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap.m_wall_position.at(i).y &&
				m_position.y <= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y)
			{


				dirLeft = false;
				m_velocity.x = 0;
				wall.play();
				break;


			}
			else
			{
				dirLeft = true;


			}


			//Test moving right collision
			if (m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x + animation.uvRect.width < m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap.m_wall_position.at(i).y &&  m_position.y <= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y)
			{
				dirRight = false;
				m_velocity.x = 0;
				wall.play();
				break;


			}


			else
			{
				dirRight = true;
			}

		}

		for (int i = 0; i < m_tileMap.m_ceiling_position.size(); i++)
		{

			if (m_position.y + animation.uvRect.height * 2 >= m_tileMap.m_ceiling_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap.m_ceiling_position.at(i).y + m_tileMap.m_ceiling_WH.at(i).y
				&& m_position.x >= m_tileMap.m_ceiling_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap.m_ceiling_position.at(i).x + m_tileMap.m_ceiling_WH.at(i).x)
			{
				if (m_velocity.y < 0)
				{

					m_velocity.y = 0;
					break;

				}
			}
		}


		for (int i = 0; i < m_tileMap.m_trap_position.size(); i++)
		{
			//test moving left collision 
			if (m_position.x <= m_tileMap.m_trap_position.at(i).x + m_tileMap.m_trap_WH.at(i).x &&
				m_position.x >= m_tileMap.m_trap_position.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap.m_trap_position.at(i).y &&
				m_position.y <= m_tileMap.m_trap_position.at(i).y + m_tileMap.m_trap_WH.at(i).y)
			{
				trapCollided = true;
				break;
			}


			//Test moving right collision
			else if (m_position.x + animation.uvRect.width >= m_tileMap.m_trap_position.at(i).x &&
				m_position.x + animation.uvRect.width < m_tileMap.m_trap_position.at(i).x + m_tileMap.m_trap_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap.m_trap_position.at(i).y &&
				m_position.y <= m_tileMap.m_trap_position.at(i).y + m_tileMap.m_trap_WH.at(i).y)
			{
				trapCollided = true;
				break;
			}

			/*else if (m_position.y + animation.uvRect.height >= m_tileMap.m_trap_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap.m_trap_position.at(i).y + m_tileMap.m_trap_WH.at(i).y
			&& m_position.x >= m_tileMap.m_trap_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap.m_trap_position.at(i).x + m_tileMap.m_trap_WH.at(i).x)
			{
			if (m_velocity.y > 0)
			{
			respawn(m_tileMap.m_checkpoint_position.at(i).x, m_tileMap.m_checkpoint_position.at(i).y);
			}
			}*/

		}

		for (int i = 0; i < m_tileMap.m_goal_position.size(); i++)
		{

			if (m_position.x + animation.uvRect.width >= m_tileMap.m_goal_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap.m_goal_position.at(i).x + m_tileMap.m_goal_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap.m_goal_position.at(i).y &&  m_position.y <= m_tileMap.m_goal_position.at(i).y + m_tileMap.m_goal_WH.at(i).y)
			{
				goalreached = true;

				item.play();



			}

		}
	}
	else if (level2 == true)
	{
		for (int i = 0; i < m_tileMap2.m_object_position.size(); i++)
		{
			//Top of the onject 
			if (m_position.y + animation.uvRect.height >= m_tileMap2.m_object_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap2.m_object_position.at(i).y + m_tileMap2.m_object_WH.at(i).y
				&& m_position.x >= m_tileMap2.m_object_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap2.m_object_position.at(i).x + m_tileMap2.m_object_WH.at(i).x)
			{
				if (m_velocity.y > 0)
				{
					gravity = false;
					m_velocity.y = 0;
					m_position.y = m_tileMap2.m_object_position.at(i).y - animation.uvRect.height;
					jumped = false;
					jumpCount = 0;
				}

			}

			else
			{
				gravity = true;
				jumped = true;
			}


			/*if (m_position.y - m_radius <= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y && m_position.y - m_radius >= m_tileMap.m_object_position.at(i).y + m_tileMap.m_object_WH.at(i).y - 40
			&& m_position.x >= m_tileMap.m_object_position.at(i).x && m_position.x <= m_tileMap.m_object_position.at(i).x + m_tileMap.m_object_WH.at(i).x)
			{

			m_velocity.y = 0;



			}
			std::cout << gravity << std::endl;*/

		}
		//for (int i = 0; i < m_tileMap.m_wall_position.size(); i++)
		//{
		//	//Top of the onject 
		//	
		//	//m_position.y + animation.uvRect.height <= m_tileMap.m_wall_position.at(i).y && m_position.y >= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y
		//		//&& m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x <= m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x)
		//	if(m_position.x + animation.uvRect.width >= m_tileMap.m_wall_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap.m_wall_position.at(i).x + m_tileMap.m_wall_WH.at(i).x
		//		&& m_position.y + animation.uvRect.height >= m_tileMap.m_wall_position.at(i).y &&  m_position.y <= m_tileMap.m_wall_position.at(i).y + m_tileMap.m_wall_WH.at(i).y)
		//	{
		//		moveX = false;
		//		m_velocity.x = 0;


		//	}
		//	else
		//	{
		//		moveX = true;
		//	}
		//	
		//}

		//


		for (int i = 0; i < m_tileMap2.m_wall_position.size(); i++)
		{
			//test moving right collision 
			if (m_position.x <= m_tileMap2.m_wall_position.at(i).x + m_tileMap2.m_wall_WH.at(i).x &&
				m_position.x >= m_tileMap2.m_wall_position.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap2.m_wall_position.at(i).y &&
				m_position.y <= m_tileMap2.m_wall_position.at(i).y + m_tileMap2.m_wall_WH.at(i).y)
			{


				dirLeft = false;
				m_velocity.x = 0;
				wall.play();
				break;


			}
			else
			{
				dirLeft = true;


			}


			//Test moving right collision
			if (m_position.x + animation.uvRect.width >= m_tileMap2.m_wall_position.at(i).x && m_position.x + animation.uvRect.width < m_tileMap2.m_wall_position.at(i).x + m_tileMap2.m_wall_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap2.m_wall_position.at(i).y &&  m_position.y <= m_tileMap2.m_wall_position.at(i).y + m_tileMap2.m_wall_WH.at(i).y)
			{
				dirRight = false;
				m_velocity.x = 0;
				wall.play();
				break;


			}


			else
			{
				dirRight = true;
			}

		}

		for (int i = 0; i < m_tileMap2.m_ceiling_position.size(); i++)
		{

			if (m_position.y + animation.uvRect.height * 2 >= m_tileMap2.m_ceiling_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap2.m_ceiling_position.at(i).y + m_tileMap2.m_ceiling_WH.at(i).y
				&& m_position.x >= m_tileMap2.m_ceiling_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap2.m_ceiling_position.at(i).x + m_tileMap2.m_ceiling_WH.at(i).x)
			{
				if (m_velocity.y < 0)
				{

					m_velocity.y = 0;
					break;

				}
			}
		}


		for (int i = 0; i < m_tileMap2.m_trap_position.size(); i++)
		{
			//test moving left collision 
			if (m_position.x <= m_tileMap2.m_trap_position.at(i).x + m_tileMap2.m_trap_WH.at(i).x &&
				m_position.x >= m_tileMap2.m_trap_position.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap2.m_trap_position.at(i).y &&
				m_position.y <= m_tileMap2.m_trap_position.at(i).y + m_tileMap2.m_trap_WH.at(i).y)
			{
				trapCollided = true;
				break;
			}


			//Test moving right collision
			else if (m_position.x + animation.uvRect.width >= m_tileMap2.m_trap_position.at(i).x &&
				m_position.x + animation.uvRect.width < m_tileMap2.m_trap_position.at(i).x + m_tileMap2.m_trap_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap2.m_trap_position.at(i).y &&
				m_position.y <= m_tileMap2.m_trap_position.at(i).y + m_tileMap2.m_trap_WH.at(i).y)
			{
				trapCollided = true;
				break;
			}

			/*else if (m_position.y + animation.uvRect.height >= m_tileMap.m_trap_position.at(i).y && m_position.y + animation.uvRect.height <= m_tileMap.m_trap_position.at(i).y + m_tileMap.m_trap_WH.at(i).y
			&& m_position.x >= m_tileMap.m_trap_position.at(i).x - animation.uvRect.width && m_position.x <= m_tileMap.m_trap_position.at(i).x + m_tileMap.m_trap_WH.at(i).x)
			{
			if (m_velocity.y > 0)
			{
			respawn(m_tileMap.m_checkpoint_position.at(i).x, m_tileMap.m_checkpoint_position.at(i).y);
			}
			}*/

		}

		for (int i = 0; i < m_tileMap2.m_goal_position.size(); i++)
		{

			if (m_position.x + animation.uvRect.width >= m_tileMap2.m_goal_position.at(i).x && m_position.x + +animation.uvRect.width < m_tileMap2.m_goal_position.at(i).x + m_tileMap2.m_goal_WH.at(i).x
				&& m_position.y + animation.uvRect.height >= m_tileMap2.m_goal_position.at(i).y &&  m_position.y <= m_tileMap2.m_goal_position.at(i).y + m_tileMap2.m_goal_WH.at(i).y)
			{
				goalreached = true;

				item.play();



			}

		}
	}

	
}

void Player::respawn(float x, float y)
{
	m_health.m_healthValue-=2;
	m_position.x = x;
	m_position.y = y - 50;
	m_heartscore -= 0.2;
	die.play();

}

void Player::render(sf::RenderWindow &window)
{
	if (goalreached == false)
	{
		window.draw(playerRect);
		 
	}

	m_health.render(window);
}

