#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#define W_WIDTH 800
#define W_HEIGHT 600

int main()
{
	float Gravity = 9.63f;
	float Momentum = 1.0f;
	sf::RenderWindow Game(sf::VideoMode(W_WIDTH, W_HEIGHT), "Basic Game");
	sf::RectangleShape Player(sf::Vector2f(15, 15));
	sf::RectangleShape Platform(sf::Vector2f(W_WIDTH, 15));
	Player.setFillColor(sf::Color::Red);
	Platform.setFillColor(sf::Color::Green);
	Game.setFramerateLimit(60);

	Player.setPosition((W_WIDTH-15)/2, (W_HEIGHT-15)/2);
	Platform.setPosition(0, W_HEIGHT - 15);

	while (Game.isOpen())
	{
		sf::Event event;
		while (Game.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Game.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				{
					Player.move(-10 * Momentum, 0);
					Momentum += 0.1f;
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
					Player.move(10 * Momentum, 0);
					Momentum += 0.1f;
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
					Player.move(0, -100.0f);
				} else {
					Momentum = 1.0f;
				}
			}
		}
		Game.clear();
		if (!Player.getGlobalBounds().intersects(Platform.getGlobalBounds()))
		{
			Player.move(0, Gravity);
		}
		Game.draw(Player);
		Game.draw(Platform);
		Game.display();
	}
}