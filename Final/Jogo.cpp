#include "Jogo.h"


Jogo::Jogo()
{
	pilha.push_back(new MenuIniciar(nullptr, sf::Vector2f(1088.0f, 612.0f), sf::Vector2f(544.0f, 596.0f)));
	executar();
}


Jogo::~Jogo()
{
}

void Jogo::executar()
{
	sf::RenderWindow window(sf::VideoMode(1360, 768), "Barreto: The Game", sf::Style::Close | sf::Style::Resize /*| sf::Style::Fullscreen*/);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
	ResizeView(window, view);


	float deltaTime = 0.0f;
	int time = 0;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;

			}

		}

		pilha.top()->update( deltaTime, window, view );

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);

		pilha.top()->imprimir(window);
			
		window.display();
		
	}


}

void Jogo::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_WIDTH * aspectRatio, VIEW_HEIGHT);
}
