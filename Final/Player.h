#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Giz.h"
#include "ListaTexturas.h"


class Player 
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float swicthTime, float speed, float jumpHeight);
	~Player();

	virtual void Update(float deltaTime, sf::RenderWindow& window);
	virtual void Draw(sf::RenderWindow& window);
	virtual void OnCollision(sf::Vector2f direction, bool inimigo);

	virtual sf::Vector2f GetPosition() { return body.getPosition(); }
	virtual void setPosition(sf::Vector2f pos) { body.setPosition(pos); }
	virtual GerenciadorColisoes GetGerenciadorColisoes() { return static_cast<GerenciadorColisoes>(body); }
	virtual void setCanJump(const bool canJump) { this->canJump = canJump; }
	virtual Giz* GetGiz() { return &giz; }
	virtual float GetVida() { return lifeBar.getSize().x; }

protected:
	sf::RectangleShape body;
	sf::RectangleShape lifeBar;
	GerenciadorGrafico GerenciadorGrafico;
	unsigned int row;
	float speed;
	bool faceRight;
	Giz giz;
	sf::Clock clock;
	sf::Texture book;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

