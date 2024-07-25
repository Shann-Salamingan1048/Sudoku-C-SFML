#include "..\Headers\GamePanel.hpp"
void GamePanel::initWindow()
{
	//this->videoMode = sf::VideoMode::getDesktopMode(); // sa final na ini IMPORTANT!
	this->videoMode.height = 1200;
	this->videoMode.width = 1700;
	this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "Sudoku", sf::Style::Close | sf::Style::Titlebar); // smart ptr
	this->window->setFramerateLimit(60);


	this->ui = std::make_unique<UI>();
}

GamePanel::GamePanel()
{
	this->initWindow();

}
void GamePanel::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}
void GamePanel::pollEvents()
{
	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ui)
			{
				this->ui->tempNum1 = this->ui->pollEvents(event);

			}
			// Delete the current ui and create a new one
			//this->ui.reset(); // delete forcefully
			break;
		default:
			break;
		}
	}
}
const bool GamePanel::isRunning() const
{
	return this->window->isOpen();
}

void GamePanel::update()
{
	this->updateMousePos();
	this->pollEvents();
	if (this->ui)
		this->ui->updateNumbers(this->mousePosView);
}

void GamePanel::render()
{
	this->window->clear();
	this->update();
	if (this->ui)
	{
		this->ui->printGrid(*this->window);
		this->ui->printNumbers(*this->window);
	}
	this->window->display();
}