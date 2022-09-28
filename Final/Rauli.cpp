#include "Rauli.h"



Rauli::Rauli(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Inimigo(texture, size, position)
{
	life = 6;
	clock.restart();
	random = Randomizer();
	Spawn(random);
	lolitxt.loadFromFile("images/loli.png");
}


Rauli::~Rauli()
{
}

void Rauli::Draw(sf::RenderWindow & window)
{
	window.draw(body);
	loli.imprimir(window);
}

void Rauli::Update(Player * player, float deltaTime)
{
	if (clock.getElapsedTime().asMilliseconds() >= 6000) {
		clock.restart();
		random = Randomizer();
		Spawn(random);
	}
	
	else {
		switch (random)
		{
		case(0):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(-1, deltaTime);
			break;

		case(1):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(-1, deltaTime);
			break;

		case(2):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(-1, deltaTime);
			break;

		case(3):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(-1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(1, deltaTime);
			break;

		case(4):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(-1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(1, deltaTime);
			break;

		case(5):
			if (clock.getElapsedTime().asMilliseconds() <= 2000)
				Walk(-1, deltaTime);

			if ((int)clock.getElapsedTime().asMilliseconds() == 3000)
				Shot(player->GetPosition());

			if (clock.getElapsedTime().asMilliseconds() >= 4000)
				Walk(1, deltaTime);
			break;

		}
	}

	loli.atirando(deltaTime, player->GetPosition() - body.getPosition());

}

void Rauli::Walk(int sinal, float deltaTime)
{
	body.move(sf::Vector2f(200.0f, 0.0f) * deltaTime * (float)sinal);
}

void Rauli::Shot(sf::Vector2f player)
{
	loli.inserir(new Loli(&lolitxt, sf::Vector2f(50.0f, 50.0f), body.getPosition()));
}

int Rauli::Randomizer()
{
	srand(time(NULL));

	return rand() % 6;
}

void Rauli::Spawn(int r)
{
	switch (random)
	{
	case(0):
		body.setPosition(sf::Vector2f(-300.0f, 900.0f));
		break;

	case(1):
		body.setPosition(sf::Vector2f(-300.0f, 600.0f));
		break;

	case(2):
		body.setPosition(sf::Vector2f(-300.0f, 250.0f));
		break;

	case(3):
		body.setPosition(sf::Vector2f(1388.0f, 900.0f));
		break;

	case(4):
		body.setPosition(sf::Vector2f(1388.0f, 600.0f));
		break;

	case(5):
		body.setPosition(sf::Vector2f(1388.0f, 250.0f));
		break;

	}
}
