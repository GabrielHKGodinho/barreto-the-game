#pragma once
#include "Inimigo.h"
#include <SFML/Config.hpp>
#include "Player.h"
#include "GerenciadorGrafico.h"
#include "TerraPlana.h"

class Terraplanista: public Inimigo
{
public:
	Terraplanista(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Terraplanista();

	void Update(Player* player, float deltaTime);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void Draw(sf::RenderWindow& window);
	TerraPlana* GetTerraP() { return &terraP; }

private:

	GerenciadorGrafico GerenciadorGrafico;
	TerraPlana terraP;
	sf::Texture terra;
};

