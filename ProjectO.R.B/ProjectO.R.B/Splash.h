#pragma once
#ifndef SPLASH
#define SPLASH
#include <SFML\Graphics.hpp>
#include "Game.h"
/// <summary>
/// author Aaron Curry
/// time taken: 9:00 - 16:00

class Game;

class Splash
{
public:
	Splash(Game& Game, sf::Font meatLoaf, sf::Font adventure);
	~Splash();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);
	void checkButtonPress();

private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_adventure;
	sf::Font m_meatLoaf;
	sf::Text m_project;
	sf::Text m_ORB;
	sf::Text m_continue;

	sf::Shader m_shader;
	sf::Texture m_track;
	sf::Sprite m_trackSprite;
	sf::Texture m_dial;
	sf::Sprite m_dialSprite;


	sf::Texture m_blankTexture;
	sf::Sprite m_blankSprite;

	float updateShader = 0;
	int alpha;
	int alpha2;
	bool flip;
	bool m_pressed = false;

};
#endif // !Splash
