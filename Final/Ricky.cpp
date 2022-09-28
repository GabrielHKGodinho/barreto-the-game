#include "Ricky.h"


Ricky::Ricky(sf::Texture* texture, sf::Vector2u imageCount, float swicthTime, float speed, float jumpHeight,sf::Vector2f position):
	Player(texture, imageCount, swicthTime, speed, jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	clock.restart();

	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);

	lifeBar.setFillColor(sf::Color::Green);
	lifeBar.setSize(sf::Vector2f(90.0f, 15.0f));
	lifeBar.setOrigin(lifeBar.getSize() / 2.0f);
	lifeBar.setPosition(GetPosition().x, GetPosition().y - 70.0f);

	book.loadFromFile("livro.png");
}

Ricky::~Ricky()
{
}

void Ricky::Update(float deltaTime, sf::RenderWindow& window)
{
	bool isJumping = false;
	bool canFire = false;

	if (giz.getProjeteisGiz().size() < 1) {
		canFire = true;
	}

	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
	{
		canJump = false;

		isJumping = true;

		velocity.y = -sqrtf(2.0f * 1600.0f * jumpHeight);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && canFire)
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

void Ricky::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(lifeBar);
	giz.imprimir(window);
}

void Ricky::OnCollision(sf::Vector2f direction, bool inimigo)
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
