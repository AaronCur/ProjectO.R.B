#include<iostream>
#include"Help.h"

Help::Help(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font)
{
	m_font.loadFromFile("./resources/images/AGENTORANGE.TTF");

	m_R1.setFont(m_font);
	m_R1.setString("Gear Up");
	m_R1.setColor(sf::Color(0, 0, 0, 0));
	m_R1.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_R1.setCharacterSize(22);
	m_R1.setPosition(670, 180);

	m_R2.setFont(m_font);
	m_R2.setString("Accelerate");
	m_R2.setColor(sf::Color(0, 0, 0, 0));
	m_R2.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_R2.setCharacterSize(22);
	m_R2.setPosition(540, 140);

	m_L1.setFont(m_font);
	m_L1.setString("Gear down");
	m_L1.setColor(sf::Color(0, 0, 0, 0));
	m_L1.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_L1.setCharacterSize(22);
	m_L1.setPosition(160, 180);

	m_L2.setFont(m_font);
	m_L2.setString("Decelerate");
	m_L2.setColor(sf::Color(0, 0, 0, 0));
	m_L2.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_L2.setCharacterSize(22);
	m_L2.setPosition(280, 140);

	m_A.setFont(m_font);
	m_A.setString("Select");
	m_A.setColor(sf::Color(0, 0, 0, 0));
	m_A.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_A.setCharacterSize(22);
	m_A.setPosition(770, 420);

	m_X.setFont(m_font);
	m_X.setString("Shoot");
	m_X.setColor(sf::Color(0, 0, 0, 0));
	m_X.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_X.setCharacterSize(22);
	m_X.setPosition(770, 375);

	m_Y.setFont(m_font);
	m_Y.setString("Boost");
	m_Y.setColor(sf::Color(0, 0, 0, 0));
	m_Y.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_Y.setCharacterSize(22);
	m_Y.setPosition(700, 250);

	m_B.setFont(m_font);
	m_B.setString("Return");
	m_B.setColor(sf::Color(0, 0, 0, 0));
	m_B.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_B.setCharacterSize(22);
	m_B.setPosition(740, 290);

	m_rightAnalog.setFont(m_font);
	m_rightAnalog.setString("Move");
	m_rightAnalog.setColor(sf::Color(0, 0, 0, 0));
	m_rightAnalog.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_rightAnalog.setCharacterSize(22);
	m_rightAnalog.setPosition(530, 500);

	m_leftAnalog.setFont(m_font);
	m_leftAnalog.setString("Steering");
	m_leftAnalog.setColor(sf::Color(0, 0, 0, 0));
	m_leftAnalog.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_leftAnalog.setCharacterSize(22);
	m_leftAnalog.setPosition(80, 345);

	m_dPad.setFont(m_font);
	m_dPad.setString("Navigation");
	m_dPad.setColor(sf::Color(0, 0, 0, 0));
	m_dPad.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_dPad.setCharacterSize(19);
	m_dPad.setPosition(335, 510);

	m_start.setFont(m_font);
	m_start.setString("Pause");
	m_start.setColor(sf::Color(0, 0, 0, 0));
	m_start.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_start.setCharacterSize(22);
	m_start.setPosition(505, 200);

	m_helpText.setFont(m_font);
	m_helpText.setString("Help");
	m_helpText.setColor(sf::Color::Black);
	m_helpText.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_helpText.setCharacterSize(50);
	m_helpText.setPosition(420, 79);


	if (!backgroundTexture.loadFromFile("./resources/images/Help1.png"))
	{
		std::string s("Error Loading Texture");
		throw std::exception(s.c_str());
	}

	backgroundSprite.setTexture(backgroundTexture);


}

Help::~Help()
{
	std::cout << "destructing Help" << std::endl;
}

void Help::update(sf::Time dt, Xbox360Controller&controller)
{
	m_cumulativeTime += dt;

	
	
	// Button to go back to previous menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{

		m_game->setGameState(GameState::Options);
		

	}
}

void Help::render(sf::RenderWindow & window)
{
	window.draw(backgroundSprite);
	

}