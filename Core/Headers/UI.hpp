#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <vector>
#include "Global.hpp"
#include <iostream>
class UI final
{
private:
	sf::RectangleShape Grid;
	sf::Texture textGrid;

private:
	std::vector<std::vector<std::unique_ptr<sf::RectangleShape>>> numTileVec;


	std::vector<std::unique_ptr<sf::Texture>> numbers;

	std::vector<std::unique_ptr<sf::Texture>> numbersTick;

private:
	void initNumberTiles();
	void initGrid();
	void initTextureNumbersTick();
	void initTextureNumbers();

private:
	void initNumTilePermanentOrNot();
	void initClickedOrNot();
private:
	std::vector<std::vector<bool>> numTilePermanentOrNot;
	std::vector<std::vector<bool>> clickedOrNot;

private:
	enum btn_states { btn_idle = 0, btn_hover = 1, btn_clicked = 2 };
	unsigned short btn_state;
	bool isLeftClicked;
private:
	sf::Image imageTemp;
	sf::Color OrigColorTile;

public:
	void printBackground(sf::RenderTarget& target); // not yet implemented
	void printGrid(sf::RenderTarget& target);
	void printNumbers(sf::RenderTarget& target);

public:
	void updateNumbers(sf::Vector2f& mousePos);
	unsigned short pollEvents(sf::Event& evnt);
	unsigned short tempNum1;

public:
	explicit UI();
	~UI() = default;
};