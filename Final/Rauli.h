#pragma once
#include "Inimigo.h"
#include "Loli.h"
#include <stdlib.h>

class Rauli: public Inimigo
{
public:
	Rauli(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Rauli();

	void Draw(sf::RenderWindow& window);
	void Update(Player* player, float deltaTime);
	void Walk(int sinal, float deltaTime);
	void Shot(sf::Vector2f player);
	int Randomizer();
	void Spawn(int r);
	Loli* getLoli() { return &loli; }

private:
	int random;
	Loli loli;
	sf::Texture lolitxt;
};

