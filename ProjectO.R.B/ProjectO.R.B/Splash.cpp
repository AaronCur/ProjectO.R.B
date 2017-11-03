#include "Splash.h"
#include <iostream>
/// <summary>
/// author Aaron Curry
/// time taken: 9:00 - 16:00
Splash::Splash(Game & game, sf::Font meatLoaf, sf::Font adventure) :
	m_game(&game),
	m_meatLoaf(meatLoaf), 
	m_adventure(adventure),
	m_project("project", m_adventure, 60),
	m_ORB("O.R.B", m_meatLoaf, 220),
	m_continue("Press A/Space To Continue", m_adventure, 25),
	alpha(0),
	alpha2(0),
	flip(false)

{

	m_project.setPosition(325.0f, -600.0f);
	m_project.setColor(sf::Color::Black);
	//m_madTing.setFont(m_meatLoaf);

	m_ORB.setPosition(375.0f, -100.0f);
	m_ORB.setColor(sf::Color(255, 255, 255, alpha));
	//m_racing.setFont(m_adventure);

	m_continue.setPosition(355.0f, 590.0f);
	m_continue.setColor(sf::Color::Black);


	//if (!m_track.loadFromFile("./resources/images/LicenseBg.png"))
	//{
	//	std::cout << "problem loading texture" << std::endl;
	//}

	m_blankTexture.loadFromFile("./resources/images/blank.png");
	m_blankSprite.setTexture(m_blankTexture);

	//if (!m_shader.loadFromFile("sun.txt", sf::Shader::Fragment))
	//{
	//	std::cout << "Shader is not available" << std::endl;
	//}


	m_shader.setParameter("time", 0);
	m_shader.setParameter("resolution", 1000, 650);


	m_blankSprite.setPosition(0, 0);
	m_trackSprite.setTexture(m_track);

}

Splash::~Splash()
{
	std::cout << "destructing Splash " << std::endl;
}
void Splash::checkButtonPress()
{

	if (m_cumulativeTime.asSeconds() >= 6.5)
	{
		m_game->setGameState(GameState::MainMenu);

	}

}
void Splash::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;

	updateShader = m_cumulativeTime.asSeconds();
	m_shader.setParameter("time", updateShader);

	//To get the PROJECT string to animate onto the screen and bounve

	if (m_cumulativeTime.asSeconds() < 2.5)
	{

		m_project.move(0, 5);

	}
	else if (m_cumulativeTime.asSeconds() < 2.8)
	{
		m_project.move(0, -1);

	}
	else if (m_cumulativeTime.asSeconds() < 3.15)
	{
		m_project.move(0, 1);
	}
	else if (m_cumulativeTime.asSeconds() < 3.5)
	{
		m_project.move(0, -0.2);
	}
	else if (m_cumulativeTime.asSeconds() < 3.65)
	{
		m_project.move(0, 0.2);
	}


	//To translate "Project" down the screen 
	if (m_ORB.getPosition().y < 90)
	{
		m_ORB.move(0, 5);
	}

	//After 3 seconds fade in the text "ORB" by incrementing its alpha value
	if (m_cumulativeTime.asSeconds() > 3 && alpha < 255)
	{
		alpha++;
		m_ORB.setColor(sf::Color(0, 0, 0, alpha));

	}
	//To get the Press A to continue text to appear after 6 seconds
	//Flip bool is used to alternate between fading in and fading out when the alpha value reaches 0 or 255
	if (m_cumulativeTime.asSeconds() >= 6)
	{
		if (alpha2 >= 254)
		{
			flip = true;
		}
		else if (alpha2 <= 1)
		{
			flip = false;
		}

		if (flip == false)
		{
			alpha2 += 2;
			m_continue.setColor(sf::Color(127, 127, 127, alpha2));
		}
		else if (flip == true)
		{
			alpha2 -= 2;
			m_continue.setColor(sf::Color(127, 127, 127, alpha2));
		}
	}


}

void Splash::render(sf::RenderWindow & window)
{

	//window.draw(m_blankSprite, &m_shader);
	window.draw(m_trackSprite);
	window.draw(m_project);
	window.draw(m_ORB);
	//Only draw after 6 seconds
	if (m_cumulativeTime.asSeconds() >= 6)
	{
		window.draw(m_continue);
	}

}
