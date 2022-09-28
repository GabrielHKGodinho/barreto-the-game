#pragma once
#include "Player.h"

class Ricky : public Player
{
public:
	Ricky(sf::Texture* texture, sf::Vector2u imageCount, float swicthTime, float speed, float jumpHeight, sf::Vector2f position);
	~Ricky();

	void Update(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction, bool inimigo);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	void setPosition(sf::Vector2f pos) { body.setPosition(pos); }
	GerenciadorColisoes GetGerenciadorColisoes() { return static_cast<GerenciadorColisoes>(body); }
	void setCanJump(const bool canJump) { this->canJump = canJump; }
	Giz* GetGiz() { return &giz; }
	float GetVida() { return lifeBar.getSize().x; }
};

