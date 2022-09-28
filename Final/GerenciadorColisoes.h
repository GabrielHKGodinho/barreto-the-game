#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorColisoes
{
public:
	GerenciadorColisoes(sf::RectangleShape& body);
	~GerenciadorColisoes();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(GerenciadorColisoes& other, sf::Vector2f& direction, float push=1.0f);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	

private:
	sf::RectangleShape& body;
};

