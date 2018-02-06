#include "torch.h"

Torch::Torch(float x, float y) :
	m_position(x , y-15),
	animation(&torchTxt, sf::Vector2u(2,1), 10.f),
	torchRect(sf::Vector2f(50.f,50.f))
{
	if (!torchTxt.loadFromFile("resources/images/TorchFlame.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}

	torchRect.setTexture(&torchTxt);
	torchRect.setTextureRect(animation.uvRect);
	animation = Animation(&torchTxt, sf::Vector2u(2,1), 10.f);

}

Torch::~Torch()
{
	
}

void Torch::collision(Player &e)
{
	if ((m_position.x < e.m_position.x + e.playerRect.getSize().x) &&
		(m_position.x + m_tilemap.m_checkpoint_WH.data()->x) &&
		(m_position.y + m_tilemap.m_checkpoint_WH.data()->y > e.m_position.y) &&
		(m_position.y < e.m_position.y + e.playerRect.getSize().y))
	{
		checkpoint = true;
	}
}

void Torch::update(sf::Time t, Player &e)
{
	torchRect.setTextureRect(animation.uvRect);
	torchRect.setPosition(m_position.x, m_position.y-15);
	m_cumulativeTime = t;
	collision(e);
	if (checkpoint ==true)
	{
		animation.Update(0, 1.f);
	}
}

void Torch::render(sf::RenderWindow &window)
{	
	if (checkpoint == true)
	{
	window.draw(torchRect);
	}
}