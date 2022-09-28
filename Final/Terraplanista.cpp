#include "Terraplanista.h"
#include <iostream>


Terraplanista::Terraplanista(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Inimigo(texture, size, position),
	GerenciadorGrafico(texture, sf::Vector2u(9, 1), 0.1f)
{
	velocity = sf::Vector2f(100.0f, 0.0f);
	sinal = 1;
	life = 1;

	terra.loadFromFile("images/terrap.png");
}


Terraplanista::~Terraplanista()
{
}

void Terraplanista::Update(Player* player, float deltaTime)
{
	velocity.y += 5.0f;
	velocity.x = 100.0f * sinal;
	bool canFire = false;

	if (terraP.getProjeteisTerra().size() < 1)
		canFire = true;

	if ((int)clock.getElapsedTime().asSeconds() == 5) {
		sinal *= -1;
		velocity.x *= -1;
		clock.restart();
	}
	if ((int)clock.getElapsedTime().asMilliseconds() == 1000 || clock.getElapsedTime().asMilliseconds() == 4000 && canFire) {

		terraP.inserir(new TerraPlana(&terra, sf::Vector2f(50.0f, 50.0f), GetPosition()));
		if (FaceRight)
			terraP.setVelocidade(sf::Vector2f(250.0f, 0.0f));
		else
			terraP.setVelocidade(sf::Vector2f(-250.0f, 0.0f));
	}

	if (sinal > 0)
		FaceRight = 1;
	else
		FaceRight = 0;

	GerenciadorGrafico.Update(0, deltaTime, FaceRight);
	body.setTextureRect(GerenciadorGrafico.uvRect);
	body.move(velocity * deltaTime);

	terraP.atirando(deltaTime);

}

void Terraplanista::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	terraP.imprimir(window);
}
