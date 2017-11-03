#pragma once
#ifndef LICENSE
#define LICENSE	
#include <SFML\Graphics.hpp>
#include "Game.h"
//#include "Xbox360Controller.h"

class Game;

class License
{
public:
	License(Game& game, sf::Font font);
	~License();
	//Xbox360Controller controller;
	//void changeScreen();//changes the sprite on screen 
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);
	void anyKeyPress();
	void initialise(sf::Font font);

private:
	Game *m_game;//pointer to games class 
	sf::Time m_cumulativeTime;//the time 
	sf::Sprite m_globeSprite;//first sprite
	sf::Texture m_globeTexture;//first texture 
	sf::Text m_globeText;
	sf::Text m_globeTextTwo;
	sf::Text m_presentText;
	sf::Font m_font;

	sf::Shader m_shader;
	float updateShader = 0;
	sf::Texture m_blankTexture;
	sf::Sprite m_blankSprite;
};
#endif // !License
