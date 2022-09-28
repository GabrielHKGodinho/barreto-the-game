#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TerraPlana.h"
#include "Loli.h"

class Inimigo: public Personagem
{
public:
	Inimigo(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Inimigo();

	virtual void Update(Player* player, float deltaTime)=0;
	virtual TerraPlana* GetTerraP() { return nullptr; }
	virtual Loli* getLoli() { return nullptr; }

protected:
	bool FaceRight;
	int sinal;
};

