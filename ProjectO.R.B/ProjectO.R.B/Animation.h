#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imgcount, float change);
	~Animation();

	void Update(int row, float dt);


	sf::IntRect uvRect;
private:
	sf::Vector2u imgCount;
	sf::Vector2u image;

	float totalTime;
	float changeTime;
};
