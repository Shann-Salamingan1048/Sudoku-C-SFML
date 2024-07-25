#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include "UI.hpp"
class GamePanel final
{
private:
	std::unique_ptr<sf::RenderWindow> window; // use smart pointers
	sf::Event event;
	sf::VideoMode videoMode;
	void initWindow();

	std::unique_ptr<UI> ui;
private:
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	void updateMousePos();

public:
	explicit GamePanel();
	~GamePanel() = default;
	const bool isRunning() const;
	void pollEvents();
	void update();
	void render();

};