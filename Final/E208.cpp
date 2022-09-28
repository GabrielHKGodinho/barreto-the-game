#include "E208.h"

E208::E208() :
	Fase()
{
	bg = new Entidade(texturas.getTextura(8), sf::Vector2f(1088.0f, 1088.0f), sf::Vector2f(544.0f, 544.0f));

	gerarFase(0);


}

E208::E208(sf::View& view,bool p2):
	Fase()
{
	view.setCenter(sf::Vector2f(544.0f, 596.0f));

	bg = new Entidade(texturas.getTextura(8), sf::Vector2f(1088.0f, 1088.0f), sf::Vector2f(544.0f, 544.0f));

	player2 = p2;

	gerarFase(0);
}


E208::~E208()
{
}

void E208::gerarFase(int enemies)
{
	players.inserir(new Player(texturas.getTextura(6), sf::Vector2u(8, 3), 0.1f, 400.0f, 400.0f));

	if(player2)
		players.inserir(new Ricky(texturas.getTextura(13), sf::Vector2u(8, 3), 0.1f, 400.0f, 400.0f, getPlayer(0)->GetPosition()));

	fase1.inserir(new Blackboard(texturas.getTextura(0), sf::Vector2f(600.0f, 7.0f), sf::Vector2f(-100.0f, 700.0f)));
	fase1.inserir(new Blackboard(texturas.getTextura(0), sf::Vector2f(600.0f, 7.0f), sf::Vector2f(-100.0f, 350.0f)));
	fase1.inserir(new Blackboard(texturas.getTextura(0), sf::Vector2f(600.0f, 7.0f), sf::Vector2f(1188.0f, 700.0f)));
	fase1.inserir(new Blackboard(texturas.getTextura(0), sf::Vector2f(600.0f, 7.0f), sf::Vector2f(1188.0f, 350.0f)));

	fase1.inserir(new Blackboard(texturas.getTextura(2), sf::Vector2f(400.0f, 8.0f), sf::Vector2f(550.0f, 680.0f)));

	fase1.inserir(new Limites(nullptr, sf::Vector2f(2000.0f, 1000.0f), sf::Vector2f(600.0f, 1500.0f)));//chao
	fase1.inserir(new Limites(nullptr, sf::Vector2f(10.0f, 10000.0f), sf::Vector2f(-405.0f, 1500.0f)));//parede esquerda
	fase1.inserir(new Limites(nullptr, sf::Vector2f(10.0f, 10000.0f), sf::Vector2f(1593.0f, 1500.0f)));//parede direita

	inimigos.inserir(new Rauli(texturas.getTextura(12), sf::Vector2f(100.0f, 200.0f), sf::Vector2f(0.0f,0.0f)));
}

void E208::atualizar(float deltaTime)
{
		for (Inimigo* inimigo : getInimigos())
			inimigo->Update(getPlayer(0), deltaTime);


}

void E208::ColisaoInimigo()
{
	for (Inimigo* inimigo : getInimigos())
		for (int i = 0; i < getLista().getTamanho(); i++) {
			GerenciadorColisoes aux = inimigo->GetGerenciadorColisoes();
			if (getLista().getElemento(i)->GetGerenciadorColisoes().CheckCollision(aux, direction, 1.0f))
				inimigo->OnCollision(direction);
		}

	for (int j = 15; j < getLista().getTamanho(); j++) {
		getLista().getElemento(j)->setVelocity(sf::Vector2f(getLista().getElemento(j)->getVelocity().x, getLista().getElemento(j)->getVelocity().y + 100.0f));
		for (int i = 0; i < getLista().getTamanho(); i++) {
			GerenciadorColisoes aux = getLista().getElemento(j)->GetGerenciadorColisoes();
			if (i != j) {
				getLista().getElemento(i)->GetGerenciadorColisoes().CheckCollision(aux, direction, 1.0f);
				getLista().getElemento(i)->OnCollision(direction);
			}
		}
		getLista().getElemento(j)->getBody()->move(getLista().getElemento(j)->getVelocity() * 0.01f);
	}
}

void E208::update(float deltaTime, sf::RenderWindow & window, sf::View & view)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		Ppilha->push_back(new MenuPause(nullptr, sf::Vector2f(1088.0f, 612.0f), sf::Vector2f(544.0f, 596.0f), &view, sf::Vector2f(544.0f, 596.0f)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !player2)
	{
		player2 = true;
		players.inserir(new Ricky(texturas.getTextura(13), sf::Vector2u(8, 3), 0.1f, 400.0f, 400.0f, getPlayer(0)->GetPosition()));
	}

	for (Player* pls : getPlayers())
		pls->Update(deltaTime, window);
	atualizar(deltaTime);


	sf::Vector2f direction;

	for (Player* pls : getPlayers())
		pls->setCanJump(false);


	for (Player* pls : getPlayers()) {
		GerenciadorColisoes angry = pls->GetGerenciadorColisoes();
		for (int i = 0; i < getLista().getTamanho(); i++)
			if (getLista().getElemento(i)->GetGerenciadorColisoes().CheckCollision(angry, direction, getLista().getElemento(i)->push))
				pls->OnCollision(direction, false);
	}


	for (Player* pls : getPlayers()) {
		GerenciadorColisoes angry = pls->GetGerenciadorColisoes();
		for (Inimigo* inimigo : getInimigos())
			if (inimigo->GetGerenciadorColisoes().CheckCollision(angry, direction, inimigo->push))
				pls->OnCollision(direction, true);
	}

	for (Inimigo* inimigo : getInimigos()) {
		Loli* loli = inimigo->getLoli();
		if (loli != nullptr) {
			std::vector<Loli*> loliVect = loli->getProjeteisLoli();


			for (int i = 0; i < loliVect.size(); i++)
				for (Player* pls : getPlayers())
				{
					GerenciadorColisoes terra = loliVect[i]->GetGerenciadorColisoes();
					if (pls->GetGerenciadorColisoes().CheckCollision(terra, direction, inimigo->push))
					{
						loli->OnCollison();
						pls->OnCollision(direction, true);
						break;
					}
				}
		}

	}

	for (Player* pls : getPlayers()) {
		Giz* proj = pls->GetGiz();
		std::vector<Giz*> projVect = proj->getProjeteisGiz();
		for (int i = 0; i < projVect.size(); i++)
			for (int j = 0; j < getLista().getTamanho(); j++)
			{
				GerenciadorColisoes giz = projVect[i]->GetGerenciadorColisoes();
				if (getLista().getElemento(j)->GetGerenciadorColisoes().CheckCollision(giz, direction, getLista().getElemento(j)->push))
				{
					proj->OnCollison();
					break;
				}
			}

		for (int i = 0; i < projVect.size(); i++) {
			int pos = 0;
			for (Inimigo* inimigo : getInimigos())
			{
				GerenciadorColisoes giz = projVect[i]->GetGerenciadorColisoes();
				if (inimigo->GetGerenciadorColisoes().CheckCollision(giz, direction, inimigo->push))
				{
					proj->OnCollison();
					inimigo->setLife(inimigo->getLife() - 1);

					if (inimigo->getLife() < 1) {
						inimigos.deletar(pos);
						Ppilha->substituir(new MenuVitoria(nullptr, sf::Vector2f(1088.0f, 612.0f), sf::Vector2f(544.0f, 596.0f), &view));
					}
					break;
				}
				pos++;
			}
		}

		limitePlayer(pls);
	}


	for (Player* pls : getPlayers())
		if (pls->GetVida() <= 0)
			Ppilha->pop();
}

void E208::limitePlayer(Player * player)
{
	if (player->GetPosition().x < 0.0f)
		player->setPosition(sf::Vector2f(0.0f, player->GetPosition().y));

	if (player->GetPosition().x > 1088.0f)
		player->setPosition(sf::Vector2f(1088.0f, player->GetPosition().y));
}
