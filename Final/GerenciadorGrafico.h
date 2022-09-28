#pragma once
#include <SFML/Graphics.hpp>

static const float VIEW_HEIGHT = 1088.0f;
static const float VIEW_WIDTH = 612.0f;

class GerenciadorGrafico
{
public:
	GerenciadorGrafico(sf::Texture* texture = nullptr, sf::Vector2u imageCount=sf::Vector2u(1,1), float swicthTime=0.0f);
	~GerenciadorGrafico();

	void Update(int row, float deltaTime, bool faceRight, bool isJumping=0);

public:
	sf::IntRect uvRect;
	sf::Texture BBTexture;
	sf::Texture playerTexture;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

