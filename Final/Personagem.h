#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class Personagem : public Entidade
{
public:
	Personagem(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push = 1.0f);
	~Personagem();

	virtual void Update(Player* player, float deltaTime) = 0;
	void setLife(int h) { life = h; }
	int getLife() { return life; }

protected:
	sf::Clock clock;
	int life;
};

