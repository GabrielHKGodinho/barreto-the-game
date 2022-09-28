#include "PatineteEletrico.h"



PatineteEletrico::PatineteEletrico(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Inimigo(texture, size, position),
	GerenciadorGrafico(texture,sf::Vector2u(8,1), 0.1f)
{
	velocity = sf::Vector2f(50.0f, 0.0f);
	sinal = 1;
	life = 1;
}


PatineteEletrico::~PatineteEletrico()
{
}

void PatineteEletrico::Update(Player* player, float deltaTime)
{
	velocity.y += 1.0f;

	if (abs(player->GetPosition().x - body.getPosition().x) > 350 || abs(player->GetPosition().x - body.getPosition().x) <= 75) {
		if ((int)clock.getElapsedTime().asSeconds() == 5) {
			sinal *= -1;
			velocity.x =50.0f * sinal;
			clock.restart();
		}

	}
	else {
		sinal = (player->GetPosition().x - body.getPosition().x) / abs(player->GetPosition().x - body.getPosition().x);
		velocity.x = 300.0f * sinal;
	}
	if (sinal > 0)
		FaceRight = 1;
	else
		FaceRight = 0;

	GerenciadorGrafico.Update(0, deltaTime, FaceRight);
	body.setTextureRect(GerenciadorGrafico.uvRect);
	body.move(velocity * deltaTime);
}
