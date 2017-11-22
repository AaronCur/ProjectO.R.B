#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imgcount, float change)
{
	this->imgCount = imgcount;
	this->changeTime = change;
	totalTime = 0.0f;
	image.x = 0;

	uvRect.width = texture->getSize().x / float(imgCount.x);
	uvRect.height = texture->getSize().y / float(imgCount.y);

}

Animation::~Animation()
{

}

void Animation::Update(int row, sf::Time dt)
{
	image.y = row;
	totalTime += dt.asMilliseconds();
	if (totalTime >= changeTime)
	{
		totalTime -= changeTime;
		image.x++;
		if (image.x >= imgCount.x)
		{
			image.x = 0;
		}
		
	}

	uvRect.left = image.x*uvRect.width;
	uvRect.top = image.y*uvRect.height;
}
