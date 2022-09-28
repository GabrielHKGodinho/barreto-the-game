#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Platform.h"


class Blackboard : public Platform
{
public:
	Blackboard(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Blackboard();

	void Draw(sf::RenderWindow& window);
	//GerenciadorColisoes* GetGerenciadorColisoes() { return (GerenciadorColisoes*)&body; }
private:
	//sf::RectangleShape body;
	sf::RectangleShape board;
};

