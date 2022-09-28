#include "Barreto.h"


Barreto::Barreto(sf::Texture* texture, sf::Vector2u imageCount, float swicthTime, float speed, float jumpHeight):
	Player(texture, imageCount, swicthTime, speed, jumpHeight)
{
}

Barreto::~Barreto()
{
}

void Barreto::Update(float deltaTime, sf::RenderWindow& window)
{
	bool isJumping = false;
	bool canFire = false;

	if (giz.getProjeteisGiz().size() < 1) {
		canFire = true;
	}

	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;

		isJumping = true;

		velocity.y = -sqrtf(2.0f * 1600.0f * jumpHeight);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && canFire)
	{


		canFire = false;
		giz.inserir(new Giz(&book, sf::Vector2f(50.0f, 50.0f), GetPosition()));

		if (faceRight)
			giz.setVelocidade(sf::Vector2f(250.0f, -sqrtf(2.0f * 1600.0f * 200.0f)));
		else
			giz.setVelocidade(sf::Vector2f(-250.0f, -sqrtf(2.0f * 1600.0f * 200.0f)));
		clock.restart();
	}

	velocity.y += 1600.0f * deltaTime;


	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	if (canJump == false) {
		row = 2;
	}

	GerenciadorGrafico.Update(row, deltaTime, faceRight, !canJump);
	body.setTextureRect(GerenciadorGrafico.uvRect);
	body.move(velocity * deltaTime);
	lifeBar.setPosition(GetPosition().x, GetPosition().y - 75.0f);
	giz.atirando(deltaTime);
}

void Barreto::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(lifeBar);
	giz.imprimir(window);
}

void Barreto::OnCollision(sf::Vector2f direction, bool inimigo)
{
	bool canDamage = false;
	if (clock.getElapsedTime().asSeconds() >= 1 / 2.0)
		canDamage = true;

	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}

	if (inimigo && (lifeBar.getSize().x > 0) && canDamage)
	{
		lifeBar.setSize(sf::Vector2f(lifeBar.getSize().x - 30.0f, lifeBar.getSize().y));
		clock.restart();
	}
}