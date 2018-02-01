#include "torch.h"

Torch::Torch(float x, float y) :
	m_position(x, y)
{
	if (!torchTxt.loadFromFile("./resources/images/torch.png"))
	{
		std::string s("error loading torch texture from file");
		throw std::exception(s.c_str());
	}

	torchSprite.setTexture(torchTxt);
	torchSprite.setPosition(300, 500);

	m_shaderTexture.loadFromFile("./resources/torchTexture.png");
	m_shaderSprite.setTexture(m_shaderTexture);

	if (!torchShader.loadFromFile("./resources/torch.frag", sf::Shader::Fragment))
	{
		std::cout << "Torch shader not available" << std::endl;
	}
	m_shaderSprite.setPosition(m_position);
	torchShader.setParameter("time", 0);
	torchShader.setParameter("resolution", 1920, 1080);
}

Torch::~Torch()
{

}

void Torch::update(sf::Time t)
{
	m_cumulativeTime = t;
	updateShader = m_cumulativeTime.asSeconds();
	torchShader.setParameter("time", updateShader);
	/*if (m_player.m_position.x>= m_position.x)
	{
		checkpoint = true;
	}*/
}

void Torch::render(sf::RenderWindow &window)
{
	window.draw(torchSprite);
	if (checkpoint == true)
	{
		window.draw(m_shaderSprite, &torchShader);
	}
}