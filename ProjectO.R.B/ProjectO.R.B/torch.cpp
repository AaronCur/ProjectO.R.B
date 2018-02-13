#include "torch.h"

Torch::Torch(float x, float y) :
	m_position(x, y-15),
	animation(&torchLit, sf::Vector2u(2,1), 10.f),
	torchRect(sf::Vector2f(50.f,50.f))
{
	if (!torchLit.loadFromFile("resources/images/TorchFlame.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	if (!torchUnlit.loadFromFile("resources/images/torch.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	torchRect.setTexture(&torchLit);
	torchRect.setTextureRect(animation.uvRect);
	animation = Animation(&torchLit, sf::Vector2u(2,1), 10.f);
	torchHolder.setTexture(torchUnlit);
	torchHolder.setPosition(m_position);

}

Torch::~Torch()
{
	
}

void Torch::collision(Player &e)
{
	if ((m_position.x < e.m_position.x + e.playerColWidth) &&
		(m_position.x + 10 >e.m_position.x) &&
		(m_position.y +100 > e.m_position.y) &&
		(m_position.y < e.m_position.y + e.playerColHeight))
	{
		checkpoint = true;
	}
}

void Torch::update(sf::Time t, Player &e)
{
	torchRect.setTextureRect(animation.uvRect);
	torchRect.setPosition(m_position.x+10, m_position.y-15);
	m_cumulativeTime = t;
	collision(e);
	if (checkpoint ==true)
	{
		torchSprite.setTexture(torchLit);
		animation.Update(0, 1.f);
	}
}

void Torch::render(sf::RenderWindow &window)
{
	window.draw(torchHolder);

	if(checkpoint==true)
	window.draw(torchRect);
}