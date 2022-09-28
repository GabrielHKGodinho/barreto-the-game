#include "GerenciadorGrafico.h"



GerenciadorGrafico::GerenciadorGrafico(sf::Texture* texture, sf::Vector2u imageCount, float swicthTime)
{
	this->imageCount = imageCount;
	this->switchTime = swicthTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::Update(int row, float deltaTime, bool faceRight, bool isJumping)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (isJumping)
		{
			if (currentImage.x >= imageCount.x)
				currentImage.x = imageCount.x - 1;
		}

		else if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
